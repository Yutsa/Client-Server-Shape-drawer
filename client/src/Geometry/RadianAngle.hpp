#ifndef RADIAN_ANGLE_H
#define RADIAN_ANGLE_H

#include <iosfwd>
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
    * @param value value of angle
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
    
    /**
    * Allows to add two RadianAngle
    * @param angle RadianAngle to add
    * @return RadianAngle which is the result of addition
    */
    const RadianAngle operator+ (const RadianAngle & angle) const;
    
    /**
    * Allows to add RadianAngle and double
    * @param a double to add
    * @return RadianAngle which is the result of addition
    */
    const RadianAngle operator+ (const double & a) const;
    
    const RadianAngle & operator+= (const RadianAngle & angle);
    const RadianAngle & operator+= (const double & a);

    /**
    * Allows to multiply a angle by a double
    * @param a double to multiply
    * @return RadianAngle which is the result of product
    */
    const RadianAngle operator* (const double & a) const;
    
    const RadianAngle & operator*= (const double & a);

    /**
    * Gets the opposite of a RadianAngle
    * @return RadianAngle
    */
    const RadianAngle operator- () const;
    
    /**
    * Allows to substract two RadianAngle
    * @param angle RadianAngle to sub
    * @return RadianAngle which is the result of substraction
    */
    const RadianAngle operator- (const RadianAngle & angle) const;
    
    /**
    * Allows to substract two RadianAngle
    * @param a double to sub
    * @return RadianAngle which is the result of substraction
    */
    const RadianAngle operator- (const double & a) const;
    
    const RadianAngle & operator-= (const RadianAngle & angle);
    const RadianAngle & operator-= (const double & a);
    
    /**
    * Allows to divide RadianAngle and double
    * @param a double to divide
    * @return RadianAngle which is the result of division
    */
    const RadianAngle operator/ (const double & a) const;
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