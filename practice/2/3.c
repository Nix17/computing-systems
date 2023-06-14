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

int main(int argc, char *argv[])
{
    printf("\n\nExample 3.\n\n");

    omp_set_num_threads(23);

    printf("Sequential region 1\n");
#pragma omp parallel
    { // Начало пар
        int thread_num = omp_get_thread_num();
        printf("Parallel region: Thread %d\n", thread_num);
    } // Конец пар

    printf("Sequential region 2\n");

    return 0;
}