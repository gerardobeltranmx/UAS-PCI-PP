#include <stdio.h>
#include <string.h>
#include <mpi.h>
int idproc, nproc, resultlen;
char nombre[30];
int main (int argc, char** argv)
{

char arch[4][100];

strcpy(arch[0], argv[1]);
strcpy(arch[1], argv[2]);
strcpy(arch[2], argv[3]);
strcpy(arch[3], argv[4]);

MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &idproc);
MPI_Comm_size(MPI_COMM_WORLD, &nproc);
MPI_Get_processor_name(nombre, &resultlen);

printf("Hola Mundo! Yo soy %d de %d corriendo en %s usando el archivo %s\n",idproc, nproc, nombre,arch[idproc]);
MPI_Finalize();
}

