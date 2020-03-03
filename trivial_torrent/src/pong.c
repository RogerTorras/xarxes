/**
 * This file implements a "UDP ping server".
 *
 * It basically waits for datagrams to arrive, and for each one received, it responds to the original sender
 * with another datagram that has the same payload as the original datagram. The server must reply to 3
 * datagrams and then quit.
 *
 * Test with:
 *
 * $ netcat localhost 8080
 * ping
 * ping
 * pong
 * pong
 *
 * (assuming that this program listens at localhost port 8080)
 *
 */

// TODO: some includes here
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
 
#define PORT 8080
#define MAXLINE 1024

int main(int argc, char **argv) {

	(void) argc; // This is how an unused parameter warning is silenced.
	(void) argv;
	char buffer[MAXLINE];
	struct sockaddr_in servaddr, cliaddr;
	int sockfd = socket(AF_INET,SOCK_DGRAM,0);
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	bind(sockfd, (const struct sockaddr *)&servaddr,sizeof(servaddr));
	
	int n, len;
	len = sizeof(cliaddr);
	for(int i = 0; i<3;i++)
	{
		n = recvfrom(sockfd,(char *) buffer,MAXLINE, MSG_WAITALL, (struct sockaddr *) &cliaddr, &len);
		buffer[n] = '\0';
		printf(buffer);
		sendto(sockfd,(char *) buffer,strlen(buffer), MSG_CONFIRM, (struct sockaddr *) &cliaddr, &len);
	}

	// TODO: some socket stuff here

	return 0;
}
