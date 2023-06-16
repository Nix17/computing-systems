#include <stdio.h>
#include "mpi.h"

const double MAX_ITERATIONS = 200000000;
const double MIN_ITERATIONS = 2000;

int main(int argc, char *argv[])
{
    int N = 200000000;              // Число разбиений
    double sum = 0;                 // Сумма ряда
    double sum1;                    // Частичная сумма ряда
    double timer_start, timer_stop; // Переменные измерения времени
    int size;                       // Количество процессов
    int rank;                       // Номер процесса
    sum = 0;
    sum1 = 0;
    // Инициализация
    MPI_Init(&argc, &argv);
    // Сведения о количестве процессов
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    // Сведения о номерах процессов
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // for(long N = MIN_ITERATIONS;
    //    N <= MAX_ITERATIONS;
    //  N *= ITERATIONS_MULTIPLIER){

    // Начальный отсчет таймера
    if (rank == 0)
    {
        timer_start = MPI_Wtime();
    }
    // Задаем шаг
    double h = 1 / (double)N;
    sum1 = 0;
    double x;
    for (int i = rank + 1; i <= N; i += size)
    {
        x = (h * (i - 0.5) + 1);
        sum1 += 5.0 * x * h / ((x + 1.0) * (x + 1.0));
    }
    // Подсчет общей суммы ряда в процесс с номером 0
    MPI_Reduce(&sum1, &sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    // Если процесс №0
    if (rank == 0)
    {
        timer_stop = MPI_Wtime();
        // Вывод результатов
        printf("Number of partitions: %d\n", N);
        printf("Number of processes: %d\n", size);
        printf("Approximate value: %.5f\n", sum);
        printf("Calculation time: %.6f\n\n", timer_stop - timer_start);
    }
    //}
    MPI_Finalize();
    return 0;
}
