// Distrución de tareas con for y lastprivate
#include <stdio.h>
#include <omp.h>
int main( int argc, char *argv[] ){
	int i=5, N=10;
        int idHilo=6;

        #pragma omp parallel for lastprivate(i) private(idHilo) 
        for(i = 0; i < N; i++ ) {
           idHilo=omp_get_thread_num(); 
           printf("Iteración correspondiente al Hilo %d\n", idHilo);
          }

       printf("El ultimo valor del i es %d \n",i);


 return 0;
}
