#ifndef POLYGON_H
#define POLYGON_H

#include "Shape.hpp"
#include <vector>
#include <cmath>

using std::string;

/**
*   Represent a Polygon
*   It's a Shape
**/
class Polygon : public Shape
{
protected:

    /**
    * Array of Vector2D for store points of the Polygon
    **/
    std::vector<Vector2D> _points;

public:

    /**
    * Polygon constructor
    * @param color the color of the Polygon
    **/
    Polygon(const Color & color = Color::getColor("black"));

    /**
    * Function to add a point on the Polygon
    * @param point point to add
    **/
    void addPoint(const Vector2D & point);

    /**
    * Function to get a point of _points with index
    * @Param index the index of point to get
    * @return Vector2D the point
    **/
    const Vector2D getPoint(int index) const;

    /**
    * Function to get the size of _points
    * @return int the size of _points
    **/
    const int getPointsSize() const;

    /**
    * Draws the Polygon using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the Polygon.
    */
    void draw(DrawingVisitor* visitor) const;

    /**
    * Returns a string that represents the Polygon.
    * @return The string representing the Polygon.
    */
    operator string() const;

    /**
    * Saves the Polygon.
    * @param saveVisitor The SaveVisitor to use to save the Polygon.
    */
    void save(const SaveVisitor* saveVisitor, const string & filename) const;

    /**
    * Translate the Polygon using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new Polygon after Translation
    */
    Shape* translation(const Vector2D & translationVector) const;

    /**
    * Apply an homothety on the Polygon.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new Polygon after homothety
    */
    Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio) const;

    /**
    * Rotates the Polygon.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new Polygon after rotation
    */
    Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) const;

    /**
    * Returns the area of the Polygon.
    * @return The area of the Polygon.
    */
    double getArea() const;

    friend ostream & operator << (ostream & os, const Polygon & polygon);
};

extern ostream & operator << (ostream & os, const Polygon & polygon);

#endif
