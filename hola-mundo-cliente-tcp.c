/* Archivo: hola-mundo-cliente-tcp.c */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/* DEFINICIONES */
#define PORT 5000
#define SIZE 1024

/* SINONIMOS */
typedef struct sockaddr *sad;

/* FUNCIONES */
void error(char*s)
{
	perror(s);
	exit(-1);
}

/* FUNCION PRINCIPAL */
int main(int argc, char **argv)
{
	int sock;
	struct sockaddr_in sin;
	char linea [SIZE];
	int cuanto;
	
	if(argc<2){
		fprintf(stderr,"Uso:%s ipaddr\n", argv[0]);
		exit(-1);
	}
	
	if((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0 )
		error("socket");
	
	sin.sin_family=AF_INET;
	sin.sin_port=htons(PORT); //Host to Network Short
	
	inet_aton(argv[1],&sin.sin_addr); //Ascii To Network
	
	if(connect(sock,(sad)&sin, sizeof sin) < 0)
		error("connect");
	
	write(sock,"Hola mundo!\n",12);
	cuanto = read(sock, linea, SIZE);
	linea[cuanto]=0;
	printf("Contestaron: %s\n", linea);
	close (sock);
	return 0;
}
/* Fin Archivo: hola-mundo-cliente-tcp.c */
