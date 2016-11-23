#include "ShapeCreatorLink.hpp"

class PolygonCreator : public ShapeCreatorLink
{
    PolygonCreator(ShapeCreatorLink *next);
    
    virtual Shape* createShapeSpe(const string & shapeString) const;
};