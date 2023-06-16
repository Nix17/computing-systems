#include <stdio.h>
#include <omp.h>

double function(double x)
{
    return 5.0 * x / ((x + 1.0) * (x + 1.0));
}

const double MIN_VALUE = 1;
const double MAX_VALUE = 2;
const double MAX_ITERATIONS = 300000000;
const double MIN_ITERATIONS = 3;
const double ITERATIONS_MULTIPLIER = 10;

int main()
{
    printf("Counts;\t\t\tThreads;\t\tResult;\t\t\tTime\n");

    for (long iteration_count = MIN_ITERATIONS;
         iteration_count <= MAX_ITERATIONS;
         iteration_count *= ITERATIONS_MULTIPLIER)
    {

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
    }

    return 0;
}