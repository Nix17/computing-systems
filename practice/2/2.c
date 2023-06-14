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
    printf("\n\nExample 2.\n\n");

    double start_time, end_time, tick;
    start_time = omp_get_wtime(); // Начальная отсечка времени
    sleep(19);//Задержка на 19 секунд
    // sleep(1);                   // Задержка на 1 секунду
    end_time = omp_get_wtime(); // Конечная отсечка времени
    tick = omp_get_wtick();     // Точность таймера
    printf("Time range %e\n", end_time - start_time);
    printf("Accuracy of timer %e\n", tick);

    return 0;
}