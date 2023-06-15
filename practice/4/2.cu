#include <cuda.h>
#include <stdio.h>

__global__ void kern(void)
{ // ничего не делает
}

int main()
{
    printf("Starostenkov A.A. VM-22 (mag.)\n");
    printf("Example 2.\n");

    kern<<<1, 1>>>();
    printf("Hello !\n");
    return 0;
}