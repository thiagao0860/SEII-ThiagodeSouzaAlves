#include <iostream>
#include <sstream>
#include <fstream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string>
#include "FileIOHandler.h"
#include "ClientTCP.h"

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
    try{
    ClientTCP client(argv[1],port);
    client.Connect();
    client.useChat(argv[3]);
    }catch (exception e){
        cout<< e.what() <<endl;
        return -1;
    }
    return 0;
}