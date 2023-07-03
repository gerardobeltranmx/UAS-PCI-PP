// reducción buscando el mayor
#include <stdio.h>
#include <mpi.h>
#define tam 100
int idProc, nProc, datos[tam], i, tag = 99, primero, ultimo, bloque;
int  mayor = 0,pmayor = 0;
MPI_Status status;
int main (int argc, char** argv)
{
MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &idProc);
MPI_Comm_size(MPI_COMM_WORLD, &nProc);
/* Rellena el vector a */
if (idProc == 0) for (i=0;i<tam;i++) datos[i] = i + 1;
// Difunde el vector a *
MPI_Bcast(datos,tam,MPI_INT,0,MPI_COMM_WORLD);
// Determina nmeros a sumar
bloque = tam/nProc;
if (idProc == nProc - 1) {

primero = (nProc - 1)*bloque;
ultimo = tam - 1;
}
else {
primero = idProc*bloque;
ultimo = (idProc + 1)*bloque - 1;
}
// Computa la suma parcial
int  pmayor = datos[primero];
for (i=primero;i<=ultimo;i++)
        if (pmayor < datos[i])
             pmayor = datos[i];

// Hacer la reduccin de los mayores  parciales para obtener el mayor de  todos
MPI_Reduce(&pmayor,&mayor,1,MPI_INT, MPI_MAX,0,MPI_COMM_WORLD);
if (idProc == 0) printf("Mayor: %10d\n",mayor);
MPI_Finalize();
}
