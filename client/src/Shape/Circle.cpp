#include "Circle.hpp"
#include "../Geometry/Vector2D.hpp"
#include <cmath>

Circle::Circle(Vector2D center, double diameter)
{
    _center.setX(center.getX());
    _center.setY(center.getY());
    _diameter=diameter;
}

virtual void Circle::draw(const DrawingVisitor* visitor) const
{
    visitor.draw(this);
}

virtual operator Circle::string() const
{

}

virtual void Circle::save(const SaveVisitor* saveVisitor) const
{
    saveVisitor.save(this);
}

virtual Shape* Circle::translation(const Vector2D & translationVector)
{
    Circle newCircle(this);
    newCircle._center.translation(translationVector);
    return newCircle;
}

virtual void Circle::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio)
{
    Circle newCircle(this);
    newCircle._center.homothety(invariantPoint,homothetyRatio);
    newCircle._diameter *= homothetyRatio;
    return newCircle;

}

virtual void Circle::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle)
{
    Circle newCircle(this);
    newCircle._center.rotation(rotationCenter,rotationAngle);
    return newCircle;
}

virtual double Circle::getArea() const
{
    double radius = _diameter/2;
    return M_PI*radius*radius;
}
