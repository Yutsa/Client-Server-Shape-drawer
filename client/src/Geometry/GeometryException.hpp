#include <iostream>

using std::string;
using std::ostream;

class GeometryException 
{
private:
    string _message;
    
public:
    GeometryException(const string & message);
    
    ostream & operator<<(ostream & os);
};
