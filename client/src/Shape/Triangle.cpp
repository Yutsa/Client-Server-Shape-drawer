#include "Triangle.hpp"
#include <sstream>
#include <iostream>

#include "../Visitor/SaveVisitor.hpp"
#include "../Visitor/ServerDrawer.hpp"

using std::ostringstream;

Triangle::Triangle(const Vector2D & firstPoint, const Vector2D & secondPoint, const Vector2D & thirdPoint, const Color & color) : Polygon(color)
{
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
    return _points[0];
}

const Vector2D Triangle::getSecondPoint() const
{
    return _points[1];
}

const Vector2D Triangle::getThirdPoint() const
{
    return _points[2];
}

Triangle::operator string() const
{
    ostringstream os;
    os << "triangle," << _color;
    for (int i = 0; i < 3; i++) 
    {
        os << "," << (int)_points[i].getX() << "," << (int)_points[i].getY();
    }
    
    return os.str();
}

void Triangle::save(const SaveVisitor* saveVisitor, const string & filename) const
{
    saveVisitor->save(this, filename);
}

Shape* Triangle::translation(const Vector2D & translationVector) const
{
    Triangle *newTriangle = new Triangle(*this);

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
