#include <iostream>
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
    *   Circle constructors
    *   @param center The center point of the Circle
    *   @param diameter The diameter of the Circle
    **/
    Circle(Vector2D center, double diameter);

    /**
    * Draws the Circle using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the Circle.
    */
    virtual void draw(const DrawingVisitor* visitor) const;

    /**
    * Returns a string that represents the Circle.
    * @return The string representing the Circle.
    */
    virtual operator string() const;

    /**
    * Saves the Circle.
    * @param saveVisitor The SaveVisitor to use to save the Circle.
    */
    //virtual void save(const SaveVisitor* saveVisitor) const;

    /**
    * Translate the Circle using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new circle after Translation
    */
    virtual Shape* translation(const Vector2D & translationVector) const;

    /**
    * Apply an homothety on the Circle.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new circle after homothety
    */
    virtual Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio) const;

    /**
    * Rotates the Circle.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new circle after rotation
    */
    virtual Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) const;

    /**
    * Returns the area of the Circle.
    * @return The area of the Circle.
    */
    virtual double getArea() const;
    
    friend ostream & operator<<(ostream & os, const Circle & circle);
};

extern ostream & operator<<(ostream & os, const Circle & circle);
