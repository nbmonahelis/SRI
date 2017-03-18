#include "TCPSocket.cpp"
#include "SRI.cpp"
#include "common.h"
class SRIClient{
	public:
	TCPSocket client;

	SRIClient();

	void lookInput();
	void loadFile(string fileName);

};

SRIClient::SRIClient(){
	client = new TCPSocket("0.0.0.0",9999,100);
}

void SRIClient::loadFile(string fileName){

	string input;
	fstream file;
	file.open(fileName.c_str(), fstream::in);
	cout<<"Opening: "<< fileName << endl;

	while(!file.EOF()){
	  getline(file,input);
	  if(input.size() == 0) break;
	}
	file.close();
}

void SRIClient::lookInput(){
	char* local = client.getRemoteAddress();
	TCPSocket* tcpServer = new TCPSocket(local,9999,100);

	int bytes = 1024;
	char buffer[bytes];
	buffer[0] = 'x';
	int readIn = tcpServer->writeToSocket(buffer, bytes);

    readIn =  tcpServer.readFromSocket(buffer, bytes);

}

int main(){
	SRIClient* mainClient = new Client();
	mainClient->lookInput();
}
