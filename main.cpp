/*
- TCP Server side
    - socket
    - bind
    - listen
    - accept
    - send
    - recv

	struct  pollfd
	{
	   int    fd;
	   short  events;
	   short  revents;
	};
*/

#include <cstdlib>
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

int	main(void) {
	//stocker dans struct ? class ?
	struct sockaddr_in	address;
	int					server_fd;
	int					new_socket;
	socklen_t			addrlen = sizeof(address);
	const int			PORT = 8080;
	struct pollfd		fd[1];
	//
	//parsing?

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
	//debut boucle pool ? pool simple ? POLLNVAL
	if (poll(fd, 1,  100) == POLL_ERROR)
		// ???
	if (listen(server_fd, 2) == -1) {
		std::cerr << "error: socket listen" << std::endl;
		exit(EXIT_FAILURE);
	}
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) == INVALID_SOCKET) {
		std::cerr << "error: socket accept" << std::endl;
		exit(EXIT_FAILURE);
	}
	//-------------------------------
	//	Switch en fonction du signal ?
	switch(poll(fd, 1,  100)) {
		case POLL_ERROR:
			std::cerr << "error: poll" << std::endl;
			return(EXIT_FAILURE);
		case 0:
	}
	//-------------------------------
	if (poll( struct pollfd fds[],  nfds_t nfds,  int n_msec ))
		//
	//-------------------------------
	if(send(new_socket, buffer, strlen(buffer), 0) == SEND_ERROR) {
		std::cerr << "error: send data" << std::endl;
		exit(EXIT_FAILURE);
	}
	if((n = recv(new_socket, buffer, sizeof buffer - 1, 0)) == RECV_ERROR) {
		std::cerr << "error: receive data" << std::endl;
		exit(EXIT_FAILURE);
	}
	buffer[n] = '\0';
	return(EXIT_SUCCESS);
}
