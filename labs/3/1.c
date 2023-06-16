#include <stdio.h>
#include <omp.h>
#include <unistd.h>
int main()
{
    double start_time, end_time, tick, summa;
    start_time = omp_get_wtime();
    sleep(1);
    int i;
    double s;
    for (i = 0; i <= 550000000; i++)
    {
        s = 3.0 / ((10 * i * i) - (2 * i) - 3);
        summa += s;
    }
    end_time = omp_get_wtime();
    tick = omp_get_wtick();
    printf("Time range %E\n", end_time - start_time);
    printf("Accuracy of timer %E\n", tick);
    printf("Sum = %E\n", summa);
    return 0;
}