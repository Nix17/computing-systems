#include <stdio.h>
#include <omp.h>
const int N = 550000000;
int main()
{
    double sum = 0;
    double start_time = omp_get_wtime();
    omp_lock_t lock;
    omp_init_lock(&lock);

#pragma omp parallel for
    for (int n = 1; n < N; ++n)
    {
        double result = 3.0 / ((10 * n * n) - (2 * n) - 3);
        omp_set_lock(&lock);
        sum += result;
        omp_unset_lock(&lock);
    }
    omp_destroy_lock(&lock);
    printf("Result: %.20f; Time: %.20f seconds;\n",
           sum,
           omp_get_wtime() - start_time);
    return 0;
}
