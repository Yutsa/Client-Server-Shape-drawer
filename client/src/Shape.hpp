#include <iostream>
#include <string>

using std::string;

class Shape
{
public:
    virtual void draw(const DrawingVisitor* visitor) const = 0;
    virtual operator string() const = 0;
    virtual void save(const SaveVisitor* saveVisitor) const = 0;
    virtual void translation() = 0;
    virtual void homothety() = 0;
    virtual void rotation() = 0;
    virtual double getArea() const = 0;
}
