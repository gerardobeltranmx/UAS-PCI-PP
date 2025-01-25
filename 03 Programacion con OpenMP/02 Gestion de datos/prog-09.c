// Distribucion de tareas con for con clausula reduction - suma
#include <stdio.h>
#include <omp.h>


int main( int argc, char *argv[] ){
        int valor=10; 
        int i, suma=0; 
        int a[]={10,20,30,40,50};
        int N=5;  

        #pragma omp parallel for private(i) reduction(+:suma)   
         for(i=0;i<N;i++){ 
              suma+=a[i];
              printf("Suma %d en el hilo %d\n", suma, omp_get_thread_num());
         }
       printf("El  valor de suma es %d \n",suma);


 return 0;
}