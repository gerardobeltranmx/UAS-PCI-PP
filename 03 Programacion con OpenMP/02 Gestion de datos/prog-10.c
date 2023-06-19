// Distribucion de tareas con for con clausula reduction - multiplicacion
#include <stdio.h>
#include <omp.h>


int main( int argc, char *argv[] ){
        int valor=10; 
        int i, mul=1; 
        int a[]={10,20,30,40,50};
        int N=5;  

        #pragma omp parallel for private(i) reduction(*:mul)   
         for(i=0;i<N;i++){ 
              mul*=a[i];
              printf("Multiplicacion %d en el hilo %d\n", mul, omp_get_thread_num());
         }
       printf("El  valor de mul es %d \n",mul);


 return 0;
}