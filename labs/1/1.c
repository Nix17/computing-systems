#include <stdio.h>

const int N = 550000000;

int main()
{
    double sum = 0;
    for (int n = 1; n < N; ++n)
    {
        double result = 3.0 / ((10 * n * n) - (2 * n) - 3);
        sum += result;
    }
    printf("Result: %.20f\n", sum);
    return 0;
}
