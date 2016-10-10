#ifndef __ACCEPTOR_H__
#define __ACCEPTOR_H__

#include "socket.h"

namespace proxyHub{

class Server;
	
class Acceptor{
public:
	Acceptor (Server *s, char *ip, int port);

	int startListen ();
private:
	Server *server_;
	Socket sock_;
};
 
}//end of namespace

#endif
