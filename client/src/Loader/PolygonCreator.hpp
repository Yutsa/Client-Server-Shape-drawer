#include "ShapeCreatorLink.hpp"

class PolygonCreator : public ShapeCreatorLink
{
    PolygonCreator(ShapeCreatorLink *next);
    
    virtual const Shape* createShapeSpe(const string & shapeString) const;
};