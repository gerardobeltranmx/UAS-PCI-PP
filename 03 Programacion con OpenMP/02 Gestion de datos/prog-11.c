 // Distrución de tareas con for y uso de secciones

 #include <stdio.h>
#include <omp.h>

int max(int v[], int N){
int i=0, mayor=v[0];   

for(i=1; i<N; i++)
   if(v[i]>mayor) mayor=v[i]; 

return mayor;
}

int min(int v[], int N){
int i=0, menor=v[0];   

for(i=1; i<N; i++)
   if(v[i]<menor) menor=v[i]; 

return menor;
}

int main(){
int vector[]={5,8,0,4,3,1,6,9,7,2};
int N=10, may, men;

#pragma omp parallel sections 
{
  #pragma omp section
  {
    printf("Buscando el mayor en el hilo %d\n",omp_get_thread_num()); 
    may  = max(vector, N);
         
  }
  #pragma omp section
  {
    printf("Buscando el menor en el hilo %d\n",omp_get_thread_num()); 
    men  = min(vector, N);
  }
}

  printf("El valor mayor es %d\n",may);
  printf("El valor menor es %d\n",men);

return 1;
}