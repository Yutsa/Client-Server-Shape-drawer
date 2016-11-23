#include "Triangle.hpp"
#include <sstream>

using std::ostringstream;

Triangle::Triangle(const Vector2D & firstPoint, const Vector2D & secondPoint, const Vector2D & thirdPoint, const Color & color) : Shape(color)
{
    _firstPoint = firstPoint;
    _secondPoint = secondPoint;
    _thirdPoint = thirdPoint;
}

void Triangle::draw(const DrawingVisitor* visitor) const
{
    visitor->draw(this);
}

const Vector2D getFirstPoint() const
{
    return _firstPoint;
}

const Vector2D getSecondPoint() const
{
    return _secondPoint;
}

const Vector2D getThirdPoint() const
{
    return _thirdPoint;
}

Triangle::operator string() const
{
    ostringstream os;
    os << "triangle," << _color << "," << (int)_firstPoint.getX() << ","
        << (int)_firstPoint.getY() << "," << (int)_secondPoint.getX() << ","
        << (int)_secondPoint.getY() << "," << (int)_thirdPoint.getX() << ","
        << (int)_thirdPoint.getY();
    return os.str();
}

void Triangle::save(const SaveVisitor* saveVisitor, const string & filename) const
{
    saveVisitor->save(this, filename);
}

Shape* Triangle::translation(const Vector2D & translationVector) const
{
    Triangle *newTriangle = new Triangle(*this);
    newTriangle->_firstPoint.translation(translationVector);

    newTriangle->_secondPoint.translation(translationVector);

    newTriangle->_thirdPoint.translation(translationVector);
    return newTriangle;
}

Shape* Triangle::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio) const
{
    Triangle *newTriangle = new Triangle(*this);
    newTriangle->_firstPoint.homothety(invariantPoint,homothetyRatio);
    newTriangle->_secondPoint.homothety(invariantPoint,homothetyRatio);
    newTriangle->_thirdPoint.homothety(invariantPoint,homothetyRatio);
    return newTriangle;
}

Shape* Triangle::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle) const
{
    Triangle *newTriangle = new Triangle(*this);
    newTriangle->_firstPoint.rotation(rotationCenter,rotationAngle);
    newTriangle->_secondPoint.rotation(rotationCenter,rotationAngle);
    newTriangle->_thirdPoint.rotation(rotationCenter,rotationAngle);
    return newTriangle;
}
double Triangle::getArea() const
{
    double semi_perimeter;
    double firstSegment, secondSegment, thirdSegment;
    firstSegment=sqrt(pow((_secondPoint.getX()-_firstPoint.getX()),2)
        +pow((_secondPoint.getY()-_firstPoint.getY()),2));
    secondSegment=sqrt(pow((_thirdPoint.getX()-_secondPoint.getX()),2)
        +pow((_thirdPoint.getY()-_secondPoint.getY()),2));
    thirdSegment=sqrt(pow((_firstPoint.getX()-_thirdPoint.getX()),2)
        +pow((_firstPoint.getY()-_thirdPoint.getY()),2));
    semi_perimeter = (firstSegment+secondSegment+thirdSegment)/2;

    //Heron Formula
    return sqrt(semi_perimeter*(semi_perimeter - firstSegment)
        *(semi_perimeter - secondSegment)*(semi_perimeter - thirdSegment));

}

ostream  & operator << (ostream & os, const Triangle & triangle)
{
    os << (string) triangle;
    return os;
}
