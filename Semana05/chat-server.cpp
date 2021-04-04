#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "ServerTCP.h"
#include "FileIOHandler.h"

using namespace std;

int main(int argc, char** argv)
{
    if(argc<2){
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
    try{
     ServerTCP server(port);
     server.initServer();
    }
    catch(exception e)
    {
        cout<< e.what() <<endl;
        return -1;
    }

    return 0;
}