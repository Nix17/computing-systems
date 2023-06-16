// PROGRAM 3

#include <stdio.h>
#include <omp.h>

float calculateSeriesTerm(int n)
{
    float result;
    int i;

    i = n;                                        // Используем n в качестве значения счетчика i
    result = 3.0 / ((10 * n * n) - (2 * n) - 3); // Вычисляем общий член ряда

    return result;
}

int main()
{
    int n, i;
    double start_time, end_time;
    double static_time, dynamic_time, guided_time, auto_time;
    int num_threads = 0;

    printf("Введите количество значений для вычисления: ");
    scanf("%d", &n);

#pragma omp parallel
    {
#pragma omp master
        num_threads = omp_get_num_threads();
    }

    printf("Количество потоков: %d\n", num_threads);

    start_time = omp_get_wtime(); // Замеряем время начала выполнения цикла

    printf("Статическое планирование\n");
    omp_set_schedule(omp_sched_static, 4); // Установка статического планирования
    start_time = omp_get_wtime();          // Замеряем время начала выполнения цикла
#pragma omp parallel for schedule(static)
    for (i = 1; i <= n; i++)
    {
        float term = calculateSeriesTerm(i);
        printf("a%d = %f\n", i, term);
        printf("Tread %d does iteration %d\n", omp_get_thread_num(), i);
    }
    end_time = omp_get_wtime(); // Замеряем время окончания выполнения цикла
    static_time = end_time - start_time;

    printf("Динамическое планирование\n");
    omp_set_schedule(omp_sched_dynamic, 4); // Установка динамического планирования
    start_time = omp_get_wtime();           // Замеряем время начала выполнения цикла
#pragma omp parallel for schedule(dynamic)
    for (i = 1; i <= n; i++)
    {
        float term = calculateSeriesTerm(i);
        printf("a%d = %f\n", i, term);
        printf("Tread %d does iteration %d\n", omp_get_thread_num(), i);
    }
    end_time = omp_get_wtime(); // Замеряем время окончания выполнения цикла
    dynamic_time = end_time - start_time;

    printf("Guided планирование\n");
    omp_set_schedule(omp_sched_guided, 4); // Установка guided планирования
    start_time = omp_get_wtime();          // Замеряем время начала выполнения цикла
#pragma omp parallel for schedule(guided)
    for (i = 1; i <= n; i++)
    {
        float term = calculateSeriesTerm(i);
        printf("a%d = %f\n", i, term);
        printf("Tread %d does iteration %d\n", omp_get_thread_num(), i);
    }
    end_time = omp_get_wtime(); // Замеряем время окончания выполнения цикла
    guided_time = end_time - start_time;

    printf("Auto планирование\n");
    start_time = omp_get_wtime(); // Замеряем время начала выполнения цикла
#pragma omp parallel for schedule(auto)
    for (i = 1; i <= n; i++)
    {
        float term = calculateSeriesTerm(i);
        printf("a%d = %f\n", i, term);
        printf("Tread %d does iteration %d\n", omp_get_thread_num(), i);
    }
    end_time = omp_get_wtime(); // Замеряем время окончания выполнения цикла
    auto_time = end_time - start_time;

    printf("Время выполнения:\n");
    printf("Статическое планирование: %f секунд\n", static_time);
    printf("Динамическое планирование: %f секунд\n", dynamic_time);
    printf("Guided планирование: %f секунд\n", guided_time);
    printf("Auto планирование: %f секунд\n", auto_time);

    // Определение наиболее сбалансированных алгоритмов
    double min_time = static_time;
    if (dynamic_time < min_time)
        min_time = dynamic_time;
    if (guided_time < min_time)
        min_time = guided_time;
    if (auto_time < min_time)
        min_time = auto_time;

    printf("Наиболее сбалансированные алгоритмы:\n");
    if (static_time == min_time)
        printf("Статическое планирование\n");
    if (dynamic_time == min_time)
        printf("Динамическое планирование\n");
    if (guided_time == min_time)
        printf("Guided планирование\n");
    if (auto_time == min_time)
        printf("Auto планирование\n");

    return 0;
}
