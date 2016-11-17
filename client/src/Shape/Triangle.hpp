#include <iostream>
#include <Shape.hpp>

using std::string;

class Vector2D;
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
    Vector2D _fistPoint;
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
    **/
    Triangle(Vector2D firstPoint, Vector2D secondPoint Vector2D thirdPoint);

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
    */
    virtual void translation(const Vector2D & translationVector);

    /**
    * Apply an homothety on the Triangle.
    * @param invariantPoint The center of the homothety.
    * @param homothetyRatio The ratio of the homothety.
    */
    virtual void homothety(const Vector2D & invariantPoint,
        const double & homothetyRatio);

    /**
    * Rotates the Triangle.
    * @param rotationCenter The center of the rotation.
    * @param rotationAngle The angle of the rotation.
    */
    virtual void rotation(const Vector2D & rotationCenter,
        const RadianAngle & rotationAngle);

    /**
    * Returns the area of the Triangle.
    * @return The area of the Triangle.
    */
    virtual double getArea() const;
};
