#include <stdio.h>
#include "mpi.h"
int main(int argc, char *argv[])
{
    int N;                          // Число разбиений
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
    for (N = 2000; N <= 200000000; N += 22222000)
    {
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
            printf("Число разбиений: %d\n", N);
            printf("Количество процессов: %d\n", size);
            printf("Приближенное значение: %.5f\n", sum);
            printf("Время вычислений: %.6f\n\n", timer_stop - timer_start);
        }
    }
    MPI_Finalize();
    return 0;
}
