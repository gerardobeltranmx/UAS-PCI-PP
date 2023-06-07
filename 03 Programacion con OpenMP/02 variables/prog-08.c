// Distrución de tareas con for y lastprivate
#include <stdio.h>
#include <omp.h>
int main( int argc, char *argv[] ){
	int i=0, N=9, suma=0, idHilo;
   int datos[]={1,2,3,4,5,6,7,8,9};

   #pragma omp parallel for private(i, idHilo)
      for(i = 0; i < N; i++ ) {
        suma+=datos[i];
       }

   printf(" la suma es: %d \n", suma);


 return 0;
}
