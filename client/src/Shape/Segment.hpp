#include <iostream>
#include <Shape.hpp>

using std::string;

class Vector2D;
/**
*   Represent a Segment
*   It's a Shape
**/
class Segment : public Shape
{
private:
    /**
    *   The first point of the Segment
    **/
    Vector2D _fistPoint;
    /**
    *   The second point of the Segment
    **/
    Vector2D _secondPoint;
public:
    /**
    *   Segment constructors
    *   @param firstPoint the firstPoint of the Segment
    *   @param secondPoint the secondPoint of the Segment
    **/
    Segment(Vector2D firstPoint, Vector2D secondPoint);

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
    virtual void save(const SaveVisitor* saveVisitor) const;

    /**
    * Translate the Segment using a translation vector.
    * @param translationVector The translation vector to use for the
    *  translation.
    * @return Shape* the new Segment after the translation
    */
    virtual Shape* translation(const Vector2D & translationVector);

    /**
    * Apply an homothety on the Segment.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    * @return Shape* the new Segment after the homothety
    */
    virtual Shape* homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio);

    /**
    * Rotates the Segment.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    * @return Shape* the new Segment after the rotation
    */
    virtual Shape* rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle);

    /**
    * Returns the area of the Segment.
    * @return The area of the Segment.
    */
    virtual double getArea() const;
};