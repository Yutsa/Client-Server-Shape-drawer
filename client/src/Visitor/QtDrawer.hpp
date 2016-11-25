#ifndef QT_DRAWER_H
#define QT_DRAWER_H

#include <QApplication>
#include <QtGui>

#include "DrawingVisitor.hpp"

#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"
#include "../Shape/ComposedShape.hpp"

/**
* This class is the drawer that implement a way to draw shapes using Qt
*/

class QtDrawer : public DrawingVisitor
{
private:
    QApplication* _app;

    QGraphicsScene* _scene;

    QGraphicsView* _vue;

    QPen* _pen;

public:
    QtDrawer();
    virtual ~QtDrawer();

    // TODO: None of these methods should be const as they modify
    // The instance.
    
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
    void draw(const Shape* shape) const;

    /**
     * Add the Circle to the scene.
     * @param circle The Circle to add to the scene.
     */
    void addToScene(const Circle* circle) const;

    /**
     * Add the Segment to the scene.
     * @param segment The Segment to add to the scene.
     */
    void addToScene(const Segment* segment) const;

    /**
     * Add the Triangle to the scene.
     * @param triangle The Triangle to add to the scene.
     */
    void addToScene(const Triangle* triangle) const;

    /**
     * Add the Polygon to the scene.
     * @param polygon The Polygon to add to the scene.
     */
    void addToScene(const Polygon* polygon) const;

    /**
     * Add the ComposedShape to the scene.
     * @param composedShape The ComposedShape to add to the scene.
     */
    void addToScene(const ComposedShape* composedShape) const;

    /**
     * Sets the scene to the view and display it.
     */
    void displayWindow() const;
    
};

#endif
