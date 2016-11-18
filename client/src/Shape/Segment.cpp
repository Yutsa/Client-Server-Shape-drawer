#include "Segment.hpp"

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

Shape* Segment::translation(const Vector2D & translationVector)
{
    Segment newSegment(this);
    newSegment._firstPoint.translation(translationVector);
    newSegment._secondPoint.translation(translationVector);
    return newSegment;
}

void Segment::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio)
{
    Segment newSegment(this);
    newSegment._firstPoint.homothety(invariantPoint,homothetyRatio);
    newSegment._secondPoint.homothety(invariantPoint,homothetyRatio);
    return newSegment;
}

void Segment::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle)
{
    Segment newSegment(this);
    newSegment._firstPoint.rotation(rotationCenter,rotationAngle);
    newSegment._secondPoint.rotation(rotationCenter,rotationAngle);
    return newSegment;
}
double Segment::getArea() const
{
    return 0;
}
