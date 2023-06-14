#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void printThreadsProc()
{
    int num_threads, num_proc;

    num_threads = omp_get_max_threads(); // максимально допустимое число нитей
    num_proc = omp_get_num_procs();      // число доступных ядер с учетом гипертрейдинга

    printf("\n----------------\n");
    printf("number of threads %d\n", num_threads); // равно значению OMP_NUM_THREADS
    printf("number of processors %d\n", num_proc); // равно значению OMP_NUM_THREADS
    printf("---------------\n");
}

int main(int argc, char *argv[])
{
    printf("\n\nExample 9.\n");

    omp_set_num_threads(26);
    printThreadsProc();

    int count = 0;
#pragma omp parallel reduction(+ : count)
    {
        count++;
        printf("Value of count: %d\n", count);
    }
    printf("Number of treads: %d\n", count);

    printf("\n\n---------------\nEND.\n---------------\n");
    return 0;
}
