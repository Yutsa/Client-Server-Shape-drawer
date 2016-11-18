#ifndef RADIAN_ANGLE_H
#define RADIAN_ANGLE_H

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
    * @param value value of angle : 0 < value < 2*PI
    */
    RadianAngle(const double & value);
    
    /**
    * Sets the value before some verifications
    * @param value
    */
    void setValue(const double & value);
    
    /**
    * Gets the angle's value 
    * @return value
    */
    double getValue() const;
};

double cos(const RadianAngle & angle);
double sin(const RadianAngle & angle);

#endif