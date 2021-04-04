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
}

void ClientTCP::setTransferHandle(FileIOHandler* transferHandle){
    this->tranferHandle = transferHandle;
}

void ClientTCP::receiveFile(){
    char a[1]{ ServerTCP::GET_FILE};
    send(this->sock ,a , 1, 0);
    int valread =1024;
    char buffer[1024];
    vector<char>* data;
    while (valread==1024){
        valread = recv(this->sock, buffer, 1024, 0);
        data = new vector<char>( buffer,buffer + valread);
        this->tranferHandle->setData(*data);
    }
}

void ClientTCP::useChat(string name){
   char a[1]{ ServerTCP::USE_CHAT};
    char buffer[4];
    send(this->sock ,a , 1, 0);
    recv(this->sock,buffer,4,0);
    send(this->sock ,name.c_str() , name.length(), 0);
    string sendto;
    cout<<"Connected as "<<name<<" welcome."<<endl;
    cout<<"Send to: ";
    cout.clear();
    cin>>sendto;
    send(this->sock, sendto.c_str(), sendto.length(),0);
    thread t1([this](int _sock){
            cout<<"type your message: ";
       while(true){
            string message;
            getline( cin, message );
            send(_sock, message.c_str(), message.length(),0);
       }
    },this->sock);
    thread t2([this](int sock){
       string received;
       while(true){
            char intr[1024];
            auto readedi=recv(this->sock,intr,1024,0);
            received = string(intr,readedi);
            cout<<"\nreceived: \""<<received<<"\""<<endl;
            cout.clear();
       } 
    },this->sock);
    t1.join();
    t2.join();
}

ClientTCP::~ClientTCP()
{
}
