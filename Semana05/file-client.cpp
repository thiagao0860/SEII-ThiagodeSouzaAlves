#include <iostream>
#include <sstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>

using namespace std;
   
int main(int argc, char** argv)
{
    if(argc<4){
        cout<<"wrong args"<<endl;
        return 1;
    }
    int port;
    string IP_ad = argv[1];
    try{
    string s1 = argv[2];
    istringstream(s1) >> port;
    }catch(exception e){
        cout<<"invalid port"<<endl;    
        return 1;
    }

    int sock = 0, valread=1024;
    struct sockaddr_in serv_addr;
    string hello = "Hello from client";
    char* buffer = new char[1024];

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
   
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
       
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, IP_ad.c_str() , &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock , "0" , 2, 0);
    while (valread==1024){
        valread = recv(sock, buffer, 1024, 0);
        cout<<buffer<<endl;
    }
    return 0;
}