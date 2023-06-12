#include <stdio.h>
#include <omp.h>
#define myNUM 14

int main(int argc, char *argv[])
{
    printf("Starostenkov A.A. VM-19 (mag.)\n\n");
    int count, num;
    #pragma omp parallel num_threads(myNUM + 7)
    {
        count = omp_get_num_threads();//число нитей всего
        num = omp_get_thread_num();//номер нити, у каждой свой
        if (num == 0)
        {
            printf("Quantity of treads: %d\n", count);
        }
        else
        {
            printf("Number of tread %d\n", num);
        }

    }
    return 0;
}