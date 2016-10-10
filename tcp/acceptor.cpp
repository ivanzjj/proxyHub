#include "acceptor.h"

namespace proxyHub{
Acceptor::Acceptor (Server *s, char *ip, int port)
	:server_ (s), sock_ (ip, port){	
}
int Acceptor::startListen (){
	return sock_.createServerSocket ();
}
	
}//end of namespace
