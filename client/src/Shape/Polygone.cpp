#include "Polygone.hpp"
#include "../Geometry/Vector2D.hpp"
#include <cmath>

Polygone()
{

}


void Polygone::draw(const DrawingVisitor* visitor) const
{
    visitor.draw(this);
}

void Polygone::addPoint(const Vector2D & point)
{
    _points.push_back(point);
}

operator Polygone::string() const
{

}

void Polygone::save(const SaveVisitor* saveVisitor) const
{
    saveVisitor.save(this);
}

Shape* Polygone::translation(const Vector2D & translationVector)
{
    Polygone newPolygone(this);
    for(int i=0;i<newPolygone._points.size();i++){
        newPolygone._points[i].translation(translationVector);
    }
    return newPolygone;
}

void Polygone::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio)
{
    Polygone newPolygone(this);
    for(int i=0;i<newPolygone._points.size();i++){
        newPolygone._points[i].homothety(invariantPoint, homothetyRatio);
    }
    return newPolygone;
}

void Polygone::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle)
{
    Polygone newPolygone(this);
    for(int i=0;i<newPolygone._points.size();i++){
        newPolygone._points[i].rotation(rotationCenter, rotationAngle);
    }
    return newPolygone;
}

double Polygone::getArea() const
{
    double area=0;
    for(int i=0;i<_points.size();i++){
        if(i!=_point.size()-1){
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
