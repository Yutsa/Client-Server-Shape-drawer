#include <iostream>
#include <cmath>
#include "GeometryException.hpp"

using std::string;
using std::ostream;

/**
* Class represents an angle in radian
*/
class RadianAngle 
{
private:
    double _value;
    
public:
    /**
    * Constructor of the radian angle
    */
    RadianAngle(const double & value);
    
    /**
    * Sets the value before some verifications
    */
    void setValue(const double & value);
};