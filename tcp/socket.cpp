#include "socket.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>

namespace proxyHub{
	
Socket::Socket (char *ip, int port)
	:ip_ (ip), port_ (port), fd_ (-1) {
}

int Socket::createServerSocket (){
	struct sockaddr_in addr;
	if ((fd_ = socket (AF_INET, SOCK_STREAM, 0)) == -1){
		printf ("create server socket failed.\n");
		return -1;
	}
	setReuse (1);
	setNonblocking (1);
	
	memset (&addr, 0, sizeof (addr));
	addr.sin_family = AF_INET;
	if (inet_aton (ip_.c_str (), &addr.sin_addr) != 0){
		printf ("conver dot-number ip to in_addr ip failed.\n");
		return -1;
	}
	addr.sin_port = htons (port_);
	if (bind (fd_, (struct sockaddr *)&addr, sizeof (addr)) == -1){
		printf ("bind socket error.\n");
		return -1;
	}
	if (listen (fd_, MAX_LISTEN_SOCKET) == -1){
		printf ("listen socket failed.\n");
		return -1;
	}
	return 0;
}

int Socket::setReuse (int enable){
	if (setsockopt (fd_, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof (enable)) < 0){
		printf ("setsockopt failed.\n");
		return -1;
	}
	return 0;
}
int Socket::setNonblocking (int enable){
	int flags = fcntl (fd_, F_GETFL, 0);
	flags = enable == 1 ? (flags & O_NONBLOCK): (flags & ~O_NONBLOCK);
	return fcntl (fd_, F_SETFL, flags);
}	
	
}//end of namespace
