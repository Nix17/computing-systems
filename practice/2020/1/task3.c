#include <stdio.h>
#include <omp.h>

#define MAX_THREADS 19

int main(int argc, char *argv[])
{
    int num_threads, num_proc;
    num_threads = omp_get_max_threads(); //max
    num_proc = omp_get_num_procs();
    printf("num of threads %d\n", num_threads);
    printf("number of proceccors %d\n",num_proc);
    printf("\n");
    //omp_set_num_threads(MAX_THREADS);
    #pragma omp parallel num_threads(MAX_THREADS)
    {
        printf("Parallel region 1\n");
    }
    
    #pragma omp parallel num_threads(MAX_THREADS)
    {
        printf("Parallel region 2\n");
    }
    return 0;
}