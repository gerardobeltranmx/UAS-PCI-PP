// Uso de clausula shared y private
#include <stdio.h>
#include <omp.h>


int main(){
    int x = 2;
    int y = 1;
    int z = 3;

    #pragma omp parallel  shared(y) private(x,z)
    {     
        x=4;	
        printf("Región Paralela valor x = %d \n", x);
        z = x * x + 3; 
        x = y * 3 + z;
        y = z + 5; 
        printf("Región Paralela valor z = %d \n", z);
    }

    printf("Región Serie valor x  = %d \n", x);
    printf("Región Serie valor y  = %d \n", y);
    printf("Región Serie valor z  = %d \n", z);
	
return 0;
}