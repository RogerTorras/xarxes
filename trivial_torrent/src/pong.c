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
#include <sys/types.h>
#include <sys/socket.h> 

int main(int argc, char **argv) {

	(void) argc; // This is how an unused parameter warning is silenced.
	(void) argv;
	int s = socket(PF_INET,SOCK_GRAM,0);
	
	int bild(int sockfd, const struct sockaddr *myaddr,int affrlen);

	// TODO: some socket stuff here

	return 0;
}
