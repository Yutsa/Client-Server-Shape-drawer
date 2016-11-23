#ifndef QT_DRAWER_H
#define QT_DRAWER_H

#include <QApplication>
#include <QtGui>

#include "DrawingVisitor.hpp"

#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"

/**
* This class is the drawer that implement a way to draw shapes using Qt
*/

class QtDrawer : public DrawingVisitor
{
private:
    QApplication _app;

	QGraphicsScene _scene;

	QGraphicsView _vue;

    QPen _pen;

public:
    QtDrawer(int argc, char* argv[]);
    virtual ~QtDrawer();
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
    void draw(const Polygon* polygon) const;

    /**
    * Draws the Shape.
    * @param shape The Shape to draw.
    */
    virtual void draw(const Shape* shape) const;
};

#endif
