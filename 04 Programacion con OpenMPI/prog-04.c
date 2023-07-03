// reducción calculado la Suma
#include <stdio.h>
#include <mpi.h>
#define tam 100
int idProc, nProc, datos[tam], i, tag = 99, primero, ultimo, bloque;
long suma = 0, psuma = 0;
MPI_Status status;
int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &idProc);
    MPI_Comm_size(MPI_COMM_WORLD, &nProc);
    /* Rellena el vector a */
    if (idProc == 0)
        for (i = 0; i < tam; i++)
            datos[i] = i + 1;
    // Difunde el vector a *
    MPI_Bcast(datos, tam, MPI_INT, 0, MPI_COMM_WORLD);
    // Determina nmeros a sumar
    bloque = tam / nProc;
    if (idProc == nProc - 1)
    {

        primero = (nProc - 1) * bloque;
        ultimo = tam - 1;
    }
    else
    {
        primero = idProc * bloque;
        ultimo = (idProc + 1) * bloque - 1;
    }
    // Computa la suma parcial
    for (i = primero; i <= ultimo; i++)
        psuma = psuma + datos[i];
    // Hacer la reduccin de las sumas parciales para obtener la suma total

    MPI_Reduce(&psuma, &suma, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD);
    if (idProc == 0)
        printf("Suma: %10ld\n", suma);
    MPI_Finalize();
}
