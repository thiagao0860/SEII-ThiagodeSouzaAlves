#include "ServerTCP.h"

using namespace std;

ServerTCP::ServerTCP(int port)
{
    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons( port );
    this->port = port;
    int opt = 1;

    this->server_FD =socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(this->server_FD, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    bind(this->server_FD, (struct sockaddr *)&address, sizeof(address));
    
}

void ServerTCP::initServer(){
    listen(this->server_FD, 3);
    cout<<"listening on port "<<this->port<<endl;
    auto addrlen = sizeof(this->address);
    auto new_socket = accept(this->server_FD, (struct sockaddr *)&(this->address), (socklen_t*)&addrlen);
    int valread = recv( new_socket , buffer, 2*sizeof(char), 0);
    //cout<<buffer;
    switch (buffer[0])
    {
    case ServerTCP::ConOpts::GET_FILE:
        this->sendFile(new_socket);
        break;
    case ServerTCP::ConOpts::USE_CHAT:

        break;
    }
}

void ServerTCP::setTransferHandle(FileIOHandler* transferFunction){
    this->tranferHandle = transferFunction;
}

void ServerTCP::sendFile(int socket){
    char* a = this->tranferHandle->getData();
    send(socket , a , 1024*sizeof(char) , 0);
}

ServerTCP::~ServerTCP()
{
}