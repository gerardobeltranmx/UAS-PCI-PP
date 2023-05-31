#include <stdio.h>
#include <omp.h>
int main(int argc, char *argv[]){  

#pragma omp parallel 
 {    
   int  IdHilo,NumHilos, NumCPUs;      
   /* obtiene el ID del hilo actual */   
  IdHilo = omp_get_thread_num();  
  NumHilos = omp_get_num_threads(); 
  NumCPUs = omp_get_num_procs();       
  printf("Hola yo soy el hilo %d \n", IdHilo);        
      if (IdHilo == 0) {    
	printf("Num. de CPUs  = %d \n", NumCPUs);      
	printf("Num. de Hilos Totales    = %d \n", NumHilos);    
      }  
 }

return 0;

}
