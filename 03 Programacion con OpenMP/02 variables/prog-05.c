// Uso de clausula num_threads
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


int main(int argc, char *argv[]){

if (argc==2){

   int num = atoi(argv[1]);
   
  #pragma omp parallel num_threads(num)
  { 	
    printf("Hola!!! desde el hilo %d\n", omp_get_thread_num());
  }

}

	
return 0;
}