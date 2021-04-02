#include "ClientTCP.h"

using namespace std;

ClientTCP::ClientTCP(string vIP, int port)
{
    this->serv_addr.sin_family = AF_INET;
    this->serv_addr.sin_port = htons(port);
    
    char* buffer = new char[1024];

    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    inet_pton(AF_INET, vIP.c_str() , &(this->serv_addr).sin_addr);
    
}

void ClientTCP::Connect(){
    connect(this->sock, (struct sockaddr *)&(this->serv_addr), sizeof(this->serv_addr));
    char a[1]{ ServerTCP::GET_FILE };
    send(this->sock ,a , 1, 0);
    receiveFile();
}

void ClientTCP::setTransferHandle(FileIOHandler* transferHandle){
    this->tranferHandle = transferHandle;
}

void ClientTCP::receiveFile(){
    int valread =1024;
    char buffer[1024];
    vector<char>* data;
    while (valread==1024){
        valread = recv(this->sock, buffer, 1024, 0);
        data = new vector<char>( buffer,buffer + valread);
        this->tranferHandle->setData(*data);
    }
}

ClientTCP::~ClientTCP()
{
}
