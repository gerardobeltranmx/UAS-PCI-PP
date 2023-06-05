// Uso de clausula if
#include <stdio.h>
#include <string.h>
#include <omp.h>
int main(int argc, char *argv[]){

  int N = argc;
  #pragma omp parallel if(N > 10 )
  { 	
      
  }


	
return 0;
}