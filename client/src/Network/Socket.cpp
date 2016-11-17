#include "Socket.hpp"
#include "NetworkException.hpp"

using std::cout;
using std::cin;
using std::endl;


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
        cout << "Connexion au serveur effectuée à l'adresse " << _serverAddress << " et au port : " << _serverPort << endl;;
    }

}
