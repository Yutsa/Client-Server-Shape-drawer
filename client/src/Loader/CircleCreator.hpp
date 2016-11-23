#include "ShapeCreatorLink.hpp"

class CircleCreator : public ShapeCreatorLink
{
    CircleCreator(ShapeCreatorLink *next);
    
    virtual Shape* createShapeSpe(const string & shapeString) const;
};