#include <stdio.h>
#include <omp.h>

int main( int argc, char * argv[] ) {

   printf("Hola mundo \n");

   #pragma omp parallel
    {
        printf("Hola desde desde el hilo \n");
    }

   printf("Bye mundo \n");

 return 0;
}

