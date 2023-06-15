// Получение информации о некоторых свойствах устройств cuda
#include <cuda.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("Starostenkov A.A. VM-22 (mag.)\n");
    printf("Example 1.\n");

    int deviceCount;
    cudaDeviceProp devProp;
    cudaGetDeviceCount(&deviceCount);
    printf("Found %d devices\n", deviceCount);
    for (int device = 0; device < deviceCount; device++)
    {
        cudaGetDeviceProperties(&devProp, device);
        printf("Device %d\n", device);
        printf("Compute capability     : %d.%d\n", devProp.major, devProp.minor);
        printf("Name                   : %s\n", devProp.name);
        printf("Total Global Memory    : %d\n", devProp.totalGlobalMem);
        printf("Shared memory per block: %d\n", devProp.sharedMemPerBlock);
        printf("Registers per block    : %d\n", devProp.regsPerBlock);
        printf("Warp size              : %d\n", devProp.warpSize);
        printf("Max threads per block  : %d\n", devProp.maxThreadsPerBlock);
        printf("Max threads dimensions: x = %d, y = %d, z = %d\n",
               devProp.maxThreadsDim[0],
               devProp.maxThreadsDim[1],
               devProp.maxThreadsDim[2]);
        printf("Max grid size: x = %d, y = %d, z = %d\n",
               devProp.maxGridSize[0],
               devProp.maxGridSize[1],
               devProp.maxGridSize[2]);
        printf("Clock rate: %d\n", devProp.clockRate);
        printf("Multiprocessor count: %d\n", devProp.multiProcessorCount);
        printf("Total constant memory  : %d\n", devProp.totalConstMem);
    }

    return 0;
}
