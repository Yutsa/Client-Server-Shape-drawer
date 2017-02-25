#ifndef GEOMETRY_EXCEPTION_H
#define GEOMETRY_EXCEPTION_H

#include <iostream>

using std::string;
using std::ostream;

/**
* Class for hander all geometrique exceptions
*/
class GeometryException 
{
private:
    string _message;
    
public:
    /**
    * Constructor of GeometryException
    * @param message the message to throw
    */
    GeometryException(const string & message);
    
    /**
    * Sends a string of excpetion to a stream
    * @param os ostream 
    * @param geometryException GeometryException have to print 
    * @return ostream to send to the output
    */
    friend ostream & operator<<(ostream & os, const GeometryException & geometryException);
};

extern ostream & operator<<(ostream & os, const GeometryException & geometryException);

#endif