#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.hpp"
#include <cmath>

using std::string;

/**
*   Represent a Triangle
*   It's a Shape
**/
class Triangle : public Polygon 
{
private:
    //The vector of point inherit of Polygon
    
public:
    /**
    * Triangle constructor
    * @param firstPoint the firstPoint of the Triangle
    * @param secondPoint the secondPoint of the Triangle
    * @param thirdPoint the thirdPoint of the Triangle
    * @param color the color of the Triangle
    */
    Triangle(const Vector2D & firstPoint, const Vector2D & secondPoint, const Vector2D & thirdPoint, const Color & color = Color::getColor("black"));

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
    *   Getter of the third point
    *   @return Vector2D The third point
    **/
    const Vector2D getThirdPoint() const;

    /**
    * Draws the Triangle using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the Triangle.
    */
    void draw(DrawingVisitor* visitor) const;

    /**
    * Returns a string that represents the Triangle.
    * @return The string representing the Triangle.
    */
    operator string() const;

    /**
    * Saves the Triangle.
    * @param saveVisitor The SaveVisitor to use to save the Triangle.
    */
    void save(const SaveVisitor* saveVisitor, const string & filename) const;

    /**
    * Translate the Triangle using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new Triangle after the translation
    */
    Shape* translation(const Vector2D & translationVector) const;

    /**
    * Apply an homothety on the Triangle.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new triangle after the homotethy
    */
    Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio) const;

    /**
    * Rotates the Triangle.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new Triangle after the rotation
    */
    Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) const;

    /**
    * Returns the area of the Triangle.
    * @return The area of the Triangle.
    */
    double getArea() const;

    friend ostream  & operator << (ostream & os, const Triangle & triangle);
};

extern ostream  & operator << (ostream & os, const Triangle & triangle);

#endif
