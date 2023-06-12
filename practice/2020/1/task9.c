#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{
      int A[20], B[20], C[20], i, n;
      /* Заполнение массивов */
      for (i = 0; i < 10; i++)
      {
          A[i]=i;
          B[i]=i+1;
          C[i]=0;
      }
      omp_set_num_threads(5);//5 потоков
      
      #pragma omp parallel shared(A, B, C) private(i, n) 
      {
            /* Номер текущей нити */
            n=omp_get_thread_num();
            #pragma omp for
            for (i=0; i<10; i++)
            {
                  C[i]=A[i]+B[i];
                  printf("Tread %d number of array element %d\n", n, i);
            }
      }
      return 0;
}