#include "Triangle.hpp"
#include <sstream>

#include "../Visitor/SaveVisitor.hpp"
#include "../Visitor/ServerDrawer.hpp"

using std::ostringstream;

Triangle::Triangle(const Vector2D & firstPoint, const Vector2D & secondPoint, const Vector2D & thirdPoint, const Color & color) : Polygon(color)
{
//    _firstPoint = firstPoint;
//    _secondPoint = secondPoint;
//    _thirdPoint = thirdPoint;

    _points.push_back(firstPoint);
    _points.push_back(secondPoint);
    _points.push_back(thirdPoint);
}

void Triangle::draw(DrawingVisitor* visitor) const
{
    visitor->draw(this);
}

const Vector2D Triangle::getFirstPoint() const
{
    //return _firstPoint;
    return _points[0];
}

const Vector2D Triangle::getSecondPoint() const
{
    //return _secondPoint;
    return _points[1];
}

const Vector2D Triangle::getThirdPoint() const
{
    //return _thirdPoint;
    return _points[2];
}

Triangle::operator string() const
{
    ostringstream os;
    os << "triangle," << _color << "," << (int)_points[0].getX() << ","
        << (int)_points[0].getY() << "," << (int)_points[1].getX() << ","
        << (int)_points[1].getY() << "," << (int)_points[2].getX() << ","
        << (int)_points[2].getY();
    return os.str();
}

void Triangle::save(const SaveVisitor* saveVisitor, const string & filename) const
{
    saveVisitor->save(this, filename);
}

Shape* Triangle::translation(const Vector2D & translationVector) const
{
    Triangle *newTriangle = new Triangle(*this);
//    newTriangle->_firstPoint.translation(translationVector);
//
//    newTriangle->_secondPoint.translation(translationVector);
//
//    newTriangle->_thirdPoint.translation(translationVector);
    
    for (int i = 0; i < 3; i++) 
    {
        newTriangle->_points[i].translation(translationVector);
    }
    
    return newTriangle;
}

Shape* Triangle::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio) const
{
    Triangle *newTriangle = new Triangle(*this);
//    newTriangle->_firstPoint.homothety(invariantPoint,homothetyRatio);
//    newTriangle->_secondPoint.homothety(invariantPoint,homothetyRatio);
//    newTriangle->_thirdPoint.homothety(invariantPoint,homothetyRatio);
    
    for (int i = 0; i < 3; i++) 
    {
        newTriangle->_points[i].homothety(invariantPoint,homothetyRatio);
    }
    return newTriangle;
}

Shape* Triangle::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle) const
{
    Triangle *newTriangle = new Triangle(*this);
//    newTriangle->_firstPoint.rotation(rotationCenter,rotationAngle);
//    newTriangle->_secondPoint.rotation(rotationCenter,rotationAngle);
//    newTriangle->_thirdPoint.rotation(rotationCenter,rotationAngle);
    
    for (int i = 0; i < 3; i++) 
    {
        newTriangle->_points[i].rotation(rotationCenter,rotationAngle);
    }
    return newTriangle;
}
double Triangle::getArea() const
{
    double semi_perimeter;
    double firstSegment, secondSegment, thirdSegment;
//    firstSegment=sqrt(pow((_secondPoint.getX()-_firstPoint.getX()),2)
//        +pow((_secondPoint.getY()-_firstPoint.getY()),2));
//    secondSegment=sqrt(pow((_thirdPoint.getX()-_secondPoint.getX()),2)
//        +pow((_thirdPoint.getY()-_secondPoint.getY()),2));
//    thirdSegment=sqrt(pow((_firstPoint.getX()-_thirdPoint.getX()),2)
//        +pow((_firstPoint.getY()-_thirdPoint.getY()),2));
    
    firstSegment=sqrt(pow((_points[1].getX()-_points[0].getX()),2)
        +pow((_points[1].getY()-_points[0].getY()),2));
    secondSegment=sqrt(pow((_points[2].getX()-_points[1].getX()),2)
        +pow((_points[2].getY()-_points[1].getY()),2));
    thirdSegment=sqrt(pow((_points[0].getX()-_points[2].getX()),2)
        +pow((_points[0].getY()-_points[2].getY()),2));
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
