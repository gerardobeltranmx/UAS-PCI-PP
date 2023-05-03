#include<stdlib.h>
#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include <arpa/inet.h>
// Envia 2 valores al servidor y restorna la suma de los mismos
int main(int argc, char *argv[]){

int mi_socket = 0;
int puerto = 0;
int estado = 0;
char Mensaje[256] = "";
struct hostent *hostinfo;
struct sockaddr_in dir;

if(argc != 5){
   printf("Use: %s <servidor> <puerto> <valor1> <valor2>\n", argv[0]);
   exit(1);

}//fin del if

//crear un  socket
mi_socket = socket(AF_INET, SOCK_STREAM, 0);

if(mi_socket == -1){
	printf("No es posible crear socket!!\n");
	exit(1);
}
else{

	printf("Socket creado\n");

}//fin del if

//Recupera el numero de puerto para escuchar
puerto = atoi(argv[2]);

//convertir las cadenas a numeros
hostinfo = gethostbyname(argv[1]);

if(hostinfo == NULL)
	return 1;

//establece valores a la estructura de direccion
 dir.sin_family = AF_INET;
 dir.sin_addr = *((struct in_addr *) hostinfo->h_addr);
 dir.sin_port = htons(puerto);

//conectar la direccion y puerto a nuestro socket
estado = connect(mi_socket, (struct sockaddr *)&dir, sizeof(dir));


if(estado == 0){
	printf("Conexion establecida con exito!!!\n");
}else
{
	printf("No es posible conectar a la direccion!! %s\n", argv[1]);
	close(mi_socket);
	exit(1);
}//fin del if

// envia mensaje al servidor
 char msg_envio[50];
 sprintf(msg_envio, "%s %s", argv[3], argv[4]);

estado = write(mi_socket, msg_envio , sizeof(Mensaje));

if(estado <= 0){
	printf("Error al enviar datos al servidor\n");
}

//obtener el resultado desde el servidor

estado = read(mi_socket, Mensaje, sizeof(Mensaje));

if(estado > 0){
	printf("La suma es: %s\n", Mensaje);
}else
{
  printf("Error = %d\n", estado);
}//fin del if

close(mi_socket);

return 0;
}//fin del main