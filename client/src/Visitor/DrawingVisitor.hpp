#include <iostream>

class Circle;
class Segment;
class Triangle;
class Polygon;

class DrawingVisitor
{
public:
    virtual void draw(Circle* circle) = 0;
    virtual void draw(Segment* segment) = 0;
    virtual void draw(Triangle* triangle) = 0;
    virtual void draw(Polygon* polygon) = 0;
};
