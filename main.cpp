#include "Server.hpp"

int	main(void) {

	Server serv00;

	serv00.set_server();
	/*=======================================SET SERVER=====================================================*/
	//creer le socket et le stocker dans un tableau
	if (server_fd = socket(PF_INET, SOCK_STREAM, 0) == ERROR) {
		std::cerr << "error: socket creation" << std::endl;
		return(EXIT_FAILURE);
	}
	//set la structur sockaddr_in pour bind le server
	memset((char *)&address, 0, sizeof(address));
	address.sin_family = PF_INET;
	address.sin_port = htons(PORT);
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == ERROR) {
		std::cerr << "error: socket bind" << std::endl;
		return(EXIT_FAILURE);
	}
	//creer une structure pollfd pour y ajouter le socket du server
	struct pollfd fd;
	fd.fd = server_fd;
	fd.events = POLLIN;
	fds.push_back(fd);
	/*=======================================SERVER ROUTINE=====================================================*/
	int					new_socket;
	while (1) {
		if (poll(&fds[0], fds.size(), 0) != ERROR) {
			/*==========partie connection client==========*/
			if (fds[0].revents == POLLIN ) { //TODO:not sur
				//listen puis accept le nouveau client si POLLIN
				if (listen(server_fd, BUFF) == ERROR) { //ECONNREFUSED
					std::cerr << "error: socket listen" << std::endl;
					exit(EXIT_FAILURE);
				}
				if ((new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen)) == ERROR) {
					std::cerr << "error: socket accept" << std::endl;
					exit(EXIT_FAILURE);
				}
				else {
					//add_client
				}
			}
			/*==========partie requete client==========*/
			// for()
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
