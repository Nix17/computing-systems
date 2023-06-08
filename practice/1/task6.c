#include <stdio.h>
#include <omp.h>
#define myNUM 14

int main(int argc, char *argv[])
{
    printf("Starostenkov A.A. VM-19 (mag.)\n\n");
    int i;
    int num = myNUM + 10;
    //num_threads(num)
    omp_set_num_threads(num);
    int m[40]; 
    printf("massive m in the beginning:\n"); 
    /* Обнуление элементов массива*/ 
    for (i = 0; i < 40; i++)
    {
        m[i]=0;
        //печатаем 10 элементов массива, равных нулю
        printf("%d\t", m[i]);
    }
    //объявляем массив общим
    #pragma omp parallel shared(m)
    {
        /* Совместное заполнение общего массива. */
        m[omp_get_thread_num()] = omp_get_thread_num();
        //Каждая нить записывает
        //свой номер только в один элемент массива. Массив заполняется совместно всеми
        //нитями, но гонок нет, так как нити работают с разными элементами массива!
    }
    printf("\n\n");
    printf("massive m in the end:\n");
    for (i = 0; i < num; i++)
    {
        printf("%d\t", m[i]);
    }
    printf("\n\n");
    return 0;
}