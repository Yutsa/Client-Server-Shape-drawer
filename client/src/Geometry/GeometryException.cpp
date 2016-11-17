#include "GeometryException.hpp"

GeometryException::GeometryException(const string & message)
{
    _message = message;
}

extern ostream & operator<<(ostream & os, const GeometryException & geometryException)
{
    os << "GeometryException => " << geometryException._message;
    return os;
}