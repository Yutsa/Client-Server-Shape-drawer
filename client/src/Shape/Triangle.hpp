#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>
#include "Shape.hpp"
#include <cmath>

#include "../Visitor/SaveVisitor.hpp"
#include "../Visitor/ServerDrawer.hpp"

using std::string;

/**
*   Represent a Triangle
*   It's a Shape
**/
class Triangle : public Shape
{
private:
    /**
    *   The first point of the Triangle
    **/
    Vector2D _firstPoint;
    /**
    *   The second point of the Triangle
    **/
    Vector2D _secondPoint;
    /**
    *   The third point of the Triangle
    **/
    Vector2D _thirdPoint;
public:
    /**
    *   Triangle constructors
    *   @param firstPoint the firstPoint of the Triangle
    *   @param secondPoint the secondPoint of the Triangle
    *   @param thirdPoint the thirdPoint of the Triangle
    **/
    Triangle(Vector2D firstPoint, Vector2D secondPoint, Vector2D thirdPoint, Color color);

    /**
    * Draws the Triangle using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the Triangle.
    */
    virtual void draw(const DrawingVisitor* visitor) const;

    /**
    * Returns a string that represents the Triangle.
    * @return The string representing the Triangle.
    */
    virtual operator string() const;

    /**
    * Saves the Triangle.
    * @param saveVisitor The SaveVisitor to use to save the Triangle.
    */
    virtual void save(const SaveVisitor* saveVisitor) const;

    /**
    * Translate the Triangle using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new Triangle after the translation
    */
    virtual Shape* translation(const Vector2D & translationVector) const;

    /**
    * Apply an homothety on the Triangle.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new triangle after the homotethy
    */
    virtual Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio) const;

    /**
    * Rotates the Triangle.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new Triangle after the rotation
    */
    virtual Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) const;

    /**
    * Returns the area of the Triangle.
    * @return The area of the Triangle.
    */
    virtual double getArea() const;

    friend ostream  & operator << (ostream & os, const Triangle & triangle);
};

extern ostream  & operator << (ostream & os, const Triangle & triangle);

#endif
