#include "ShapeCreatorLink.hpp"

class TriangleCreator : public ShapeCreatorLink
{
    TriangleCreator(ShapeCreatorLink *next);
    
    virtual Shape* createShapeSpe(const string & shapeString) const;
};