#ifndef COMPOSED_SHAPE_CREATOR_H
#define COMPOSED_SHAPE_CREATOR_H

#include "ShapeCreatorLink.hpp"

/**
* Class ComposedShapeCreator
* Link of the COR for build ComposedShape
*/
class ComposedShapeCreator : public ShapeCreatorLink
{
public:
    /**
    * Constructor of ComposedShapeCreator
    * @param next The next ShapeCreatorLink if this one fails 
    */
    ComposedShapeCreator(ShapeCreatorLink *next);
    
    /**
    * Try to create a ComposedShape with the string
    * @param shapeString the string with informations of the shape
    * @return The Shape* wich were created
    */
    virtual Shape* createShapeSpe(const string & shapeString) const;
};

#endif