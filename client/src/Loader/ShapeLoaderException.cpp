#include "ShapeLoaderException.hpp"

ShapeLoaderException::ShapeLoaderException(const string & message)
{
    _message = message;
}

extern ostream & operator<<(ostream & os, const ShapeLoaderException & ShapeLoaderException)
{
    os << "ShapeLoaderException => " << ShapeLoaderException._message;
    return os;
}
