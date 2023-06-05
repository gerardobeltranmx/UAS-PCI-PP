#include <stdio.h>
#include <omp.h>

int main( int argc, char * argv[] ) {


   #pragma omp parallel
    {
        int idHilo = omp_get_thread_num();
        printf("Yo soy el hilo %d y tengo el numero: %s \n",
                idHilo, argv[idHilo+1]);
    }


 return 0;
}

