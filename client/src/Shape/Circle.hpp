#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.hpp"

using std::string;

class Vector2D;
/**
*   Represent a Circle
*   It's a Shape
**/
class Circle : public Shape
{
private:
    /**
    *   The center of the Circle
    **/
    Vector2D _center;
    /**
    *   The diameter of the Circle
    **/
    double _diameter;
public:
    /**
    * Circle constructor
    * @param center The center point of the Circle
    * @param diameter The diameter of the Circle
    * @param color The color of the Circle
    **/
    Circle(const Vector2D & center, const double & diameter, const Color & color = Color::getColor("black"));

    /**
    * Gets the center of the circle
    * @return Vector2D the center of the circle
    **/
    const Vector2D getCenter() const;

    /**
    * Gets the diameter of the circle
    * @return double the diameter of the circle
    **/
    const double getDiameter() const;

    /**
    * Draws the Circle using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the Circle.
    */
    void draw(DrawingVisitor* visitor) const;

    /**
    * Returns a string that represents the Circle.
    * @return The string representing the Circle.
    */
    operator string() const;

    /**
    * Saves the Circle.
    * @param saveVisitor The SaveVisitor to use to save the Circle.
    */
    void save(const SaveVisitor* saveVisitor, const string & filename) const;

    /**
    * Translate the Circle using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new circle after Translation
    */
    Shape* translation(const Vector2D & translationVector) const;

    /**
    * Apply an homothety on the Circle.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new circle after homothety
    */
    Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio) const;

    /**
    * Rotates the Circle.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new circle after rotation
    */
    Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) const;

    /**
    * Returns the area of the Circle.
    * @return The area of the Circle.
    */
    double getArea() const;

    friend ostream & operator<<(ostream & os, const Circle & circle);
};

extern ostream & operator<<(ostream & os, const Circle & circle);

#endif
