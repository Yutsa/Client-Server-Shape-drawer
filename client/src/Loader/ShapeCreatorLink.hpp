#include <iosfwd>
#include "ShapeCreator.hpp"

class Shape;
using std::string;

class ShapeCreatorLink : public ShapeCreator
{
private:
    ShapeCreatorLink* _next;
public:
    ShapeCreatorLink(const ShapeCreatorLink* next);
    const Shape* createShape(const string & shapeString) const;
    virtual const Shape* createShapeSpe(const string & shapeString) = 0;
};