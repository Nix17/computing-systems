#include <stdio.h>
#include <omp.h>
#define myNUM 14


int main(int argc, char *argv[])
{
    printf("Starostenkov A.A. VM-19 (mag.)\n\n");
    // Для данного пункта необходимо перед запуском программы запустить
    // команду в терминале "export OMP_NUM_THREADS=15"
    printf("FIRST POINT\n");
    #pragma omp parallel
    {
        printf("Parallel region point 1, thread num: %d\n", omp_get_thread_num());
    }
    printf("\n");

    // Второй пункт
    // Функция OpenMP
    printf("SECOND POINT\n");
    omp_set_num_threads(myNUM + 2);
    #pragma omp parallel
    {
        printf("Parallel region point 2, thread num: %d\n", omp_get_thread_num());
    }
    printf("\n");

    //Третий пункт
    printf("THIRD POINT\n");
    #pragma omp parallel num_threads(myNUM + 3)
    {
        printf("Parallel region point 3, thread num: %d\n", omp_get_thread_num());
    }
    printf("\n");
    printf("END PROGRAM\n");
    return 0;
}