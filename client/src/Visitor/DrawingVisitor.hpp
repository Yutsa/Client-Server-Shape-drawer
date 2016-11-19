#ifndef DRAWING_VISITOR_H
#define DRAWING_VISITOR_H

#include <iostream>

class Circle;
class Segment;
class Triangle;
class Polygone;

using std::string;
using std::cout;
using std::endl;

//#include "../Shape/Circle.hpp"
//#include "../Shape/Segment.hpp"
//#include "../Shape/Triangle.hpp"
//#include "../Shape/Polygone.hpp"

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
    virtual void draw(const Polygone* polygon) const = 0;
};

#endif
