#ifndef SHAPE_CREATOR_LINK_H
#define SHAPE_CREATOR_LINK_H

#include <iosfwd>
#include "ShapeCreator.hpp"
#include <vector>
#include <string>

using std::vector;

/**
* namespace func
*/
namespace func
{
    /**
    * Splits a string with a separator
    * @param s String to split
    * @param sep The separator
    * @return vector<string> An array of the string wich is split
    */
    vector<string> split(const string & s, char sep);
}

/**
* Abstract class ShapeCreatorLink for link the COR of creation shape
*/
class ShapeCreatorLink : public ShapeCreator
{
protected:
    ShapeCreatorLink* _next;
public:
    /**
    * Constructor of ShapeCreatorLink
    * @param next A pointer of the next ShapeCreatorLink
    */
    ShapeCreatorLink(ShapeCreatorLink* next);
    
    /**
    * Try to create a shape with string 
    * If it doesn't work, try with the next ShapeCreatorLink
    * @param shapeString The string for build the shape
    * @return A Shape* build with shapeString 
    */
    Shape* createShape(const string & shapeString) const;
    
    /**
    * Abstract method for try creating shape with each type of Shape
    * @param shapeString The string for build the shape
    * @return A Shape* build with shapeString 
    */
    virtual Shape* createShapeSpe(const string & shapeString) const = 0;
};

#endif