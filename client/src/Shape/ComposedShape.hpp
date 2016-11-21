#ifndef COMPOSEDSHAPE_H
#define COMPOSEDSHAPE_H

#include <iostream>
#include "Shape.hpp"
#include <vector>
#include <cmath>

#include "../Visitor/SaveVisitor.hpp"
#include "../Visitor/ServerDrawer.hpp"

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
    *   @param color the color of the ComposedShape
    **/
    ComposedShape(Color color);

    /**
    *   Function to add a point on the ComposedShape
    *   @param point point to add
    **/
    virtual void addShape(const Shape* shape);

    /**
    * Draws the ComposedShape using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the ComposedShape.
    */
    virtual void draw(const DrawingVisitor* visitor) const;

    /**
    * Returns a string that represents the ComposedShape.
    * @return The string representing the ComposedShape.
    */
    virtual operator string() const;

    /**
    * Saves the ComposedShape.
    * @param saveVisitor The SaveVisitor to use to save the ComposedShape.
    */
    virtual void save(const SaveVisitor* saveVisitor, const string & filename) const;

    /**
    * Translate the ComposedShape using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new ComposedShape after Translation
    */
    virtual Shape* translation(const Vector2D & translationVector) const;

    /**
    * Apply an homothety on the ComposedShape.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new ComposedShape after homothety
    */
    virtual Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio) const;

    /**
    * Rotates the ComposedShape.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new ComposedShape after rotation
    */
    virtual Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) const;

    /**
    * Returns the area of the ComposedShape.
    * @return The area of the ComposedShape.
    */
    virtual double getArea() const;

    friend ostream & operator << (ostream & os, const ComposedShape & composedShape);
};

extern ostream & operator << (ostream & os, const ComposedShape & composedShape);

#endif
