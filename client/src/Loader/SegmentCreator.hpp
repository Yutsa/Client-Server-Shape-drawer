#include "ShapeCreatorLink.hpp"

class SegmentCreator : public ShapeCreatorLink
{
    SegmentCreator(ShapeCreatorLink *next);
    
    virtual const Shape* createShapeSpe(const string & shapeString) const;
};