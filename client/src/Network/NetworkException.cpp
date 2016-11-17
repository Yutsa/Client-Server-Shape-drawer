#include "NetworkException.hpp"

NetworkException::NetworkException(const string & message)
{
    _message = message;
}

extern ostream & operator<<(ostream & os, const NetworkException & networkException)
{
    os << "NetworkException => " << networkException._message;
    return os;
}