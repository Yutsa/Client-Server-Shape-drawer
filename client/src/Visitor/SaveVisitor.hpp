#ifndef SAVE_VISITOR_H
#define SAVE_VISITOR_H

#include <iostream>

using std::string;

class Circle;
class Segment;
class Triangle;
class Polygon;
class Shape;

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
    virtual void save(const Circle* circle, const string & filename) const = 0;
    /**
    * Saves the Segment.
    * @param segment The Segment to save.
    */
    virtual void save(const Segment* segment, const string & filename) const = 0;
    /**
    * Saves the Triangle.
    * @param triangle The Triangle to save.
    */
    virtual void save(const Triangle* triangle, const string & filename) const = 0;
    /**
    * Saves the Polygon.
    * @param polygon The Polygon to save.
    */
    virtual void save(const Polygon* polygon, const string & filename) const = 0;

    /**
    * Saves the Shape
    * @param shape The Shape to save.
    */
    virtual void save(const Shape* shape, const string & filename) const = 0;
};

#endif
