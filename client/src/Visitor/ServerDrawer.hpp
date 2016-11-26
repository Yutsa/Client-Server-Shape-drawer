#ifndef SERVER_DRAWER_H
#define SERVER_DRAWER_H

#include <iostream>
#include "../Network/Socket.hpp"
#include "DrawingVisitor.hpp"



/**
* This class is the drawer that implement a way to draw shapes using a
* drawing server.
*/

class ServerDrawer : public DrawingVisitor
{
public:
    ServerDrawer();
    virtual ~ServerDrawer();
    /**
    * Draws the Circle.
    * @param circle The Circle to draw.
    */
    void draw(const Circle* circle);

    /**
    * Draws the Segment.
    * @param segment The Segment to draw.
    */
    void draw(const Segment* segment);

    /**
    * Draws the Triangle.
    * @param triangle The Triangle to draw.
    */
    void draw(const Triangle* triangle);

    /**
    * Draws the Polygon.
    * @param polygon The Polygon to draw.
    */
    void draw(const Polygon* polygon);

    /**
    * Draws the Shape.
    * @param polygon The Shape to draw.
    */
    virtual void draw(const Shape* shape);    
};

#endif
