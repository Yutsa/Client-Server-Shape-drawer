#ifndef SHAPE_LOADER_H
#define SHAPE_LOADER_H

#include <iosfwd>

class Shape;
class ShapeCreator;
using std::string;

class ShapeLoader
{
protected:
    /* Could remove const if we want to change the shapeCreator.
    *  Then we'd need a setter
    */
    const ShapeCreator* _shapeCreator;
public:
    ShapeLoader(const ShapeCreator* shapeCreator)
    {
        _shapeCreator = shapeCreator;
    }
    virtual Shape* load(const string & filename) const = 0;
};

#endif
