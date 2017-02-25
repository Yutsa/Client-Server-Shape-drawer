#include "Polygon.hpp"
#include <sstream>
#include <iostream>

#include "../Visitor/DrawingVisitor.hpp"
#include "../Visitor/SaveTextVisitor.hpp"

using std::ostringstream;

Polygon::Polygon(const Color & color) : Shape(color)
{

}


void Polygon::draw(DrawingVisitor* visitor) const
{
    visitor->draw(this);
}

void Polygon::addPoint(const Vector2D & point)
{
    _points.push_back(point);
}

const Vector2D Polygon::getPoint(int index) const
{
    return _points[index];
}

const int Polygon::getPointsSize() const
{
    return _points.size();
}

Polygon::operator string() const
{
    ostringstream os;
    os << "polygon," << _color;
    for(unsigned int i = 0; i < _points.size(); i++)
    {
        os << "," << (int)_points[i].getX() << "," << (int)_points[i].getY();
    }
    return os.str();
}

void Polygon::save(const SaveVisitor* saveVisitor, const string & filename) const
{
    saveVisitor->save(this, filename);
}

Shape* Polygon::translation(const Vector2D & translationVector) const
{
    Polygon *newPolygon = new Polygon(*this);
    for(unsigned int i=0 ; i < newPolygon->_points.size() ; i++)
    {
        newPolygon->_points[i].translation(translationVector);
    }
    return newPolygon;
}

Shape* Polygon::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio) const
{
    Polygon *newPolygon = new Polygon(*this);
    for(unsigned int i = 0; i < newPolygon->_points.size(); i++){
        newPolygon->_points[i].homothety(invariantPoint, homothetyRatio);
    }
    return newPolygon;
}

Shape* Polygon::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle) const
{
    Polygon *newPolygon = new Polygon(*this);
    for(unsigned int i = 0; i < newPolygon->_points.size(); i++){
        newPolygon->_points[i].rotation(rotationCenter, rotationAngle);
    }
    return newPolygon;
}

double Polygon::getArea() const
{
    double area=0;
    for(unsigned int i=0;i<_points.size();i++){
        if(i!=_points.size()-1){
            area += (_points[i].getX()*_points[i+1].getY())
                -(_points[i+1].getX()*_points[i].getY());
        }
        else{
            area += (_points[i].getX()*_points[0].getY())
                -(_points[0].getX()*_points[i].getY());
        }
    }
    return (area/2);
}

ostream & operator<<(ostream & os, const Polygon & polygon)
{
    os << (string) polygon;
    return os;
}
