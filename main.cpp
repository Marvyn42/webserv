/*
- TCP Server side
    - socket
    - bind
	poll() {
    - listen
    - accept
    - send
    - recv
	}

	struct  pollfd
	{
	   int    fd;
	   short  events;
	   short  revents;
	};
*/

#include <cstdlib>
#include <vector>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <poll.h>

#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
#define SEND_ERROR -1
#define RECV_ERROR -1
#define POLL_ERROR -1
#define BUFF 10

int	main(void) {
	struct sockaddr_in	address;
	int					server_fd;
	int					new_socket;
	socklen_t			addrlen = sizeof(address);
	const int			PORT = 8080;
	std::vector<struct pollfd> fds;

	/*=======================================SET SERVER=====================================================*/
	if (server_fd = socket(PF_INET, SOCK_STREAM, 0) == INVALID_SOCKET) {
		std::cerr << "error: socket creation" << std::endl;
		return(EXIT_FAILURE);
	}
	memset((char *)&address, 0, sizeof(address));
	address.sin_family = PF_INET;
	address.sin_port = htons(PORT);
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == SOCKET_ERROR) {
		std::cerr << "error: socket bind" << std::endl;
		return(EXIT_FAILURE);
	}
	struct pollfd fd;
	fd.fd = server_fd;
	fd.events = POLLIN;
	fds.push_back(fd);
	/*=======================================SERVER ROUTINE=====================================================*/
	while (1) {
		if (poll(&fds[0], fds.size(), 0) != POLL_ERROR) {
			/*==========partie connection client==========*/
			if (fds[0].revents == POLLIN ) {
				//listen puis accept le nouveau client si POLLIN
				if (listen(server_fd, BUFF) == -1) { //ECONNREFUSED
					std::cerr << "error: socket listen" << std::endl;
					exit(EXIT_FAILURE);
				}
				if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) == INVALID_SOCKET) {
					std::cerr << "error: socket accept" << std::endl;
					exit(EXIT_FAILURE);
				}
				else {
					//add_client
				}
			}
			/*==========partie requete client==========*/
				//iter sur la liste des client pour une action en fonction des signaux sortant:
					//client recois
					//client envoi
					//client se deco
			// if(send(new_socket, buffer, strlen(buffer), 0) == SEND_ERROR) {
				// std::cerr << "error: send data" << std::endl;
				// exit(EXIT_FAILURE);
			// }
			// if((n = recv(new_socket, buffer, sizeof buffer - 1, 0)) == RECV_ERROR) {
				// std::cerr << "error: receive data" << std::endl;
				// exit(EXIT_FAILURE);
			// }
		}
		usleep(100);
	}
	/*============================================================================================*/
	return(EXIT_SUCCESS);
}
