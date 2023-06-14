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
    printf("\n\nExample 10.\n");

    int A[20], B[20], C[20], i, n;
    /* Заполнение массивов */
    for (i = 0; i < 20; i++)
    {
        A[i] = i;
        B[i] = i + 1;
        C[i] = 0;
    }
    omp_set_num_threads(5); // 5 потоков
#pragma omp parallel shared(A, B, C) private(i, n)
    { /* Номер текущей нити */
        n = omp_get_thread_num();
#pragma omp for
        for (i = 0; i < 20; i++)
        {
            C[i] = A[i] + B[i];
            printf("Tread %d number of array element %d\n ", n, i);
        }
    }

    printf("\n\n---------------\nEND.\n---------------\n");
    return 0;
}