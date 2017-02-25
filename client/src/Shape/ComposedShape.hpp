#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H

#include "Shape.hpp"
#include <vector>
#include <cmath>

using std::string;

/**
*   Represent a ComposedShape
*   It's a Shape
**/
class ComposedShape : public Shape
{
private:

    /**
    *   Array of Vector2D for store points of the ComposedShape
    **/
    std::vector<Shape*> _shapes;

public:

    /**
    *   ComposedShape constructors
    **/
    ComposedShape(Color color = Color::getColor("black"));

    /**
    *   Function to add a point on the ComposedShape
    *   @param point point to add
    **/
    void addShape(Shape* shape);

    /**
    * Draws the ComposedShape using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the ComposedShape.
    */
    void draw(DrawingVisitor* visitor) const;

    /**
    * Returns a string that represents the ComposedShape.
    * @return The string representing the ComposedShape.
    */
    operator string() const;

    /**
    * Saves the ComposedShape.
    * @param saveVisitor The SaveVisitor to use to save the ComposedShape.
    */
    void save(const SaveVisitor* saveVisitor, const string & filename) const;

    /**
    * Translate the ComposedShape using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new ComposedShape after Translation
    */
    Shape* translation(const Vector2D & translationVector) const;

    /**
    * Apply an homothety on the ComposedShape.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new ComposedShape after homothety
    */
    Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio) const;

    /**
    * Rotates the ComposedShape.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new ComposedShape after rotation
    */
    Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) const;

    /**
    * Returns the area of the ComposedShape.
    * @return The area of the ComposedShape.
    */
    double getArea() const;

    /**
     * Returns the number of Shapes composing this ComposedShape.
     * @return The number of shapes composing this ComposedShape.
     */
    int getShapeNumber() const;

    /**
     * Returns the i-th shape in this ComposedShape
     * @return The i-th shape in this ComposedShape
     * @throws ShapeException if the index is wrong.
     */
    const Shape* getShape(unsigned int i) const;

    //TODO: operator[] to get the i-th shape.

    friend ostream & operator << (ostream & os, const ComposedShape & composedShape);
};

extern ostream & operator << (ostream & os, const ComposedShape & composedShape);

#endif
