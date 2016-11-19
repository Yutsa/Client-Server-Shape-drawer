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