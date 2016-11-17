#ifndef SOCKET_H
#define SOCKET_H

#include <iostream>

using std::string;
using std::sockaddr_in;

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
