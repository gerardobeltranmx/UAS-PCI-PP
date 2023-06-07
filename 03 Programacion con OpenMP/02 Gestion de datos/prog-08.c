// Distrución de tareas con for y uso de variables
#include <stdio.h>
#include <omp.h>
int main( int argc, char *argv[] ){
	int i=0, N=10, suma=0, idHilo;
   int datos[]={1,2,3,4,5,6,7,8,9,10};
   #pragma omp parallel shared(suma) private(i, idHilo)
   {
      #pragma omp parallel for 
        for(i = 0; i < N; i++ ) {
          idHilo=omp_get_thread_num(); 
          printf("El hilo de la operación es: %d\n", idHilo);
          suma+=datos[i];
        }
   }
   printf(" la suma es: %d \n", suma);


 return 0;
}
