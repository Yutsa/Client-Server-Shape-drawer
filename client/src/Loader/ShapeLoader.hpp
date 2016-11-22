#ifndef SHAPE_LOADER_H
#define SHAPE_LOADER_H

#include <iosfwd>

class Shape;
using std::string;

class ShapeLoader
{
public:
    virtual const Shape* load(const string & filename) const = 0;
};

#endif
