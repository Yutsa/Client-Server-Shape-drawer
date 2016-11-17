#include "GeometryException.hpp"

GeometryException::GeometryException(const string & message)
{
    _message = message;
}

ostream & GeometryException::operator<<(ostream & os)
{
    os << "GeometryException => " << _message;
    return os;
}