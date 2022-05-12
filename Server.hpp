#ifndef SERVER_HPP
# define SERVER_HPP

class Server {
	public:
		Server(/* args */);
		Server(Server const &cpy);

		virtual ~Server();

		Server &operator=(Server const &ref);

		void	set_server();
	private:
};

#endif
