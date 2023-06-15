#include <stdio.h>
#include "mpi.h"
int main(int argc, char **argv)
{
    double start_time, end_time, tick;
    MPI_Init(&argc, &argv);
    start_time = MPI_Wtime();
    sleep(1);
    end_time = MPI_Wtime();
    tick = MPI_Wtick();
    printf("Time to measure %E\n", end_time - start_time);
    printf("Accuracy of timer %E\n", tick);
    MPI_Finalize();
    return 0;
}
