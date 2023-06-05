// Uso de firstprivate 
#include <stdio.h>
#include <omp.h>
int main(){
  int x = 1;
  int y = 2;
  int z = 3;

    #pragma omp parallel shared(y)  firstprivate(x,z) 
    { 
        int hilo = omp_get_thread_num();
        printf("---------------------------------------\n")   ;
        printf("Región Paralela (%d) valor x = %d \n", hilo, x);
        z = x * x + 3; 
    	x = y * 3 + z;
        y = z + 5; 
        printf("Región Paralela (%d) valor y = %d \n", hilo, y);
        printf("Región Paralela (%d) valor z = %d \n", hilo, z);
        printf("Región Paralela (%d) valor x = %d \n", hilo, x);

    }
    printf("---------------------------------------\n")   ;
    printf("Región Serie valor x  = %d \n", x);
    printf("Región Serie valor y  = %d \n", y);
    printf("Región Serie valor z  = %d \n", z);

	
return 0;
}