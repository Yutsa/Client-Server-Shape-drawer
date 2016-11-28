#ifndef SAVE_TEXT_VISITOR_H
#define SAVE_TEXT_VISITOR_H

#include "SaveVisitor.hpp"

using std::string;

/**
* This class implements a way to save a shape in a simple text format.
*/
class SaveTextVisitor : public SaveVisitor
{
public:
    SaveTextVisitor();
    virtual ~SaveTextVisitor();
    /**
    * Saves the Circle.
    * @param circle The Circle to save.
    */
    void save(const Circle* circle, const string & filename) const;
    /**
    * Saves the Segment.
    * @param segment The Segment to save.
    */
    void save(const Segment* segment, const string & filename) const;
    /**
    * Saves the Triangle.
    * @param triangle The Triangle to save.
    */
    void save(const Triangle* triangle, const string & filename) const;
    /**
    * Saves the Polygon.
    * @param polygon The Polygon to save.
    */
    void save(const Polygon* polygon, const string & filename) const;

    /**
    * Saves the Shape
    * @param shape The Shape to save.
    */
    void save(const Shape* shape, const string & filename) const;
};

#endif
