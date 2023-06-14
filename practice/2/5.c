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
    printf("\n\nExample 5.\n\n");
    int count;
    omp_set_num_threads(27);
#pragma omp parallel
    {
        int num;
        count = omp_get_num_threads(); // число нитей всего
        num = omp_get_thread_num();    // номер нити, у каждой свой
        if (num == 0)
        {
            printf("Quantity of treads: %d\n", count);
        }
        else
        {
            printf("Number of tread %d\n", num);
        }
    }

    return 0;
}