// Поэлементное сложение векторов (несколько блоков)
#include <cuda.h>
#include <stdio.h>

__global__ void add(int *a, int *b, int *c)
{
    // вычисление индекса массивов, используем несколько
    // блоков по координате x (blockDim.x),
    // в каждом блоке – несколько нитей по координате x
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    c[index] = a[index] + b[index];
}

#define MIN_N (4096 * 4096 / 256) // Минимальный размер векторов
#define MAX_N (4096 * 4096 * 16)  // Максимальный размер векторов
#define MULTIPLY_N 2              // множитель
#define THREADS_PER_BLOCK 1024    // максимальное значение для GK110

int main(void)
{
    printf("Starostenkov A.A. VM-22 (mag.)\n");
    printf("Example 5.\n");

    cudaEvent_t start, stop;
    float gpuTime;
    size_t n; // представления размера векторов

    printf("\n-----START-----\n");

    FILE *file = fopen("5_output.txt", "w");
    if (file == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    fprintf(file, "n: gpuTime\n");


    for (n = MIN_N; n <= MAX_N; n *= MULTIPLY_N)
    {
        printf("n = %d\n", n);

        int *a, *b, *c;             // host копии a, b, c
        int *dev_a, *dev_b, *dev_c; // device копии of a, b, c
        // int size = N * sizeof(int);
        size_t size = n * sizeof(int);

        cudaEventCreate(&start);
        cudaEventCreate(&stop);

        // выделяем память на device для of a, b, c
        cudaMalloc((void **)&dev_a, size);
        cudaMalloc((void **)&dev_b, size);
        cudaMalloc((void **)&dev_c, size);
        // выделяем память на хосте
        a = (int *)malloc(size);
        b = (int *)malloc(size);
        c = (int *)malloc(size);
        // инициализация массивов
        size_t i;
        for (i = 0; i < n; ++i)
            a[i] = 10;
        for (i = 0; i < n; ++i)
            b[i] = 9;
        
        cudaEventRecord(start, 0); // отсечка
        // копируем ввод на device
        cudaMemcpy(dev_a, a, size, cudaMemcpyHostToDevice);
        cudaMemcpy(dev_b, b, size, cudaMemcpyHostToDevice);

        // запускаем на выполнение add() kernel с блоками и нитями
        add<<<n / THREADS_PER_BLOCK, THREADS_PER_BLOCK>>>(dev_a, dev_b, dev_c);
        
        // копируем результат работы device на host ( копия c )
        cudaMemcpy(c, dev_c, size, cudaMemcpyDeviceToHost);
        cudaEventRecord(stop, 0); // отсечка
        cudaEventSynchronize(stop);
        cudaEventElapsedTime(&gpuTime, start, stop);

        printf("c = [");
        for (i = 0; i < 20; ++i) printf("%d; ", c[i]);
        printf("]\n");

        printf("time spent executing by the GPU: %.2f millseconds\n", gpuTime);

        fprintf(file, "%zu: %.2f\n", n, gpuTime);

        cudaEventDestroy(start);
        cudaEventDestroy(stop);

        free(a);
        free(b);
        free(c);
        cudaFree(dev_a);
        cudaFree(dev_b);
        cudaFree(dev_c);
    }

    fclose(file);

    return 0;
}
