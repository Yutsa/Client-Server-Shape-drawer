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
*   Represent a Polygon
*   It's a Shape
**/
class Polygon : public Shape
{
private:

    /**
    *   Array of Vector2D for store points of the Polygon
    **/
    std::vector<Vector2D> _points;

public:

    /**
    * Polygon constructor
    * @param color the color of the Polygon
    **/
    Polygon(Color color);
    
    /**
    * Polygon default constructor
    **/
    Polygon();

    /**
    * Function to add a point on the Polygon
    * @param point point to add
    **/
    virtual void addPoint(const Vector2D & point);

    /**
    * Draws the Polygon using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the Polygon.
    */
    virtual void draw(const DrawingVisitor* visitor) const;

    /**
    * Returns a string that represents the Polygon.
    * @return The string representing the Polygon.
    */
    virtual operator string() const;

    /**
    * Saves the Polygon.
    * @param saveVisitor The SaveVisitor to use to save the Polygon.
    */
    virtual void save(const SaveVisitor* saveVisitor, const string & filename) const;

    /**
    * Translate the Polygon using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new Polygon after Translation
    */
    virtual Shape* translation(const Vector2D & translationVector) const;

    /**
    * Apply an homothety on the Polygon.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new Polygon after homothety
    */
    virtual Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio) const;

    /**
    * Rotates the Polygon.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new Polygon after rotation
    */
    virtual Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) const;

    /**
    * Returns the area of the Polygon.
    * @return The area of the Polygon.
    */
    virtual double getArea() const;

    friend ostream & operator << (ostream & os, const Polygon & polygon);
};

extern ostream & operator << (ostream & os, const Polygon & polygon);

#endif
