#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>


int main (void)
{
  	char server_data[256];

	///////CREATE A SOCKET/////
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);


	///////SPECIFY AN ADDRESS FOR THE SOCKET///////
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;


	///////CONNECT TO THE SERVER//////
	int connection_status;
	connection_status = connect(network_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	if (connection_status == -1)
	{
		printf("ERROR\n");
	}


	///////IF THE SERVER ACCEPT OUR CONNECTION, RECEIVE THE DATA///////
	recv(network_socket, &server_data, sizeof(server_data), 0);


	//////PRINT THE DATA RECEIVED FROM THE SERVER///////
	printf("%s\n",server_data);

	return 0;
}
