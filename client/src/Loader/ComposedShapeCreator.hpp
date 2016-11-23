#include "ShapeCreatorLink.hpp"

class ComposedShapeCreator : public ShapeCreatorLink
{
    ComposedShapeCreator(ShapeCreatorLink *next);
    
    virtual Shape* createShapeSpe(const string & shapeString) const;
};