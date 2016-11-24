#ifndef POLYGON_CREATOR_H
#define POLYGON_CREATOR_H

#include "ShapeCreatorLink.hpp"

/**
* Class PolygonCreator
* Link of the COR for build Polygon
*/
class PolygonCreator : public ShapeCreatorLink
{
public:
    /**
    * Constructor of PolygonCreator
    * @param next The next ShapeCreatorLink if this one fails 
    */
    PolygonCreator(ShapeCreatorLink *next);
    
    /**
    * Try to create a Polygon with the string
    * @param shapeString the string with informations of the shape
    * @return The Shape* wich were created
    */
    virtual Shape* createShapeSpe(const string & shapeString) const;
};

#endif