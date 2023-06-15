// Поэлементное сложение векторов (один блок)
#include <cuda.h>
#include <stdio.h>
#define N 128

__global__ void add(int *a, int *b, int *c)
{
    int tid = threadIdx.x; // Связываем элемент массива с глобальным номером нити
    if (tid > N - 1)
        return;
    c[tid] = a[tid] + b[tid]; // каждый tid – одна нить
}

int main()
{
    printf("Starostenkov A.A. VM-22 (mag.)\n");
    printf("Example 4.\n");

    int host_a[N], host_b[N], host_c[N];
    int *dev_a, *dev_b, *dev_c;
    for (int i = 0; i < N; i++)
    {
        host_a[i] = 10;
        host_b[i] = 9;
    }
    cudaMalloc((void **)&dev_a, N * sizeof(int));
    cudaMalloc((void **)&dev_b, N * sizeof(int));
    cudaMalloc((void **)&dev_c, N * sizeof(int));
    cudaMemcpy(dev_a, host_a, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, host_b, N * sizeof(int), cudaMemcpyHostToDevice);
    add<<<1, N>>>(dev_a, dev_b, dev_c); // один блок, N потоков
    cudaMemcpy(host_c, dev_c, N * sizeof(int), cudaMemcpyDeviceToHost);
    for (int i = 0; i < N; i++)
    {
        printf("%d + %d = %d\n", host_a[i], host_b[i], host_c[i]);
    }
    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);
    return 0;
}
