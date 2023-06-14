#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main(int argc, char *argv[])
{
    printf("Starostenkov A.A. VM-22 (mag.)\n");
    
    printf("Example 1.\n");
#ifdef _OPENMP
    printf("OpenMP Version = %d\n", _OPENMP);
#else
    printf("Sequential Version");
#endif

    return 0;
}