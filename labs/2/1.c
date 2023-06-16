#include <stdio.h>
#include <omp.h>
int main()
{
    omp_sched_t type;
    int chunk;
    omp_get_schedule(&type, &chunk);
    printf("schedule type: %i\n", type);
    printf("schedule chunk: %i\n", chunk);
    return 0;
}
