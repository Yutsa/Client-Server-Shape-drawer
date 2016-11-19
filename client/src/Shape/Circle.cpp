#include "Circle.hpp"
#include <cmath>
#include <sstream>

using std::ostringstream;

Circle::Circle(Vector2D center, double diameter, Color color) : Shape(color)
{
    _center.setX(center.getX());
    _center.setY(center.getY());
    _diameter=diameter;
}

Circle::Circle(Vector2D center, double diameter) : Shape()
{
    _center.setX(center.getX());
    _center.setY(center.getY());
    _diameter=diameter;
}

void Circle::draw(const DrawingVisitor* visitor) const
{
    visitor->draw(this);
}

Circle::operator string() const
{
    ostringstream os;
    os << "circle," << _color << "," << _center.getX() << "," << _center.getY() << "," << _diameter;
    return os.str();
}

void Circle::save(const SaveVisitor* saveVisitor, const string & filename) const
{
    saveVisitor->save(this, filename);
}

Shape* Circle::translation(const Vector2D & translationVector) const
{
    Circle *newCircle = new Circle(*this);
    newCircle->_center.translation(translationVector);
    return newCircle;
}

Shape* Circle::homothety(const Vector2D & invariantPoint,
                         const double & homothetyRatio) const
{
    Circle *newCircle = new Circle(*this);
    newCircle->_center.homothety(invariantPoint,homothetyRatio);
    newCircle->_diameter *= homothetyRatio;
    return newCircle;
}

Shape* Circle::rotation(const Vector2D & rotationCenter,
                        const RadianAngle & rotationAngle) const
{
    Circle *newCircle = new Circle(*this);
    newCircle->_center.rotation(rotationCenter,rotationAngle);
    return newCircle;
}

double Circle::getArea() const
{
    double radius = _diameter/2;
    return M_PI*radius*radius;
}

ostream & operator<<(ostream & os, const Circle & circle)
{
    os << (string) circle;
    return os;
}
