#include "Shape.hpp"
#include <iostream>

Shape::Shape(const Color & color) : _color(color)
{

}

void Shape::setColor(const Color & color)
{
    _color = color;
}

Color Shape::getColor() const
{
    return _color;
}

ostream & operator << (ostream & os, const Shape & shape)
{
    os << (string) shape;
    return os;
}
