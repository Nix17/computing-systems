#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rank, size, len;
    char name[MPI_MAX_PROCESSOR_NAME];
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    // Процедура возвращает в
    //строке name имя узла, на котором запущен вызвавший процесс.
    //В переменной len возвращается количество символов в имени,
    //не превышающее значения  константы MPI_MAX_PROCESSOR_NAME
    MPI_Get_processor_name(name, &len);
    printf("Hello.  I am %d of %d on %s\n", rank, size, name);
    MPI_Finalize();
    return 0;
}