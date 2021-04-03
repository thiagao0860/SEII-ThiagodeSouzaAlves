#pragma once
#include <string>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <map>
#include <thread>
#include <vector>
#include "FileIOHandler.h"



class ServerTCP
{
private:
    int port;
    int server_FD;
    std::vector<std::thread> handler_threads; 
    FileIOHandler* tranferHandle;
    struct sockaddr_in address;

public:
    std::map<std::string, int> users;
    enum ConOpts{
        GET_FILE=0,
        USE_CHAT=1
    };
    ServerTCP(int port);
    void initServer();
    void setTransferHandle(FileIOHandler* transferFunction);
    void sendFile(int socket);
    ~ServerTCP();
};
