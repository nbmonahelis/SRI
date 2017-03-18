#include "TCPServerSocket.h"
#include "GarbageCollector.h"
#include "Connection.h"
#include "SRI.h"

int main(int argc, char** argv) {
	
    TCPServerSocket * tcp = new TCPServerSocket("127.0.0.1",9999,100);	
    GarbageCollector * gC = new GarbageCollector();


	tcp->initializeSocket();

	while (true) {

//if timeoutSec and timeoutMilli are zeros the method will behave in a blocking mode
        TCPSocket * tcpSocket = tcp->getConnection(0,0,-1,-1);

		if (tcpSocket == NULL) break; //otherwise won't work

		gC->cleanup(); // call cleanUp

		Connection * connection = new Connection (tcpSocket); // new instance of connection object

		connection->start();

		gC->addConnection(connection);
	}

    delete(gC);
	delete(tcp);

	return(0);
}
