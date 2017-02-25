#ifndef TRIANGLE_CREATOR_H
#define TRIANGLE_CREATOR_H

#include "ShapeCreatorLink.hpp"

/**
* Class TriangleCreator
* Link of the COR for build Triangle
*/
class TriangleCreator : public ShapeCreatorLink
{
public:
    /**
    * Constructor of TriangleCreator
    * @param next The next ShapeCreatorLink if this one fails 
    */
    TriangleCreator(ShapeCreatorLink *next);
    
    /**
    * Try to create a Triangle with the string
    * @param shapeString the string with informations of the shape
    * @return The Shape* wich were created
    */
    virtual Shape* createShapeSpe(const string & shapeString) const;
};

#endif