#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <map>
#include "FileIOHandler.h"

using namespace std;


class ServerTCP
{
    enum ConOpts{
        GET_FILE='0',
        USE_CHAT='1'
    };
private:
    int port;
    int server_FD;
    FileIOHandler* tranferHandle;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    map<string, int> users;
public:
    ServerTCP(int port);
    void initServer();
    void setTransferHandle(FileIOHandler* transferFunction);
    void sendFile(int socket);
    ~ServerTCP();
};
