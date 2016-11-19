#include "Shape.hpp"

Shape::Shape(Color color) : _color(color)
{

}

Shape::Shape() : _color(Color::getColor("black"))
{

}

void Shape::setColor(Color color)
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
