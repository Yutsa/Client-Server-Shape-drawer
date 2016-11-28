#include "RadianAngle.hpp"

#include <sstream>
#include <iostream>
#include <math.h>

using std::ostringstream;

RadianAngle::RadianAngle(const double & value)
{
    setValue(value);
}

void RadianAngle::setValue(const double & value)
{
    if (value < 0 || value > 2*M_PI)
    {
        _value = fmod(value, 2*M_PI);
    }

    _value = value;
}

RadianAngle::operator string() const
{
    ostringstream os;
    os << _value;
    return os.str();
}

ostream & operator<<(ostream & os, const RadianAngle & angle)
{
    os << (string) angle;
    return os;
}

const RadianAngle RadianAngle::operator+ (const RadianAngle & angle) const
{
    return RadianAngle(fmod(_value+angle.getValue(), 2*M_PI));
}

const RadianAngle RadianAngle::operator+ (const double & a) const
{
    return RadianAngle(fmod(_value+a, 2*M_PI));
}

const RadianAngle & RadianAngle::operator+= (const RadianAngle & angle)
{
    _value = fmod(_value+angle.getValue(), 2*M_PI);
    return *this;
}

const RadianAngle & RadianAngle::operator+= (const double & a)
{
    _value = fmod(_value+a, 2*M_PI);
    return *this;
}
    
const RadianAngle RadianAngle::operator* (const double & a) const
{
    return RadianAngle(fmod(_value*a, 2*M_PI));
}

const RadianAngle & RadianAngle::operator*= (const double & a)
{
    _value = fmod(_value+a, 2*M_PI);
    return *this;
}

const RadianAngle RadianAngle::operator- () const
{
    return RadianAngle(fmod(-_value, 2*M_PI));
}

const RadianAngle RadianAngle::operator- (const RadianAngle & angle) const
{
    return RadianAngle(fmod(_value - angle.getValue(), 2*M_PI));
}

const RadianAngle RadianAngle::operator- (const double & a) const
{
    return RadianAngle(fmod(_value - a, 2*M_PI));
}

const RadianAngle & RadianAngle::operator-= (const RadianAngle & angle)
{
    _value = fmod(_value + angle.getValue(), 2*M_PI);
    return *this;
}

const RadianAngle & RadianAngle::operator-= (const double & a)
{
    _value = fmod(_value + a, 2*M_PI);
    return *this;
}

const RadianAngle RadianAngle::operator/ (const double & a) const
{
    return RadianAngle(fmod(_value / a, 2*M_PI));
}

double RadianAngle::getValue() const
{
    return _value;
}

double cos(const RadianAngle & angle)
{
    return cos(angle.getValue());
}

double sin(const RadianAngle & angle)
{
    return sin(angle.getValue());
}