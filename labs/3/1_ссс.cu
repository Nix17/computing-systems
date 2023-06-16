#include <stdio.h>
#include <cuda.h>

__global__ void computeSum(double* result, int n) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < n) {
        int i = idx + 1;
        double denominator = 5 * i * i - 8.0 * i + 6.0;
        result[idx] = 5.0 / denominator;
    }
}

int main() {
    int n = 1000;  // Количество элементов в ряде
    int blockSize = 256;
    int gridSize = (n + blockSize - 1) / blockSize;

    // Выделение памяти на хосте (CPU)
    double* h_result = (double*)malloc(n * sizeof(double));

    // Выделение памяти на устройстве (GPU)
    double* d_result;
    cudaMalloc((void**)&d_result, n * sizeof(double));

    // Вычисление суммы на GPU
    computeSum<<<gridSize, blockSize>>>(d_result, n);

    // Копирование результата с GPU на CPU
    cudaMemcpy(h_result, d_result, n * sizeof(double), cudaMemcpyDeviceToHost);

    // Вывод результата
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += h_result[i];
    }
    printf("Sum: %f\n", sum);

    // Освобождение памяти
    free(h_result);
    cudaFree(d_result);

    return 0;
}
