#include <stdio.h>
#include <omp.h>
int main(int argc, char *argv[])
{
   //Объявление переменных
   long i; // Переменная цикла
   int N = 200000000;// Число разбиений 
   int threads_count = 0, j = 0;
   //double h = 1/(double)N; //Вычисление шага
   double timer_Start, timer_Stop, sum = 0;
   omp_set_num_threads(32);
   for(j = 2; j <= 32; j+=3)
   {
      omp_set_num_threads(j);
      sum = 0;
      double h = 1/(double)N;
      //Начальный отсчет таймера
      timer_Start = omp_get_wtime(); 
      //Расспаралеливание программы
      #pragma omp parallel reduction(+:sum) private(i)
      {
         //Главный цикл
         #pragma omp for
         for(i = 1; i < N; i++)
         {
            double x = (h*(i-0.5)+1);
            sum += 5.0 * x / ((x + 1.0) * (x + 1.0));
         }
         threads_count = omp_get_num_threads();
      }
      //Конечный отсчет таймера
      timer_Stop = omp_get_wtime(); 
      //Вывод результатов
      printf("Number threads %d\n",threads_count);
      printf("Number partitions: %d\n", N);
      printf("Approximate value: %.5f\n", sum);
      printf("Calculation time: %.6f\n\n", timer_Stop - timer_Start);
   } 
   return 0;
}
