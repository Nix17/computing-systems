#include <stdio.h>
#include "mpi.h"
int main(int argc, char *argv[])
{
    int size, rank, a, b;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    if (rank == 0)
    // Действия, выполняемые только процессом с рангом 0
    {
        a = 1;
    }
    else // Действия, выполняемые остальными процессами
    {
        a = 0;
    }
    // Широковещательная рассылка //«а» от нулевого процесса всем остальным
    MPI_Bcast(&a, 1, MPI_INT, 0, MPI_COMM_WORLD);               
    
    // Редукция в //виде суммы «а» от всех процессов на нулевом процессе. Результат суммы «а» //записывается в «b»
    MPI_Reduce(&a, &b, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    
    // Все процессы печатают свой номер и «b». //Для всех процессов, кроме нулевого, «b» не определено. Для нулевого: b=size
    printf("process %d, b = %d\n", rank, b);                   
    MPI_Finalize();
    return 0;
}