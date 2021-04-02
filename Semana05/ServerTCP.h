#pragma once
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <map>
#include <vector>
#include "FileIOHandler.h"

using namespace std;


class ServerTCP
{
private:
    int port;
    int server_FD;
    FileIOHandler* tranferHandle;
    struct sockaddr_in address;
    map<string, int> users;

public:
    enum ConOpts{
        GET_FILE='0',
        USE_CHAT='1'
    };
    ServerTCP(int port);
    void initServer();
    void setTransferHandle(FileIOHandler* transferFunction);
    void sendFile(int socket);
    ~ServerTCP();
};
