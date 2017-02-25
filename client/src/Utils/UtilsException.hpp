#ifndef UTILS_EXCEPTION_H
#define UTILS_EXCEPTION_H

#include <iostream>

using std::string;
using std::ostream;

/**
* Class for hander all utils exceptions
*/
class UtilsException 
{
private:
    string _message;
    
public:
    /**
    * Constructor of UtilsException
    * @param message the message to throw
    */
    UtilsException(const string & message);
    
    /**
    * Sends a string of excpetion to a stream
    * @param os ostream 
    * @param utilsException utilsException have to print 
    * @return ostream to send to the output
    */
    friend ostream & operator<<(ostream & os, const UtilsException & utilsException);
};

extern ostream & operator<<(ostream & os, const UtilsException & utilsException);

#endif