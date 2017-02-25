#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include "Shape.hpp"
#include <cmath>

//#include "../Visitor/SaveVisitor.hpp"
//#include "../Visitor/ServerDrawer.hpp"
#include "../Visitor/DrawingVisitor.hpp"
#include "../Visitor/SaveTextVisitor.hpp"

using std::string;

/**
* Represent a Segment
* It's a Shape
**/
class Segment : public Shape
{
private:
    /**
    * The first point of the Segment
    **/
    Vector2D _firstPoint;
    /**
    * The second point of the Segment
    **/
    Vector2D _secondPoint;
public:

    /**
    * Segment constructor with color
    * @param firstPoint the firstPoint of the Segment
    * @param secondPoint the secondPoint of the Segment
    * @param color the color of the Segment
    **/
    Segment(const Vector2D & firstPoint, const Vector2D & secondPoint, const Color & color = Color::getColor("black"));

    /**
    *   Getter of the first point
    *   @return Vector2D The first point
    **/
    const Vector2D getFirstPoint() const;

    /**
    *   Getter of the second point
    *   @return Vector2D The second point
    **/
    const Vector2D getSecondPoint() const;

    /**
    * Draws the Segment using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the Segment.
    */
    void draw(DrawingVisitor* visitor) const;

    /**
    * Returns a string that represents the Segment.
    * @return The string representing the Segment.
    */
    operator string() const;

    /**
    * Saves the Segment.
    * @param saveVisitor The SaveVisitor to use to save the Segment.
    */
    void save(const SaveVisitor* saveVisitor, const string & filename) const;

    /**
    * Translate the Segment using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new Segment after the translation
    */
    Shape* translation(const Vector2D & translationVector) const;

    /**
    * Apply an homothety on the Segment.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new Segment after the homothety
    */
    Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio) const;

    /**
    * Rotates the Segment.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new Segment after the rotation
    */
    Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) const;

    /**
    * Returns the area of the Segment.
    * @return The area of the Segment.
    */
    double getArea() const;

    friend ostream & operator << (ostream & os, const Segment & segment);
};

extern ostream & operator << (ostream & os, const Segment & segment);

#endif
