#ifndef SEGMENT_H
#define SEGMENT_H

#include <iostream>
#include "Shape.hpp"
#include <cmath>

#include "../Visitor/SaveVisitor.hpp"
#include "../Visitor/ServerDrawer.hpp"

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
    * Segment constructor
    * @param firstPoint the firstPoint of the Segment
    * @param secondPoint the secondPoint of the Segment
    **/
    Segment(Vector2D firstPoint, Vector2D secondPoint);
    
    /**
    * Segment constructor with color
    * @param firstPoint the firstPoint of the Segment
    * @param secondPoint the secondPoint of the Segment
    * @param color the color of the Segment
    **/
    Segment(Vector2D firstPoint, Vector2D secondPoint, Color color);

    /**
    * Draws the Segment using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the Segment.
    */
    virtual void draw(const DrawingVisitor* visitor) const;

    /**
    * Returns a string that represents the Segment.
    * @return The string representing the Segment.
    */
    virtual operator string() const;

    /**
    * Saves the Segment.
    * @param saveVisitor The SaveVisitor to use to save the Segment.
    */
    virtual void save(const SaveVisitor* saveVisitor, const string & filename) const;

    /**
    * Translate the Segment using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new Segment after the translation
    */
    virtual Shape* translation(const Vector2D & translationVector) const;

    /**
    * Apply an homothety on the Segment.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new Segment after the homothety
    */
    virtual Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio) const;

    /**
    * Rotates the Segment.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new Segment after the rotation
    */
    virtual Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) const;

    /**
    * Returns the area of the Segment.
    * @return The area of the Segment.
    */
    virtual double getArea() const;

    friend ostream & operator << (ostream & os, const Segment & segment);
};

extern ostream & operator << (ostream & os, const Segment & segment);

#endif
