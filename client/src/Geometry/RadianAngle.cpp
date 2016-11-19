#include "RadianAngle.hpp"

#include <sstream>

using std::ostringstream;

RadianAngle::RadianAngle(const double & value)
{
    setValue(value);
}

void RadianAngle::setValue(const double & value)
{
    if (value < 0 || value > 2*M_PI)
    {
        throw new GeometryException("Angle invalide");
    }
    else
    {
        _value = value;
    }
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