#include "RadianAngle.hpp"

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

double RadianAngle::getValue() const
{
    return _value;
}