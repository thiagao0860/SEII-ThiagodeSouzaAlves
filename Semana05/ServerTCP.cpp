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
    char* received;
    while (true){
        auto new_socket = accept(this->server_FD, (struct sockaddr *)&(this->address), (socklen_t*)&addrlen);
        received = new char[1];
        int valread = recv( new_socket , received, 1, 0);
        if(received[0]==ServerTCP::USE_CHAT)
        {
            this->handler_threads.push_back(
            thread([this](int vSock){
                char buffer[1024];
                send(vSock , "wait",4,0);
                int valread_internal = recv(vSock , buffer,1024,0);
                string nome = string( buffer, valread_internal);
                this->users.insert(make_pair(nome,vSock));
                cout<<"user "<<nome<<" inserted"<<endl;
                cout.clear();
                valread_internal = recv(vSock , buffer,1024,0);
                string sendTo = string( buffer, valread_internal);
                cout<<"user "<<nome<<" envia para "<<sendTo<<endl;
                cout.clear();
                vector<char>* mes;
                while(true){
                    valread_internal=recv(vSock , buffer,1024,0);
                    mes= new vector<char>(buffer,buffer+valread_internal);
                    this->handler_threads.push_back(
                    thread([this](string _sendTo, vector<char> _message){
                         this->sendMessage(_sendTo,_message);
                    },sendTo,*mes));
                    delete mes;
                }
            },new_socket));
        }
        if(received[0]==ServerTCP::GET_FILE)
        {
            this->handler_threads.push_back(
            thread([this](int vSock){
                this->sendFile(vSock);
                cout<<"File sended to "<< vSock <<endl;
            },new_socket));
        }
        
        delete[] received;
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

void ServerTCP::sendMessage(string user, vector<char> message){
    int sock = (this->users.find(user))->second;
    send(sock , &message[0] , message.size() , 0);
}

ServerTCP::~ServerTCP()
{
    for (size_t i = 0; i < this->handler_threads.size(); i++)
    {
        this->handler_threads[i].join();
    }
      
}