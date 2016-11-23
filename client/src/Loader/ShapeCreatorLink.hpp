#include <iosfwd>
#include "ShapeCreator.hpp"
#include <vector>
#include <string>

class Shape;

using std::string;
using std::vector;

namespace func 
{
    vector<string> split(const string & s, char sep);
}

class ShapeCreatorLink : public ShapeCreator
{
protected:
    ShapeCreatorLink* _next;
public:
    ShapeCreatorLink(ShapeCreatorLink* next);
    const Shape* createShape(const string & shapeString) const;
    virtual const Shape* createShapeSpe(const string & shapeString) const = 0;
};