#include <stdio.h>
#include <omp.h>
int main(int argc, char *argv[])
{
   //Объявление переменных
   long i; // Переменная цикла
   int N;// Число разбиений 
   //double h = 1/(double)N; //Вычисление шага
   double timer_Start, timer_Stop, sum = 0, x;
   for(N = 2000; N <= 200000000; N+=22222000)
   {
      sum = 0;
      double h = 1/(double)N;
      //Начальный отсчет таймера
      timer_Start = omp_get_wtime();
      //Главный цикл
      for(i = 1; i < N; i++)
      {
         x = (h*(i-0.5)+1);
         sum+= 9*x*x*x*h/(double)(x * ((x*x) + 3));
      }
      //Конечный отсчет таймера
      timer_Stop = omp_get_wtime();
      //Вывод результатов
      printf("Число разбиений: %d\n", N);
      printf("Приближенное значение: %.5f\n", sum);
      printf("Время вычислений: %.6f\n\n", timer_Stop - timer_Start);
   }; 
return 0;}
