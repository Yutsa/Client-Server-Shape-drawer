#include <iosfwd>
#include "ShapeLoader.hpp"

class Shape;
using std::string;

class ShapeLoaderLink : public ShapeLoader

{
private:
    ShapeLoaderLink* _next;
public:
    ShapeLoaderLink(const ShapeLoaderLink* next);
    const Shape* load(const string & filename) const;
    virtual const Shape* loadShape(const string & filename) = 0;
};
