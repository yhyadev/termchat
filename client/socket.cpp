#include "main.h"

#include "socket.h"

#include <cstdio>
#include <cstdlib>
#include <curses.h>
#include <stdlib.h>

#include <arpa/inet.h>
#include <string>
#include <sys/socket.h>

int connect_to_socket() {
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) {
		printf("Socket creation failed");
		exit(1);
	}

	struct sockaddr_in socket_address;

	socket_address.sin_family = AF_INET;
	socket_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	socket_address.sin_port = htons(8080);

	if (connect(sockfd, (const struct sockaddr *)&socket_address,
				sizeof(socket_address)) != 0) {
		printf("Connecting to the socket failed");
		exit(1);
	}

	return sockfd;
}

void recieve_message(RegularArgs *args) {
    char buffer[1024];

    WINDOW *messages_win = newwin(LINES - 5, 0, 1, 1);

	while (true) {
		int status = recv(args->sockfd, buffer, 1024, 0);

		if (status == -1) {
			printf("Cannot receive messages");
			exit(1);
		} else if (status == 0) {
			printf("Server closed");
			exit(1);
		} else {
            waddstr(messages_win, buffer);
            wrefresh(messages_win);
		}
        
        napms(100);
	}
}

void send_message(RegularArgs *args, std::string message) {
	if (send(args->sockfd, message.c_str(), message.length(), 0) == -1) {
		printf("Cannot send message");
		exit(1);
	}
}
