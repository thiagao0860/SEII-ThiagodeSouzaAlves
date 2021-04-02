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
    char* received = new char[2];
    int valread = recv( new_socket , received, 2, 0);
    //cout<<buffer;
    switch (received[0])
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
    vector<char> a;
    while((a = this->tranferHandle->getData()).size()>0){
        send(socket , &a[0] , a.size() , 0);
    }
}

ServerTCP::~ServerTCP()
{
}