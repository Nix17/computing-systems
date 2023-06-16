// PROGRAM 4

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
    int num_threads;
    int total_iterations = 0;
    int thread_iterations[32] = {0}; // Assuming up to 32 threads, adjust accordingly
    double start_time, end_time;
    double static_time, dynamic_time, guided_time, auto_time;

    printf("Введите количество значений для вычисления: ");
    scanf("%d", &n);

    printf("Введите количество потоков: ");
    scanf("%d", &num_threads);

    start_time = omp_get_wtime(); // Замеряем время начала выполнения цикла

#pragma omp parallel num_threads(num_threads)
    {
        int thread_num = omp_get_thread_num();
#pragma omp for schedule(static, 1) private(i)
        for (i = 1; i <= n; i++)
        {
            float term = calculateSeriesTerm(i);
            printf("a%d = %f\n", i, term);
            printf("Tread %d does iteration %d on core %d\n", thread_num, i, thread_num % num_threads);

// Use atomic to update thread_iterations
#pragma omp atomic
            thread_iterations[thread_num]++;

// Use a critical section to update total_iterations
#pragma omp critical
            total_iterations++;
        }
    }
    end_time = omp_get_wtime(); // Замеряем время окончания выполнения цикла
    static_time = end_time - start_time;
    printf("Время выполнения планирования static: %f секунд\n", static_time);
    printf("Распределение итераций при планировании static:\n");
    for (i = 0; i < num_threads; i++)
    {
        printf("Поток %d выполнил %d итераций\n", i, thread_iterations[i]);
    }

    printf("Общее количество выполненных итераций: %d\n", total_iterations);

    start_time = omp_get_wtime();
    total_iterations = 0;
    for (i = 0; i < num_threads; i++)
    {
        thread_iterations[i] = 0;
    }

#pragma omp parallel num_threads(num_threads)
    {
        int thread_num = omp_get_thread_num();
#pragma omp for schedule(dynamic, 6) private(i)
        for (i = 1; i <= n; i++)
        {
            float term = calculateSeriesTerm(i);
            printf("a%d = %f\n", i, term);
            printf("Tread %d does iteration %d on core %d\n", thread_num, i, thread_num % num_threads);

// Use atomic to update thread_iterations
#pragma omp atomic
            thread_iterations[thread_num]++;

// Use a critical section to update total_iterations
#pragma omp critical
            total_iterations++;
        }
    }
    end_time = omp_get_wtime(); // Замеряем время окончания выполнения цикла
    dynamic_time = end_time - start_time;
    printf("Время выполнения планирования dynamic: %f секунд\n", dynamic_time);
    printf("Распределение итераций при планировании dynamic:\n");
    for (i = 0; i < num_threads; i++)
    {
        printf("Поток %d выполнил %d итераций\n", i, thread_iterations[i]);
    }

    printf("Общее количество выполненных итераций: %d\n", total_iterations);

    start_time = omp_get_wtime();
    total_iterations = 0;
    for (i = 0; i < num_threads; i++)
    {
        thread_iterations[i] = 0;
    }

#pragma omp parallel num_threads(num_threads)
    {
        int thread_num = omp_get_thread_num();
#pragma omp for schedule(guided, 3) private(i)
        for (i = 1; i <= n; i++)
        {
            float term = calculateSeriesTerm(i);
            printf("a%d = %f\n", i, term);
            printf("Tread %d does iteration %d on core %d\n", thread_num, i, thread_num % num_threads);

// Use atomic to update thread_iterations
#pragma omp atomic
            thread_iterations[thread_num]++;

// Use a critical section to update total_iterations
#pragma omp critical
            total_iterations++;
        }
    }
    end_time = omp_get_wtime(); // Замеряем время окончания выполнения цикла
    guided_time = end_time - start_time;
    printf("Время выполнения планирования guided: %f секунд\n", guided_time);
    printf("Распределение итераций при планировании guided:\n");
    for (i = 0; i < num_threads; i++)
    {
        printf("Поток %d выполнил %d итераций\n", i, thread_iterations[i]);
    }

    printf("Общее количество выполненных итераций: %d\n", total_iterations);

    start_time = omp_get_wtime();
    total_iterations = 0;
    for (i = 0; i < num_threads; i++)
    {
        thread_iterations[i] = 0;
    }

#pragma omp parallel num_threads(num_threads)
    {
        int thread_num = omp_get_thread_num();
#pragma omp for schedule(auto) private(i)
        for (i = 1; i <= n; i++)
        {
            float term = calculateSeriesTerm(i);
            printf("a%d = %f\n", i, term);
            printf("Tread %d does iteration %d on core %d\n", thread_num, i, thread_num % num_threads);

// Use atomic to update thread_iterations
#pragma omp atomic
            thread_iterations[thread_num]++;

// Use a critical section to update total_iterations
#pragma omp critical
            total_iterations++;
        }
    }
    end_time = omp_get_wtime(); // Замеряем время окончания выполнения цикла
    auto_time = end_time - start_time;
    printf("Время выполнения планирования auto: %f секунд\n", auto_time);
    printf("Распределение итераций при планировании auto:\n");
    for (i = 0; i < num_threads; i++)
    {
        printf("Поток %d выполнил %d итераций\n", i, thread_iterations[i]);
    }
    total_iterations = 0;
    for (i = 0; i < num_threads; i++)
    {
        thread_iterations[i] = 0;
    }

    printf("Общее количество выполненных итераций: %d\n", total_iterations);

    return 0;
}
