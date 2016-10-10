#include "server.h"

namespace proxyHub{

Server::Server (char *ip, int port)
	:acceptor (this, ip, port){
}

void Server::start (){
	if (0 != acceptor.startListen ()){
		printf ("server start failed.\n");
		return;
	}
}
}//end of namespace proxyHub
