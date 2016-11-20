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
    
    /**
    * Casts RadianAngle to a string
    */
    operator string() const;
    
    /**
    * Sends a string of angle to a stream
    * @param os ostream
    * @param angle the angle to send 
    * @return ostream to send to output
    */
    friend ostream & operator<<(ostream & os, const RadianAngle & angle);
};

extern ostream & operator<<(ostream & os, const RadianAngle & angle);

/**
* Override function cos for RadianAngle
* @param angle RadianAngle have to calculate
*/
double cos(const RadianAngle & angle);

/**
* Override function sin for RadianAngle
* @param angle RadianAngle have to calculate
*/
double sin(const RadianAngle & angle);

#endif