#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>

const char Mensaje[]="Hola desde el Servidor\n";

int main(int argc, char *argv[]){

int mi_socket = 0;
int puerto = 0;
int estado = 0;
struct sockaddr_in mi_estructura;

if(argc != 2){

fprintf(stderr, "Use: %s <puerto>\n", argv[0]);
exit(1);

}//fin del if

mi_socket = socket(AF_INET, SOCK_STREAM, 0);

if(mi_socket == -1){

	fprintf(stderr, "No es posible crear socket!!\n");
	exit(1);

}
else{
	fprintf(stderr, "Socket Creado\n");
}//fin del if


//Recupera el numero de puerto para escuchar
puerto = atoi(argv[1]);

//levanta la estructura de direccion
//utiliza INADD_ANY para relacionar a todas las direcciones locales
//bzero(&simpleServer, sizeof(simpleServer));

mi_estructura.sin_family = AF_INET;
mi_estructura.sin_addr.s_addr = htonl(INADDR_ANY);
mi_estructura.sin_port = htons(puerto);


//relacionar la direccion y puerto con nuestro socket
estado = bind(mi_socket, (struct sockaddr *)&mi_estructura, sizeof(mi_estructura));


if(estado == 0){

	fprintf(stderr, "Enlace completado\n");

}else
{

	fprintf(stderr, "No es posible enlace con la direccion\n");
	close(mi_socket);
	exit(1);

}//fin del if


//escuchar las conexiones en el socket
estado = listen(mi_socket, 5);

if(estado == -1){

	fprintf(stderr, "No es posible escuchar por el socket\n");
	close(mi_socket);
	exit(1);	

}//fin del if


while(1){

	struct sockaddr_in cliente = { 0 };
	int socket_hijo = 0;
	int long_cliente = sizeof(cliente);


	//esperar aqui
	socket_hijo = accept(mi_socket, (struct sockaddr *)&cliente, &long_cliente);

	if(socket_hijo == -1){

		fprintf(stderr, "Cannot accept connections!\n");
		close(socket);
		exit(1);
	}//fin del if


	//manejar la nueva solicitud de conexion
	//envia el mensaje al cliente
  time_t rawtime;
  struct tm * timeinfo;
  time ( &rawtime );
  timeinfo = (struct tm *)localtime ( &rawtime );
//  printf ( "The current date/time is: %s", asctime (timeinfo) );

	send(socket_hijo, (char*) asctime (timeinfo), strlen(Mensaje),0);
	close(socket_hijo);

}//fin del while


close(socket);

return 0;

}//fin del main