# computing-systems
Practice, laboratory work, calculation task
mycluster23
```gcc -fopenmp name.c -o name```

```mpicc <имя исходного файла.c> -o <имя исполняемого файла>```

Запуск без системы SLURM на одном узле (на том, куда был совершен вход):

```mpirun -n <число процессов> <имя исполняемого файла>```


```
mpirun -n NUM compileProg
```


Компиляция MPI+OpenMP-программ

```mpicc <имя исходного файла.c> -fopenmp -o <имя исполняемого файла>``` 

Компиляция CUDA-программ

```
module load CUDA
module load GCC

module load CUDA && module load GCC

nvcc <имя файла>.cu -o <имя файла>
srun <имя файла>
```

========================


```
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void printThreadsProc()
{
    int num_threads, num_proc;

    num_threads = omp_get_max_threads(); // максимально допустимое число нитей
    num_proc = omp_get_num_procs();      // число доступных ядер с учетом гипертрейдинга

    printf("\n----------------\n");
    printf("number of treads %d\n", num_threads);  // равно значению OMP_NUM_THREADS
    printf("number of proceccors %d\n", num_proc); // равно значению OMP_NUM_THREADS
    printf("---------------\n");
}

int main(int argc, char *argv[])
{
    printf("\n\nExample 1.\n");

    printf("\n\n---------------\nEND.\n---------------\n");
    return 0;
}
```