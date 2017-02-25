#ifndef SHAPE_LOADER_TEXT_H
#define SHAPE_LOADER_TEXT_H

#include "ShapeLoaderLink.hpp"

class ShapeLoaderText : public ShapeLoaderLink
{
public:
    ShapeLoaderText(const ShapeLoaderLink* next, const ShapeCreator* shapeCreator);
    Shape* loadShape(const string & filename) const;
};

#endif
