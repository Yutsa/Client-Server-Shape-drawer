#ifndef SOCKET_H
#define SOCKET_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

using std::string;

class Socket
{
private:
    static Socket* _instance = NULL;
    static string _serverAddress;
    static int _serverPort;
    static int _sock;
    static sockaddr_in _socketAddress;

    Socket();

public:
    static const Socket* getInstance();
    static void createConnexion();
};

#endif
