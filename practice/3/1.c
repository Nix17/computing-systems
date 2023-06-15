#include <stdio.h>
#include "mpi.h" //кавычки определяют другой вариант поиска //заголовочного файла
int main(int argc, char **argv)
{    
    int i;
    MPI_Init(&argc, &argv);
    if (i == MPI_SUCCESS)
        printf("Successful initialization with code %d\n", i);
    else
        printf("Initialization failed with error code %d\n", i);
    MPI_Finalize();
    if (i == MPI_SUCCESS)
        printf("Successful MPI_Finalize() with code %d\n", i);
    else
        printf("MPI_Finalize() failed with error code %d\n", i);
    return (0);
}