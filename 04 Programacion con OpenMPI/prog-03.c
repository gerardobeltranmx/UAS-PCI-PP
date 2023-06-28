// Funciones Básicas de Comunicación
// MPI_Send y MPI_ Recv.

#include <stdio.h>
#include <mpi.h>
#define tam 10

int idProc, nProc, i, tag = 99, primero, tamBloque, flag, tamNombre;
char nombre[30];
int datos[tam];
long suma, sumaParcial;
MPI_Status status;
int main(int argc, char **argv)
{
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &idProc);
    MPI_Comm_size(MPI_COMM_WORLD, &nProc);
    MPI_Get_processor_name(nombre, &tamNombre);

    nombre[tamNombre] = '\0';

    /* Calcula el tamaño de las partes a enviar a los otros */
    tamBloque = tam / nProc;
    if (idProc == nProc - 1)
    {
        /* Inicializa el vector a */
        printf("datos: ");
        for (i = 0; i < tam; i++){
            datos[i] = i + 1;
            printf("%d ", datos[i]);
        }
        printf("\n");

        /* Envia los bloques de datos los otros procesos*/
        for (i = 0; i < nProc - 1; i++)
        {
            primero = i * tamBloque;
            MPI_Send(&datos[primero], tamBloque, MPI_INT, i, tag, MPI_COMM_WORLD);
        }
        /* determina lo que debo sumar yo (nproc-1) */
        primero = idProc * tamBloque;
        /* efectuo mi suma parcial */
        suma = 0;
        for (i = primero; i < tam ; i++)
            suma = suma + datos[i];
            printf ("Mi suma parcial: %10ld\n", suma);
            /* obtener las sumas parciales y calcula la total */
        for (i = 0; i < nProc - 1; i++)
        {
            MPI_Recv(&sumaParcial, 1, MPI_LONG, MPI_ANY_SOURCE, tag, MPI_COMM_WORLD, &status);
            printf("Respondio %d - envio: %10ld\n", status.MPI_SOURCE, sumaParcial);

            suma = suma + sumaParcial;
        }
        printf("Resultado de la suma = %10ld\n", suma);
    }
    else
    {
        /* recibe mi parte */
        MPI_Recv(datos, tamBloque, MPI_LONG, nProc - 1, tag, MPI_COMM_WORLD, &status);
        /* efectua mi suma parcial */
        sumaParcial = 0;
        for (i = 0; i < tamBloque; i++)
            sumaParcial = sumaParcial + datos[i];
        /* devuelve mi suma parcial a (nproc - 1) */
        MPI_Send(&sumaParcial, 1, MPI_LONG, nProc - 1, tag, MPI_COMM_WORLD);
    }
    MPI_Finalize();
}
