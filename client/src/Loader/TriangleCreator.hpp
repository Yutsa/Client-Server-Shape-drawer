#include "ShapeCreatorLink.hpp"

class TriangleCreator : public ShapeCreatorLink
{
    TriangleCreator(ShapeCreatorLink *next);
    
    virtual const Shape* createShapeSpe(const string & shapeString) const;
};