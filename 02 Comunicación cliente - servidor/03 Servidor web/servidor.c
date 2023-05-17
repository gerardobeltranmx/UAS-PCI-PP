#include<stdlib.h>
#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

// Programa que envia un saludo a los clientes que establecen una conexion

int main(int argc, char *argv[]){

char Mensaje[100];
int mi_socket = 0;
int puerto = 0;
int estado = 0;
struct sockaddr_in dir;

if(argc != 3){

printf("Use: %s <puerto> <pagina>\n", argv[0]);
exit(1);

}//fin del if

mi_socket = socket(AF_INET, SOCK_STREAM, 0);

if(mi_socket == -1){

	printf("No es posible crear socket!!\n");
	exit(1);

}
else{
	printf("Socket Creado\n");
}//fin del if


//Recupera el numero de puerto para escuchar
puerto = atoi(argv[1]);

//levanta la estructura de direccion
//utiliza INADD_ANY para relacionar a todas las direcciones locales

dir.sin_family = AF_INET;
dir.sin_addr.s_addr = htonl(INADDR_ANY);
dir.sin_port = htons(puerto);


//relacionar la direccion y puerto con nuestro socket
estado = bind(mi_socket, (struct sockaddr *)&dir, sizeof(dir));


if(estado == 0){

	printf("Enlace completado\n");

}else
{
	printf("No es posible enlace con la direccion\n");
	close(mi_socket);
	exit(1);

}//fin del if


//escuchar las conexiones en el socket
estado = listen(mi_socket, 5);

if(estado == -1){

	printf("No es posible escuchar por el socket\n");
	close(mi_socket);
	exit(1);	

}//fin del if


while(1){

	struct sockaddr_in cliente = { 0 };
	int socket_hijo = 0;
	socklen_t long_cliente = sizeof(cliente);


	//esperar aqui
	socket_hijo = accept(mi_socket, (struct sockaddr *)&cliente, &long_cliente);
         
       	if(socket_hijo == -1){

		printf("No puede aceptar conexiones!\n");
		close(mi_socket);
		exit(1);
	}//fin del if
 
	//manejar la nueva solicitud de conexion
//	printf("Se atiende una solicitud de cliente!\n");
	
	//Abre archivo de pagina a entregar
		printf("Se atendio una peticion!\n");

    write(socket_hijo,"")    

	FILE *da=fopen(argv[2],"rt");

	while(fgets(Mensaje,sizeof(Mensaje),da)!=NULL){
              
              // printf("%s", Mensaje);  

               write(socket_hijo, Mensaje, strlen(Mensaje));
	}
	
	
        close(socket_hijo);
	
        fclose(da);


}//fin del while

close(mi_socket);

return 0;

}//fin del main