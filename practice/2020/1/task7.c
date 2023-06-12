#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    omp_set_num_threads(10);//10 потоков
    int n=1;
    printf("n in sequential region (begin): %d\n", n);
    #pragma omp parallel private(n) 
    {
        printf("Value of n in tread (input): %d\n", n); 
        /* Value of n equal number of particular tread */ 
        n=omp_get_thread_num();
        printf("Value of n in tread (output): %d\n", n); 
    }
    printf("n in sequential region (end): %d\n", n);
    return 0;
}