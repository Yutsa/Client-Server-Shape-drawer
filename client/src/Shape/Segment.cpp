#include "Segment.hpp"
#include <sstream>

using std::ostringstream;

Segment::Segment(Vector2D firstPoint, Vector2D secondPoint, Color color) : Shape(color)
{
    _firstPoint = firstPoint;
    _secondPoint = secondPoint;
}

Segment::Segment(Vector2D firstPoint, Vector2D secondPoint) : Shape()
{
    _firstPoint = firstPoint;
    _secondPoint = secondPoint;
}

void Segment::draw(const DrawingVisitor* visitor) const
{
    visitor->draw(this);
}

Segment::operator string() const
{
    ostringstream os;
    os << "segment," << _color << "," << _firstPoint.getX() << "," << _firstPoint.getY() << "," << _secondPoint.getX() << "," << _secondPoint.getY();
    return os.str();
}

void Segment::save(const SaveVisitor* saveVisitor, const string & filename) const
{
    saveVisitor->save(this, filename);
}

Shape* Segment::translation(const Vector2D & translationVector) const
{
    Segment *newSegment = new Segment(*this);
    newSegment->_firstPoint.translation(translationVector);
    newSegment->_secondPoint.translation(translationVector);
    return newSegment;
}

Shape* Segment::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio) const
{
    Segment *newSegment = new Segment(*this);
    newSegment->_firstPoint.homothety(invariantPoint,homothetyRatio);
    newSegment->_secondPoint.homothety(invariantPoint,homothetyRatio);
    return newSegment;
}

Shape* Segment::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle) const
{
    Segment *newSegment = new Segment(*this);
    newSegment->_firstPoint.rotation(rotationCenter,rotationAngle);
    newSegment->_secondPoint.rotation(rotationCenter,rotationAngle);
    return newSegment;
}
double Segment::getArea() const
{
    return 0;
}

ostream & operator << (ostream & os, const Segment & segment)
{
    os << (string) segment;
    return os;
}
