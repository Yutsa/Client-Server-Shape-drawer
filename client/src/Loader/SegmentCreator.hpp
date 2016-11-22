#include "ShapeCreatorLink.hpp"

class SegmentCreator : public ShapeCreatorLink
{
    SegmentCreator();
    
    virtual const Shape* createShapeSpe(const string & shapeString);
}