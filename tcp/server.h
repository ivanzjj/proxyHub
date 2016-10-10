#ifndef __SERVER_H__
#define __SERVER_H__

#include "acceptor.h"

namespace proxyHub{

class Server{
public:
	Server (char *ip, int port);
	void start ();
	
private:
	Acceptor acceptor;
};
 
}//end of proxyHub
#endif
