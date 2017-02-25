#ifndef SEGMENT_CREATOR_H
#define SEGMENT_CREATOR_H

#include "ShapeCreatorLink.hpp"

/**
* Class SegmentCreator
* Link of the COR for build Segment
*/
class SegmentCreator : public ShapeCreatorLink
{
public:
    /**
    * Constructor of SegmentCreator
    * @param next The next ShapeCreatorLink if this one fails 
    */
    SegmentCreator(ShapeCreatorLink *next);
    
    /**
    * Try to create a Segment with the string
    * @param shapeString the string with informations of the shape
    * @return The Shape* wich were created
    */
    virtual Shape* createShapeSpe(const string & shapeString) const;
};

#endif