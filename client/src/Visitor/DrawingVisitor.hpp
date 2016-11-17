#ifndef DRAWING_VISITOR_H
#define DRAWING_VISITOR_H

#include <iostream>

class Circle;
class Segment;
class Triangle;
class Polygon;

/**
* The abstract base class for all drawers.
*/

class DrawingVisitor
{
public:
    /**
    * Draws the Circle.
    * @param circle The Circle to draw.
    */
    virtual void draw(Circle* circle) = 0;

    /**
    * Draws the Segment.
    * @param segment The Segment to draw.
    */
    virtual void draw(Segment* segment) = 0;

    /**
    * Draws the Triangle.
    * @param triangle The Triangle to draw.
    */
    virtual void draw(Triangle* triangle) = 0;

    /**
    * Draws the Polygon.
    * @param polygon The Polygon to draw.
    */
    virtual void draw(Polygon* polygon) = 0;
};

#endif
