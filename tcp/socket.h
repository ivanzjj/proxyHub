#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <string>

namespace proxyHub{

#define MAX_LISTEN_SOCKET 1024
	
class Socket {
public:
	Socket (char *ip, int port);

	int createServerSocket ();

private:
	int setReuse (int enable);
	int setNonblocking (int enable);

private:
	std::string ip_;
	int port_;
	int fd_;
};
	
}//end of namespace

#endif
