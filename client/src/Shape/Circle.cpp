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

virtual void Circle::translation(const Vector2D & translationVector)
{
    _center.setX(translationVector.getX()+_center.getX())
    _center.setY(translationVector.getY()+_center.getY())
}

virtual void Circle::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio)
{
    _center.homothety(invariantPoint,homothetyRatio);

    _diameter *= homothetyRatio;
}

virtual void Circle::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle)
{

}

virtual double Circle::getArea() const
{
    double radius = _diameter/2;
    return M_PI*radius*radius;
}
