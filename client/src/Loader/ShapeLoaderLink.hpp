#ifndef SHAPE_LOADER_LINK_H
#define SHAPE_LOADER_LINK_H

#include <iosfwd>
#include "ShapeLoader.hpp"

class Shape;
using std::string;

class ShapeLoaderLink : public ShapeLoader

{
private:
    const ShapeLoaderLink* _next;
public:
    ShapeLoaderLink(const ShapeLoaderLink* next, const ShapeCreator* shapeCreator);
    virtual ~ShapeLoaderLink();
    Shape* load(const string & filename) const;
    virtual Shape* loadShape(const string & filename) const = 0;
};

#endif
