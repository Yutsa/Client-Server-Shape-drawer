#include <iostream>
#include <string>

using std::string;

/**
* This class is the base class for every Shape.
*/

class Shape
{

//TODO: Must implement the shape color.
public:
    /**
    * Draws the Shape using a DrawingVisitor.
    * @param visitor The DrawingVisitor to use to draw the shape.
    */
    virtual void draw(const DrawingVisitor* visitor) const = 0;

    /**
    * Returns a string that represents the Shape.
    * @return The string representing the Shape.
    */
    virtual operator string() const = 0;

    /**
    * Saves the Shape.
    * @param saveVisitor The SaveVisitor to use to save the shape.
    */
    virtual void save(const SaveVisitor* saveVisitor) const = 0;

    /**
    * Translate the shape using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    */
    virtual void translation(const Vector2D & translationVector) = 0;

    /**
    * Apply an homothety on the shape.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    */
    virtual void homothety(const Vector2D & invariantPoint,
        double homothetyRatio) = 0;

    /**
    * Rotates the shape.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    */
    virtual void rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle) = 0;

    /**
    * Returns the area of the Shape.
    * @return The area of the Shape.
    */
    virtual double getArea() const = 0;
};
