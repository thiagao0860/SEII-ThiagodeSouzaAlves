#pragma once
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "FileIOHandler.h"
#include "ServerTCP.h"
#include <cstring>

class ClientTCP
{
private:
    int port;
    int sock;
    FileIOHandler* tranferHandle;
    struct sockaddr_in serv_addr;

public:
    ClientTCP(std::string vIP, int port);
    void Connect();
    void setTransferHandle(FileIOHandler* transferFunction);
    void receiveFile();
    void useChat(std::string name);
    ~ClientTCP();
};