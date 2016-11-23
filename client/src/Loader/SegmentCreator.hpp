#include "ShapeCreatorLink.hpp"

class SegmentCreator : public ShapeCreatorLink
{
public:
    SegmentCreator(ShapeCreatorLink *next);
    
    virtual Shape* createShapeSpe(const string & shapeString) const;
};
