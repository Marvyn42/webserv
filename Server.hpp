#ifndef SERVER_HPP
# define SERVER_HPP

#include "header.h"

class Server {
	public:
		Server(/* args */);
		Server(Server const &cpy);

		Server &operator=(Server const &ref);

		bool	set_server();

	private:
		int							_server_fd;
		std::vector<struct pollfd>	_fds;
		struct sockaddr_in			_address;
		socklen_t					_addrlen;
		const int					_PORT = 8080;

		virtual ~Server();

		bool	set_socket();
		bool	set_struct();

};

#endif
