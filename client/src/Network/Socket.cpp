#include "Socket.hpp"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

const Socket* Socket::getInstance()
{
    if (_instance == NULL)
    {
        _instance = new Socket();
    }
    return _instance;
}

void createConnexion()
{
    cout << "Tapez l'adresse IP du serveur de dessin : " << endl;
    cin >> _serverAddress;
    cout << "Tapez le port du serveur de dessin : " << endl;
    cin >> _serverPort;

    /* Creation of the socket */
    _sock = socket(AF_INET, SOCK_STREAM, 0);
    if (_sock == -1)
    {
        perror("socket()");
        exit(errno);
    }
}
