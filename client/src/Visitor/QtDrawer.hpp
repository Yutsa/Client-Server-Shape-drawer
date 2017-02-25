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
    /**
     * The application to run.
     */
    QApplication* _app;

    /*
     * The scene where the shapes will be.
     */
    QGraphicsScene* _scene;

    /**
     * The view that will contain the scene.
     */
    QGraphicsView* _vue;

    /**
     * The QPen that will be used to draw the shapes.
     */
    QPen* _pen;

    QBrush* _brush;

public:
    QtDrawer();
    virtual ~QtDrawer();

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
    * @param shape The Shape to draw.
    */
    void draw(const Shape* shape);

    /**
     * Add the Circle to the scene.
     * @param circle The Circle to add to the scene.
     */
    void addToScene(const Circle* circle);

    /**
     * Add the Segment to the scene.
     * @param segment The Segment to add to the scene.
     */
    void addToScene(const Segment* segment);

    /**
     * Add the Triangle to the scene.
     * @param triangle The Triangle to add to the scene.
     */
    void addToScene(const Triangle* triangle);

    /**
     * Add the Polygon to the scene.
     * @param polygon The Polygon to add to the scene.
     */
    void addToScene(const Polygon* polygon);

    /**
     * Add the ComposedShape to the scene.
     * @param composedShape The ComposedShape to add to the scene.
     */
    void addToScene(const ComposedShape* composedShape);

    /**
     * Sets the scene to the view and display it.
     */
    void displayWindow();

};

#endif
