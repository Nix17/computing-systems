#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    printf("Starostenkov A.A. VM-19 (mag.)\n");
    double start_time, end_time, tick;
    start_time = omp_get_wtime();
    struct timespec tw = {1, 400000000};
    nanosleep(&tw, NULL);
    end_time = omp_get_wtime();
    tick = omp_get_wtick();
    printf("Time range %E\n", end_time - start_time);
    printf("Accuracy of timer %E\n", tick);
    printf("\n\n");
    return 0;
}