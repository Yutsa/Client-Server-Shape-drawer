#include <iostream>
#include <Shape.hpp>

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
    *   The diamater of the Circle
    **/
    double _diamater;
public:
    /**
    *   Circle constructors
    *   @param x The coordinate x of the center point of the Circle
    *   @param y The coordinate x of the center point of the Circle
    *   @param diameter The diameter of the Circle
    **/
    //Circle(double x, double y, double diameter);
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
    virtual void save(const SaveVisitor* saveVisitor) const;

    /**
    * Translate the Circle using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    */
    virtual void translation(const Vector2D & translationVector);

    /**
    * Apply an homothety on the Circle.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    */
    virtual void homothety(const Vector2D & invariantPoint,
        double homothetyRatio);

    /**
    * Rotates the Circle.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    */
    virtual void rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle);

    /**
    * Returns the area of the Circle.
    * @return The area of the Circle.
    */
    virtual double getArea() const;
};
