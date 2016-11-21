#include "ComposedShape.hpp"
#include <sstream>

using std::ostringstream;

ComposedShape::ComposedShape(Color color) : Shape(color){}

void ComposedShape::addShape(const Shape* shape)
{
    _shapes.push_back(shape);
}

void ComposedShape::draw(const DrawingVisitor* visitor) const
{
    visitor->draw(this);
}

ComposedShape::operator string() const
{
    ostringstream os;
    os << "composedShape\n";
    for(unsigned int i = 0; i < _shapes.size(); i++)
    {
        os << _shapes[i] << "\n";
    }
}

void ComposedShape::save(const SaveVisitor* saveVisitor, const string & filename) const
{
    saveVisitor->save(this, filename);
}

Shape* ComposedShape::translation(const Vector2D & translationVector) const
{
    ComposedShape* newComposedShape = new ComposedShape(*this);
    for(unsigned int i = 0; i < newComposedShape->_shapes.size(); i++)
    {
        newComposedShape->_shapes[i].translation(translationVector);
    }
    return newComposedShape;
}

Shape* ComposedShape::homothety(const Vector2D & invariantPoint,
    const double & homothetyRatio) const
{
    ComposedShape* newComposedShape = new ComposedShape(*this);
    for(unsigned int i = 0; i < newComposedShape->_shapes.size(); i++)
    {
        newComposedShape->_shapes[i].homothety(invariantPoint, homothetyRatio);
    }
    return newComposedShape;
}

Shape* ComposedShape::rotation(const Vector2D & rotationCenter,
    const RadianAngle & rotationAngle) const
{
    ComposedShape* newComposedShape = new ComposedShape(*this);
    for(unsigned int i = 0; i < newComposedShape->_shapes.size(); i++)
    {
        newComposedShape->_shapes[i].rotation(rotationCenter, rotationAngle);
    }
    return newComposedShape;
}

double ComposedShape::getArea() const
{
    double area=0;
    for(unsigned int i = 0; i < _shapes.size(); i++)
    {
        area += _shapes[i]->getArea();
    }
    return area;
}

ostream & operator << (ostream & os, const ComposedShape & composedShape)
{

}
