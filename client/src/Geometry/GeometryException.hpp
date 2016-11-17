#include <iostream>

using std::string;
using std::ostream;

class GeometryException 
{
private:
    string _message;
    
public:
    GeometryException(const string & message);
    
    friend ostream & operator<<(ostream & os, const GeometryException & geometryException);
};

extern ostream & operator<<(ostream & os, const GeometryException & geometryException);
