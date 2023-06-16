#include <cuda.h>
#include <stdio.h>

// Переопределяем количество итераций цикла
// #define N 1000000

// another
// #define N 100
// #define N 1000
// #define N 10000
// #define N 100000
// #define N 1000000
#define N 10000000
// Переопределяем максимальное значение для GK110
#define THREADS_PER_BLOCK 1024

// Функция - ядро
__global__ void get_el(float *dev_el)
{
    float index = threadIdx.x + blockIdx.x * blockDim.x;
    if (index <= N)
    {
        float znam = (10 * (index + 1) * (index + 1) - 2 * (index + 1) - 3);
        dev_el[(int)index] = 3.0 / znam;
    }
    else
    {
        return;
    }
}

int main(void)
{
    float gpu_calc_time, gpu_send_time;
    cudaEvent_t start, stop;

    // Создание событий
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    // Host копии
    float *el;
    // Device копии
    float *dev_el;

    // Выделение памяти для device и host элементов
    int size = N * sizeof(float);
    el = (float *)malloc(size);
    cudaMalloc((void **)&dev_el, size);

    // Отсечка
    cudaEventRecord(start, 0);
    get_el<<<(int)(N / THREADS_PER_BLOCK) + 1, THREADS_PER_BLOCK>>>(dev_el);

    // Отсечка
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&gpu_calc_time, start, stop);

    // Копирование результата в CPU
    // Отсечка
    cudaEventRecord(start, 0);
    cudaMemcpy(el, dev_el, size, cudaMemcpyDeviceToHost);
    // Отсечка
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&gpu_send_time, start, stop);

    // Освобождение памяти device
    cudaFree(dev_el);
    // Переменные времени и суммы
    float cpu_t;
    double sum = 0;

    // Вычисление суммы числового ряда
    // Отсечка
    cudaEventRecord(start, 0);
    for (float i = 0; i < N; i++)
    {
        sum += el[(int)i];
    }
    // Отсечка
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    cudaEventElapsedTime(&cpu_t, start, stop);

    printf("Количество итераций: %d\n", N);
    printf("Cумма числового ряда: %.6f\n", sum);
    printf("Время вычисления в gpu: %.4f мс\n", gpu_calc_time);
    printf("Время пересылок: %.4f мс\n", gpu_send_time);
    printf("Время суммирования в cpu: %.4f мс\n", cpu_t);
    printf("Общее время: %.4f мс\n", gpu_calc_time + gpu_send_time + cpu_t);

    cudaEventDestroy(start);
    cudaEventDestroy(stop);
    return 0;
}
