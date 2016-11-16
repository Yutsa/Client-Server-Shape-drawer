#include <iostream>
#include <Shape.hpp>

using std::string;

class Circle : public Shape
{
private:
    Vector2D _center;
    double _diamater;
public:
    Circle(double x, double y, double diameter);
    virtual void draw(const DrawingVisitor* visitor) const;
    virtual operator string() const;
    virtual void save(const SaveVisitor* saveVisitor) const;
    virtual void translation();
    virtual void homothety();
    virtual void rotation();
    virtual double getArea() const;
}
