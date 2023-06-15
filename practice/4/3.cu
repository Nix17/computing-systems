#include <cuda.h>
#include <stdio.h>

__global__ void add(int *a, int *b, int *c) // Функция - ядро
{
    *c = *a + *b;
}

int main(void)
{
    printf("Starostenkov A.A. VM-22 (mag.)\n");
    printf("Example 3.\n");

    int a, b, c;                // host копии a, b, c
    int *dev_a, *dev_b, *dev_c; // device копии a, b, c
    int size = sizeof(int);
    // выделяем память для device копий для a, b, c
    cudaMalloc((void **)&dev_a, size);
    cudaMalloc((void **)&dev_b, size);
    cudaMalloc((void **)&dev_c, size);
    a = 10;
    b = 9;
    // копируем ввод на device
    cudaMemcpy(dev_a, &a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, &b, size, cudaMemcpyHostToDevice);
    // запускаем add() kernel на GPU, передавая параметры
    add<<<1, 1>>>(dev_a, dev_b, dev_c);
    // копируем результат с на CPU
    cudaMemcpy(&c, dev_c, size, cudaMemcpyDeviceToHost);
    // освобождаем память device
    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);
    printf("c = %5d\n", c);
    return 0;
}
