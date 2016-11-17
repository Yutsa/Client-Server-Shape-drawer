#ifndef SAVE_VISITOR_H
#define SAVE_VISITOR_H

#include <iostream>

class Circle;
class Segment;
class Triangle;
class Polygon;

/**
* The abstract class to implement the classes that will save the Shapes.
*/

class SaveVisitor
{
public:
    /**
    * Saves the Circle.
    * @param circle The Circle to save.
    */
    virtual void save(Circle* circle) = 0;
    /**
    * Saves the Segment.
    * @param segment The Segment to save.
    */
    virtual void save(Segment* segment) = 0;
    /**
    * Saves the Triangle.
    * @param triangle The Triangle to save.
    */
    virtual void save(Triangle* triangle) = 0;
    /**
    * Saves the Polygon.
    * @param polygon The Polygon to save.
    */
    virtual void save(Polygon* polygon) = 0;
};

#endif
