#include <iosfwd>

class Shape;
using std::string;

class ShapeCreator
{
public:
    virtual Shape* createShape(const string & shapeString) const = 0;
};