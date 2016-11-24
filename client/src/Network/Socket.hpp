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

/**
* The singleton that will encapsulate the socket to communicate with
* the drawing server.
*/
class Socket
{
private:
    /**
    * The instance of the Socket singleton.
    */
    static Socket* _instance;

    /**
    * The adress of the drawing server.
    */
    static string _serverAddress;

    /**
    * The port of the drawing server.
    */
    static int _serverPort;

    /**
    * The socket to the drawing server.
    */
    static int _sock;

    /**
    * The IP address of the drawing server
    */
    static sockaddr_in _socketAddress;

    /*
    * The private constructor to be sure that there'll be only one
    * instance of the socket singleton.
    */
    Socket();

public:
    /**
    * Creates the Socket if it hasn't been created yet, otherwise
    * returns a pointer to the instance of the Socket.
    * @return Socket* A pointer to the instance of the Socket.
    */
    static const Socket* getInstance();

    /**
    * Creates the connexion to the server.
    * @throws NetworkException When the socket can't be created or when server connexion can't be open
    */
    static void createConnexion();

    /**
    * Sends the request to the server.
    * @throws NetworkException when message cannot be send
    */
    static void sendRequest(const string & request);

    /**
    * Receives a message from the server and returns it.
    * @throws NetworkException When message from server cannot be load
    * @return string The message received from the server.
    */
    static string receiveData();

    /**
    * Closes the socket
    * @throws NetworkException When close function fails
    */
    static void closeSocket();
};

#endif
