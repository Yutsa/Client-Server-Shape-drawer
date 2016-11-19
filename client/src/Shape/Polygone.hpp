#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
#include "Shape.hpp"
#include <vector>
#include <cmath>

#include "../Visitor/SaveVisitor.hpp"
#include "../Visitor/ServerDrawer.hpp"

using std::string;

/**
*   Represent a Polygone
*   It's a Shape
**/
class Polygone : public Shape
{
private:

    /**
    *   Array of Vector2D for store points of the Polygone
    **/
    std::vector<Vector2D> _points;

public:

    /**
    *   Polygone constructors
    **/
    Polygone();

    /**
    *   Function to add a point on the Polygone
    *   @param point point to add
    **/
    virtual void addPoint(const Vector2D & point);

    /**
    * Draws the Polygone using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the Polygone.
    */
    virtual void draw(const DrawingVisitor* visitor) const;

    /**
    * Returns a string that represents the Polygone.
    * @return The string representing the Polygone.
    */
    virtual operator string() const;

    /**
    * Saves the Polygone.
    * @param saveVisitor The SaveVisitor to use to save the Polygone.
    */
    virtual void save(const SaveVisitor* saveVisitor) const;

    /**
    * Translate the Polygone using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new Polygone after Translation
    */
    virtual Shape* translation(const Vector2D & translationVector) const;

    /**
    * Apply an homothety on the Polygone.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new Polygone after homothety
    */
    virtual Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio) const;

    /**
    * Rotates the Polygone.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new Polygone after rotation
    */
    virtual Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) const;

    /**
    * Returns the area of the Polygone.
    * @return The area of the Polygone.
    */
    virtual double getArea() const;
};

#endif