#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
	
	char server_message[256] = "You have reached the server!";
	
	// Create socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0); // 0 is default, TCP
	
	// Define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	// Bind 
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	
	// Listen
	listen(server_socket, 2);
	
	int client_socket; // Get client socket

	// Accept
	client_socket = accept(server_socket, NULL, NULL);
	
	// Send data
	send(client_socket, server_message, sizeof(server_message), 0);
	
	// Close socket 
	close(server_socket);

	return 0;
}
