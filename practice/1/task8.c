#include <stdio.h>
#include <omp.h>
#define myNUM 14

int main(int argc, char *argv[])
{
    printf("Starostenkov A.A. VM-19 (mag.)\n\n");
    omp_set_num_threads(myNUM + 8);
    int count = 0;
    #pragma omp parallel //reduction (+: count)
    {
        count++;
        printf("Value of count: %d\n", count);
    }
    printf("Quantity of treads: %d\n", count);
    return 0;
}