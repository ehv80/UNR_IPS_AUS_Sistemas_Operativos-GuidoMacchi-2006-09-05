#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
typedef struct sockaddr *sad;

void error (char *s)
{
	perror(s);
	exit (-1);
}

int main (int argc , char **argv)
{
	int sock;
	struct sockaddr_in sini, sino;
	char linea [1024];
	int cto,L;

	if ((sock=socket (PF_INET, SOCK_DGRAM,0))<0)
		error("socket");
	sino.sin_family=AF_INET;
	sino.sin_port=htons (PORT);
	inet_pton(AF_INET,argv [1],&sino.sin_addr);
	if(sendto(sock,"hola mundo!\n",12,0,(sad)&sino,sizeof sino0)<0)
		error ("send to");
	L=sizeof (sini);
	if((cto=recvfrom(sock, linea,1024,0,(sad)&sini,&L))<0)
		error("recv from");
	linea[cto]=0;
	printf("%s : %d [%s]\n",inet_ntoa(sini.sin_addr), ntohs(sini.sin_port),linea);
	close(sock);
	return 0;
}

