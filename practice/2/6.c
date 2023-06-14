#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void printThreadsProc()
{
    int num_threads, num_proc;

    num_threads = omp_get_max_threads(); // максимально допустимое число нитей
    num_proc = omp_get_num_procs();      // число доступных ядер с учетом гипертрейдинга

    printf("\n----------------\n");
    printf("number of treads %d\n", num_threads);  // равно значению OMP_NUM_THREADS
    printf("number of proceccors %d\n", num_proc); // равно значению OMP_NUM_THREADS
    printf("---------------\n");
}

int main(int argc, char *argv[]){
    printf("\n\nExample 6.\n");
    omp_set_num_threads(28); // 10 потоков
    printThreadsProc();
    int n = 1;
    printf("n in sequential region (begin): %d\n", n);
#pragma omp parallel private(n)
    {
        printf("Value of n in tread (input): %d\n", n);
        /* Value of n equal number of particular tread */
        n = omp_get_thread_num();
        printf("Value of n in tread (output): %d\n", n);
    }
    printf("n in sequential region (end): %d\n", n);

    printf("\n\n---------------\nEND.\n---------------\n");
    return 0;
}