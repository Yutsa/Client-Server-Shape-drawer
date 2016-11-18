#ifndef SERVER_DRAWER_H
#define SERVER_DRAWER_H

#include <iostream>
#include "../Network/Socket.hpp"
#include "DrawingVisitor.hpp"

#include "../Shape/Circle.hpp"

class ServerDrawer : public DrawingVisitor
{
public:
    ServerDrawer();
    virtual ~ServerDrawer();
    /**
    * Draws the Circle.
    * @param circle The Circle to draw.
    */
    virtual void draw(const Circle* circle) const;

    /**
    * Draws the Segment.
    * @param segment The Segment to draw.
    */
    virtual void draw(const Segment* segment) const;

    /**
    * Draws the Triangle.
    * @param triangle The Triangle to draw.
    */
    virtual void draw(const Triangle* triangle) const;

    /**
    * Draws the Polygon.
    * @param polygon The Polygon to draw.
    */
    virtual void draw(const Polygon* polygon) const;
};

#endif
