#include "Vector2D.hpp"
#include <sstream>
#include <iostream>

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

const Vector2D & Vector2D::operator+= (const Vector2D & rhs)
{
    _x += rhs.getX();
    _y += rhs.getY();
    
    return *this;
}

const Vector2D Vector2D::operator* (const double & a) const
{
    return Vector2D(_x * a, _y * a);
}

const Vector2D & Vector2D::operator*= (const double & a)
{
    _x *= a;
    _y *= a;
    
    return *this;
}

const Vector2D Vector2D::operator- () const
{
    return Vector2D(- _x, - _y);
}

const Vector2D Vector2D::operator- (const Vector2D & rhv) const
{
    return Vector2D(_x - rhv.getX(), _y - rhv.getY());
}

const Vector2D & Vector2D::operator-= (const Vector2D & rhs)
{
    _x -= rhs.getX();
    _y -= rhs.getY();
    
    return *this;
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

void Vector2D::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio)
{
    /* Creation of the homothety Vector */
    Vector2D homothetyVector;
    homothetyVector = *this - invariantPoint;

    /* Homothety application */
    *this += homothetyVector*homothetyRatio;

}

void Vector2D::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle)
{
    //TODO
//A'.x = A.x * cos(θ) - A.y * sin(θ)
//
//A'.y = A.x * sin(θ) + A.y * cos(θ)
    
    /* Makes rotation of vector2D */
    double x = ((_x - rotationCenter.getX()) * cos(rotationAngle)) 
             - ((_y - rotationCenter.getY()) * sin(rotationAngle));
    double y = ((_x - rotationCenter.getX()) * sin(rotationAngle)) 
             + ((_y - rotationCenter.getY()) * cos(rotationAngle));
    
    /* Translation for set rotation in function of center */
    _x = x + rotationCenter.getX();
    _y = y + rotationCenter.getY();
}

const Vector2D Vector2D::rotation(
    const RadianAngle & rotationAngle)
{
    //TODO
//A'.x = A.x * cos(θ) - A.y * sin(θ)
//
//A'.y = A.x * sin(θ) + A.y * cos(θ)
    
    /* Makes rotation of vector2D */
    sinR = sin(rotationAngle);
    cosR = cos(rotationAngle);
    double x = _x * cosR - _y  * sinR;
    double y = _x  * sinR + _y  * cosR;

    return Vector2D(x, y);
}

const Vector2D Vector2D::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle)
{
    return rotationCenter + (*this - rotationCenter).rotation(rotationAngle);
}

void Vector2D::translation(const Vector2D & translationVector)
{
    *this += translationVector;
}
