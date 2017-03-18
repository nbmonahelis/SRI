#include "common.h"
#include "includes.h"
#include "TCPSocket.cpp"
#include "TCPServerSocket.cpp"
#include "SRI.cpp"
#include "KnowledgeBase.cpp"
#include "RuleBase.cpp"
#include "Parser.cpp"
#include "Threads.cpp"
#define BUFFER_SIZE = 1024;

class TCPServer{
    public:
        TCPServerSocket tcpServer;
        //map<int, SRI> serverMap;
        TCPServer(const char* serv_address, int port, int log);

        void start();

};

TCPServer::TCPServer(const char* serv_address, int port, int log)
{
    tcpServer  = TCPServerSocket(serv_address, port, log);
}

void TCPServer::start()
{
    tcpServer = TCPServerSocket("0.0.0.0",9999,100);
    tcpServer.intializeSocket();

    for(;;){
        TCPSocket *socket = tcpServer.getConnection();
        if(socket == NULL)
            break;
        int bytes = 1024;
        char buffer[BUFFER_SIZE];

        memset(buffer,0,bytes);

        int br = socket->readFromSocket(buffer, bytes);
        //cout<<buffer;

        if(buffer[0] == 'x')buffer[0] = 'y';
        int send = socket->writeToSocket(buffer, bytes);
        //cout<<buffer;
        socket->shutDown();
    }
}

int main()
{
    TCPServer *server = new TCPServer("0.0.0.0",9999,100);
    server->start();
}

