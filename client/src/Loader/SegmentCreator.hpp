#include "ShapeCreatorLink.hpp"

class SegmentCreator : public ShapeCreatorLink
{
    SegmentCreator(ShapeCreatorLink *next);
    
    virtual Shape* createShapeSpe(const string & shapeString) const;
};