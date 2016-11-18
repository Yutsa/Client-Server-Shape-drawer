#ifndef SERVER_DRAWER_H
#define SERVER_DRAWER_H

#include <iostream>
#include "../Network/Socket.hpp"

class ServerDrawer : public DrawingVisitor
{
public:
    ServerDrawer();
    virtual ~ServerDrawer();
    /**
    * Draws the Circle.
    * @param circle The Circle to draw.
    */
    virtual void draw(Circle* circle);

    /**
    * Draws the Segment.
    * @param segment The Segment to draw.
    */
    virtual void draw(Segment* segment);

    /**
    * Draws the Triangle.
    * @param triangle The Triangle to draw.
    */
    virtual void draw(Triangle* triangle);

    /**
    * Draws the Polygon.
    * @param polygon The Polygon to draw.
    */
    virtual void draw(Polygon* polygon);
};

#endif
