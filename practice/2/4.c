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
    printf("\n\nExample 4.\n\n");

    // Переменная окружения export OMP_NUM_THREADS=21 (19 + 2)
    // из файла .bashrc
    printf("Переменная окружения export OMP_NUM_THREADS=21 (19 + 2) из файла .bashrc\n");
    // Получение значения переменной окружения OMP_NUM_THREADS
    char *env_num_threads = getenv("OMP_NUM_THREADS");
    if (env_num_threads != NULL)
    {
        int num_threads_env = atoi(env_num_threads);
        omp_set_num_threads(num_threads_env);
        printf("\n");
        printThreadsProc();
        printf("\n");
    }
    else
    {
        // Обработка случая, когда переменная окружения не была задана или не существует
        // По умолчанию устанавливаем желаемое количество нитей
        printf("\n\n!!!!!!!!!!!!!\nError! Can't get OMP_NUM_THREADS!\n\n");
        omp_set_num_threads(21);
    }

#pragma omp parallel
    {
        int thread_num = omp_get_thread_num();
        printf("Parallel region 1: Thread #%d\n", thread_num);
    }

    printf("\n$$$$$$$$$$$$$$$$$$$$$$\n");

    // задаем 22 потока в параллельной области с помощью ф-ии
    printf("\n\nЗадаем 22 потока в параллельной области с помощью ф-ии omp_set_num_threads\n\n");
    omp_set_num_threads(22);
    printThreadsProc();
#pragma omp parallel
    {
        int thread_num = omp_get_thread_num();
        printf("Parallel region 2: Thread #%d\n", thread_num);
    }

    printf("\n$$$$$$$$$$$$$$$$$$$$$$\n");

    // задаем 23 потока с помощью опции директивы

    printf("\n\nЗадаем 23 потока с помощью опции директивы num_threads(23)\n\n");

#pragma omp parallel num_threads(23)
    {
        int thread_num = omp_get_thread_num();
        printf("Parallel region 3: Thread #%d\n", thread_num);
    }

    return 0;
}