#ifndef CIRCLE_CREATOR_H
#define CIRCLE_CREATOR_H

#include "ShapeCreatorLink.hpp"

/**
* Class CircleCreator
* Link of the COR for build Circle
*/
class CircleCreator : public ShapeCreatorLink
{
public:
    /**
    * Constructor of CircleCreator
    * @param next The next ShapeCreatorLink if this one fails 
    */
    CircleCreator(ShapeCreatorLink *next);
    
    /**
    * Try to create a Circle with the string
    * @param shapeString The string with informations of the shape
    * @return The Shape* wich were created
    */
    virtual Shape* createShapeSpe(const string & shapeString) const;
};

#endif