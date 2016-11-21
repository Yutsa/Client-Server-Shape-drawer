#ifndef DRAWING_VISITOR_H
#define DRAWING_VISITOR_H

#include <iostream>

class Circle;
class Segment;
class Triangle;
class Polygon;
class Shape;

using std::string;
using std::cout;
using std::endl;

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
    virtual void draw(const Circle* circle) const = 0;

    /**
    * Draws the Segment.
    * @param segment The Segment to draw.
    */
    virtual void draw(const Segment* segment) const = 0;

    /**
    * Draws the Triangle.
    * @param triangle The Triangle to draw.
    */
    virtual void draw(const Triangle* triangle) const = 0;

    /**
    * Draws the Polygon.
    * @param polygon The Polygon to draw.
    */
    virtual void draw(const Polygon* polygon) const = 0;

    /**
    * Draws the Shape.
    * @param polygon The Shape to draw.
    */
    virtual void draw(const Shape* shape) const = 0;
};

#endif
