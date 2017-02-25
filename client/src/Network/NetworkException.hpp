#ifndef NETWORK_EXCEPTION_H
#define NETWORK_EXCEPTION_H

#include <iostream>

using std::string;
using std::ostream;

/**
* Class for hander all network exceptions
*/
class NetworkException
{
private:
    string _message;

public:
    /**
    * Constructor of NetworkException
    * @param message the message to throw
    */
    NetworkException(const string & message);

    /**
    * Sends a string of excpetion to a stream
    * @param os ostream
    * @param NetworkException NetworkException have to print
    * @return ostream to send to the output
    */
    friend ostream & operator<<(ostream & os, const NetworkException & networkException);
};

extern ostream & operator<<(ostream & os, const NetworkException & networkException);

#endif
