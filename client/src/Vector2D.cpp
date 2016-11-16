#include "Vector2D.hpp"

Vector2D::Vector2D(double x, double y)
{
    //TODO: Check if x and y can be < 0 or not.
    _x = x;
    _y = y;
}

Vector2D::~Vector2D()
{
    // Destructor
}

const Vector2D operator+ (const Vector2D & lhv, const Vector2D & rhv)
{
    return Vector2D(lhv.getX() + rhv.getX(), lhv.getY() + rhv.getY());
}
