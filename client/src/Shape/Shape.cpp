#include "Shape.hpp"

Shape::Shape(const Color & color) : _color(color)
{

}

void Shape::setColor(const Color & color)
{
    _color = color;
}

Color Shape::getColor()
{
    return _color;
}

ostream & operator << (ostream & os, const Shape & shape)
{
    os << (string) shape;
    return os;
}
