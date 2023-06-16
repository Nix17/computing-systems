#include <stdio.h>
#include <omp.h>

double function(double x)
{
    return 5 * x / ((x + 1) * (x + 1));
}

const double MIN_VALUE = 1;
const double MAX_VALUE = 2;

int main()
{
    omp_set_num_threads(32);
    printf("Counts;\t\t\tThreads;\t\tResult;\t\t\tTime\n");
    long iteration_count = 200000000;
    double step = (MAX_VALUE - MIN_VALUE) / iteration_count;
    double start_time = omp_get_wtime();
    double integral = 0;

#pragma omp parallel for reduction(+ : integral)
    for (int i = 0; i < iteration_count - 1; ++i)
    {
        double left_point = MIN_VALUE + step * i;
        double right_point = MIN_VALUE + step * (i + 1);
        double result = function((right_point + left_point) / 2);
        integral += (right_point - left_point) * result;
    }
    printf("%20ld;\t%20ld;\t%.20f;\t%.20f\n",
           iteration_count,
           omp_get_max_threads(),
           integral,
           omp_get_wtime() - start_time);

    return 0;
}
