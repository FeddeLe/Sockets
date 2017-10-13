#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

#include <unistd.h>


int main (void)
{   
	char server_message[256] = "The Server is ON. Connection established\n";


	////////CREATE SOCKET////////
	int server_socket;
	int client_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);



	///////DEFINE SERVER ADDRESS, STRUCT OF TYPE "sockaddr_in"//////////
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;


	///////ASSIGNING A NAME TO A SOCKET//////////
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));


	///////WAIT FOR A CONNECTION/////////
	listen(server_socket,10);


	///////ACCEPT THE CONNECTION/////////
 	client_socket = accept(server_socket,NULL,NULL);


 	//////SEND DATA, IN THIS CASE THE MESSAGE///////
 	send(client_socket, server_message, sizeof(server_message), 0);


 	//////CLOSE THE CONNECTION, CLOSE THE SOCKET//////
 	close(server_socket);

	return 0;
}
