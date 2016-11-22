#ifndef NETWORK_EXCEPTION_H
#define NETWORK_EXCEPTION_H

#include <iostream>

using std::string;
using std::ostream;

/**
* Class for hander all network exceptions
*/
class ShapeLoaderException
{
private:
    string _message;

public:
    /**
    * Constructor of ShapeLoaderException
    * @param message the message to throw
    */
    ShapeLoaderException(const string & message);

    /**
    * Sends a string of excpetion to a stream
    * @param os ostream
    * @param ShapeLoaderException ShapeLoaderException have to print
    * @return ostream to send to the output
    */
    friend ostream & operator<<(ostream & os, const ShapeLoaderException & shapeLoaderException);
};

extern ostream & operator<<(ostream & os, const ShapeLoaderException & shapeLoaderException);

#endif
