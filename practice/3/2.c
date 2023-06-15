#include <stdio.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
    int version, sub_version;

    MPI_Init(&argc, &argv);

    // специальная функция для определения версии
    MPI_Get_version(&version, &sub_version); 
    printf("MPI Version %d.%d\n", version, sub_version);

    MPI_Finalize();
    return 0;
}
