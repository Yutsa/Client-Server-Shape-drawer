#ifndef SERVER_DRAWER_H
#define SERVER_DRAWER_H

#include <iostream>
#include "../Network/Socket.hpp"
#include "DrawingVisitor.hpp"

#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"

class ServerDrawer : public DrawingVisitor
{
public:
    ServerDrawer();
    virtual ~ServerDrawer();
    /**
    * Draws the Circle.
    * @param circle The Circle to draw.
    */
    void draw(const Circle* circle) const;

    /**
    * Draws the Segment.
    * @param segment The Segment to draw.
    */
    void draw(const Segment* segment) const;

    /**
    * Draws the Triangle.
    * @param triangle The Triangle to draw.
    */
    void draw(const Triangle* triangle) const;

    /**
    * Draws the Polygon.
    * @param polygon The Polygon to draw.
    */
    void draw(const Polygone* polygon) const;
};

#endif
