#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "ServerTCP.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc<3){
        cout<<"wrong args"<<endl;
        return 1;
    }
    int port;
    try{
    string s = argv[1];
    istringstream(s) >> port;
    }catch(exception e){
        cout<<"invalid port"<<endl;    
        return 1;
    }
    FileIOHandler* file = new FileIOHandler(argv[2]);
    try{
     ServerTCP server = ServerTCP(port);
     server.setTransferHandle(file);
     server.initServer();
    }
    catch(exception e)
    {
        cout<< e.what() <<endl;
        return -1;
    }
    return 0;
}