// Uso de clausula if
#include <stdio.h>
#include <string.h>
#include <omp.h>
int main(int argc, char *argv[]){

  #pragma omp parallel if(argc > 1 && !strcmp("todos",argv[1]))
  { 	
    printf("Hola desde  %s \n", argv[0]);
 }


	
return 0;
}