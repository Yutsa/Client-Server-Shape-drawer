#include "Socket.hpp"
#include "NetworkException.hpp"
#include <vector>
#include <string.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

Socket::Socket()
{

}

const Socket* Socket::getInstance()
{
    if (_instance == NULL)
    {
        _instance = new Socket();
    }
    return _instance;
}

void Socket::createConnexion()
{
    cout << "Tapez l'adresse IP du serveur de dessin : " << endl;
    cin >> _serverAddress;
    cout << "Tapez le port du serveur de dessin : " << endl;
    cin >> _serverPort;

    /* Initialisation of socket address */
    _socketAddress.sin_family = AF_INET;
    _socketAddress.sin_addr.s_addr = inet_addr(_serverAddress.c_str());
    _socketAddress.sin_port = htons(_serverPort);

    /* Creation of the socket */
    _sock = socket(AF_INET, SOCK_STREAM, 0);
    if (_sock == -1)
    {
        throw NetworkException("Erreur création socket.");
    }

    /* Connexion to server */
    int res;
    res = connect(_sock, (sockaddr*) &_socketAddress, sizeof(_socketAddress));

    if (res == -1)
    {
        throw NetworkException("Erreur de connexion au server.");
    }
    else
    {
        cout << "Connexion au serveur effectuée à l'adresse " << _serverAddress << " et au port : " << _serverPort << endl;
    }
}

void Socket::sendRequest(const string & request)
{
    if (send(_sock, request.c_str(), strlen(request.c_str()), 0) == -1)
    {
        throw NetworkException("L'envoie a échoué.");
    }
}

string Socket::receiveData()
{
    const unsigned int MAX_BUF_LENGTH = 4096;
    vector<char> buffer(MAX_BUF_LENGTH);
    string rcv;
    int bytesReceived = 0;
    do {
        bytesReceived = recv(_sock, buffer.data(), buffer.size(), 0);
        // append string from buffer.
        if ( bytesReceived == -1 ) {
            throw NetworkException("Erreur dans la réception du message du server.");
        } else {
            // Could use cbegin cend if using C++11
            rcv.append( buffer.begin(), buffer.end() );
        }
    } while ( bytesReceived == MAX_BUF_LENGTH );
    return rcv;
}

void Socket::closeSocket()
{
    if (close(_sock) == -1)
    {
        throw NetworkException("Erreur de fermeture du socket");
    }
    cout << "Socket fermé." << endl;
}

Socket* Socket::_instance = NULL;

/**
* The adress of the drawing server.
*/
string Socket::_serverAddress;

/**
* The port of the drawing server.
*/
int Socket::_serverPort;

/**
* The socket to the drawing server.
*/
int Socket::_sock;

/**
* The IP address of the drawing server
*/
sockaddr_in Socket::_socketAddress;
