#ifndef SHAPE_CREATOR_H
#define SHAPE_CREATOR_H

#include <iosfwd>

class Shape;
using std::string;

/**
* Abstract class ShapeCreator for handle shape creation COR
*/
class ShapeCreator
{
public:
    /**
    * Virtual method for create a shape from a string
    * @param shapeString The string cast of the shape have to create
    * @return Shape* The shape wich is create
    */
    virtual Shape* createShape(const string & shapeString) const = 0;
};

#endif