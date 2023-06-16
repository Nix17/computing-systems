#include <stdio.h>
#include <mpi.h>

int main()
{
    int num_procs, rank;
    double start_time, end_time, tick, summa = 0.0;
    int N = 550000000;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    char name[MPI_MAX_PROCESSOR_NAME];
    int len;
    MPI_Get_processor_name(name, &len);

    printf("Максимальное число процессов: %d\n", num_procs);
    printf("Узел: %s\n", name);

    int local_N = N / num_procs;      // Число итераций для каждого процесса
    int start_index = rank * local_N; // Начальный индекс для каждого процесса

    double local_sum = 0.0;
    double s;
    int i;

    start_time = MPI_Wtime();

    // Вычисление частичной суммы для каждого процесса
    for (i = start_index; i < start_index + local_N; i++)
    {
        s = 3.0 / ((10 * i * i) - (2 * i) - 3);
        local_sum += s;
    }

    // Сбор частичных сумм со всех процессов
    MPI_Reduce(&local_sum, &summa, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    end_time = MPI_Wtime();
    tick = MPI_Wtick();
    printf("Time range %E\n", end_time - start_time);
    printf("Accuracy of timer %E\n", tick);

    if (rank == 0)
    {
        printf("Sum = %E\n", summa);
    }
    MPI_Finalize();

    return 0;
}
