// Uso de clausula default
#include <stdio.h>
#include <omp.h>
int main(){
    int x = 2;
    int y = 1;
    int z = 3;
    #pragma omp parallel default(shared) firstprivate(x,z)
    { 
        printf("---------------------------------------\n")   ;
        printf("Region Paralela valor x = %d \n", x);
        z = x * x + 3; 
        x = y * 3 + z;
        y = z + 5; 
        printf("Region Paralela valor z = %d \n", z);
    }

printf("---------------------------------------\n")   ;
printf("Region Serie valor x  = %d \n", x);
printf("Region Serie valor y  = %d \n", y);
printf("Region Serie valor z  = %d \n", z);

	
return 0;
}