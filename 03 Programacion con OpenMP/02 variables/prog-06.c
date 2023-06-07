// Distribución de tareas con for
#include <stdio.h>
#include <omp.h>
#define N 12

int main( int argc, char *argv[] ){
        int a[N];
	int i;
        int idHilo;

        #pragma omp parallel for private(idHilo)
        for(i = 0; i < N; i++ ) {
           a[i] =i*10;
           idHilo=omp_get_thread_num(); 
           printf("a[%d] = %d asignado en hilo %d \n",i, a[i], idHilo);
        }

 return 0;
}
