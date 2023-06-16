#include <stdio.h>
#include <omp.h>
const int N = 550000000;
int main()
{
    double sum = 0;
    double start_time = omp_get_wtime();
    for (int n = 0; n < N; ++n)
    {
        double result = 3.0 / ((10 * n * n) - (2 * n) - 3);
        sum += result;
    }
    printf("Result: %.20f; Time: %.20f seconds;\n",
           sum,
           omp_get_wtime() - start_time);
    return 0;
}
