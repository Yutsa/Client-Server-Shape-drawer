#include "UtilsException.hpp"

UtilsException::UtilsException(const string & message)
{
    _message = message;
}

extern ostream & operator<<(ostream & os, const UtilsException & utilsException)
{
    os << "UtilsException => " << utilsException._message;
    return os;
}