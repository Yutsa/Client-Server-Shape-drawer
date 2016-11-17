#include "Vector2D.hpp"
#include <sstream>

using std::ostringstream;

Vector2D::Vector2D(const double & x, const double & y) : _x(x), _y(y)
{
    
}

Vector2D::~Vector2D()
{
    // Destructor
}

const Vector2D Vector2D::operator+ (const Vector2D & rhv) const
{
    return Vector2D(_x + rhv.getX(), _y + rhv.getY());
}

const Vector2D Vector2D::operator* (const double & a) const
{
    return Vector2D(_x * a, _y * a);
}

const Vector2D Vector2D::operator- () const
{
    return Vector2D(- _x, - _y);
}

const Vector2D operator*(const double & a, const Vector2D & vector)
{
    return vector * a;
}

Vector2D::operator string() const
{
    ostringstream os;
    os << "(" << _x << ", " << _y << ")";
    return os.str();
}

ostream & operator<<(ostream & os, const Vector2D & vector)
{
    os << (string) vector;
    return os;
}
