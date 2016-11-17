#include <iostream>

class Circle;
class Segment;
class Triangle;
class Polygon;

class SaveVisitor
{
public:
    virtual void save(Circle* circle) = 0;
    virtual void save(Segment* segment) = 0;
    virtual void save(Triangle* triangle) = 0;
    virtual void save(Polygon* polygon) = 0;
};
