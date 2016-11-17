#include "Circle.hpp"
#include "../Geometry/Vector2D.hpp"
#include <cmath>

Segment::Segment(Vector2D firstPoint, Vector2D secondPoint)
{
    _firstPoint = firstPoint;
    _secondPoint = secondPoint;
}

void Segment::draw(const DrawingVisitor* visitor) const
{
    visitor.draw(this);
}

operator Segment::string() const
{

}

void Segment::save(const SaveVisitor* saveVisitor) const
{
    saveVisitor.save(this);
}

void Segment::translation(const Vector2D & translationVector)
{
    _firstPoint.setX(translationVector.getX()+_firstPoint.getX())
    _firstPoint.setY(translationVector.getY()+_firstPoint.getY())

    _secondPoint.setX(translationVector.getX()+_secondPoint.getX())
    _secondPoint.setY(translationVector.getY()+_secondPoint.getY())
}

void Segment::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio)
{
    _firstPoint.homothety(invariantPoint,homothetyRatio);
    _secondPoint.homothety(invariantPoint,homothetyRatio);
}

void Segment::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle)
{
    _firstPoint.rotation(rotationCenter,rotationAngle);
    _secondPoint.rotation(rotationCenter,rotationAngle);
}
double Segment::getArea() const
{
    return 0;
}
