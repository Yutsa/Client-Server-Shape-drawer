#include "Circle.hpp"
#include "../Geometry/Vector2D.hpp"
#include <cmath>

Triangle::Triangle(Vector2D firstPoint, Vector2D secondPoint, Vector2D thirdPoint)
{
    _firstPoint = firstPoint;
    _secondPoint = secondPoint;
    _thirdPoint = thirdPoint;
}

void Triangle::draw(const DrawingVisitor* visitor) const
{
    visitor.draw(this);
}

operator Triangle::string() const
{

}

void Triangle::save(const SaveVisitor* saveVisitor) const
{
    saveVisitor.save(this);
}

void Triangle::translation(const Vector2D & translationVector)
{
    _firstPoint.setX(translationVector.getX()+_firstPoint.getX())
    _firstPoint.setY(translationVector.getY()+_firstPoint.getY())

    _secondPoint.setX(translationVector.getX()+_secondPoint.getX())
    _secondPoint.setY(translationVector.getY()+_secondPoint.getY())
}

void Triangle::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio)
{
    _firstPoint.homothety(invariantPoint,homothetyRatio);
    _secondPoint.homothety(invariantPoint,homothetyRatio);
    _thirdPoint.homothety(invariantPoint,homothetyRatio);
}

void Triangle::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle)
{
    _firstPoint.rotation(rotationCenter,rotationAngle);
    _secondPoint.rotation(rotationCenter,rotationAngle);
    _thirdPoint.rotation(rotationCenter,rotationAngle);
}
double Triangle::getArea() const
{
    //TODO
}
