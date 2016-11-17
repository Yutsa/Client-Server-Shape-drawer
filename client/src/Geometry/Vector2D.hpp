#include <iostream>

using std::string;
using std::ostream;

/**
* Class represents a point in space
*/
class Vector2D
{
private:
    /**
    * Member, abscissa of the point
    */
    double _x;
    /**
    * Member, ordonate of the point
    */
    double _y;

public:
    /**
    * Constructor
    * @param x double for the abscissa, 0 default
    * @param y double for the ordonate, 0 default
    */
    Vector2D(const double & x = 0, const double & y = 0);
    
    /**
    * Destructor
    */
    virtual ~Vector2D();
    
    /**
    * Gets $_x (abscissa)
    */
    double getX() const { return _x;}
    /**
    * Gets $_y (ordonate)
    */
    double getY() const { return _y;}
    void setX(double x) { _x = x;}
    void setY(double y) { _y = y;}

    // Operators
    
    /**
    * Operator cast to string
    */
    operator string() const;
    
    /**
    * Allows to add two vectors
    * @param rhv vector to add
    * @return Vector2D which is the result of addition
    */
    const Vector2D operator+ (const Vector2D & rhv) const;
    
    /**
    * Allows to multiply a vector by a constant
    * @param a double to multiply
    * @return Vector2D which is the result of product
    */
    const Vector2D operator* (const double & a) const;
    
    /**
    * Gets the opposite of a vector
    * @return Vector2D 
    */
    const Vector2D operator- () const;
    
    /**
    * Sends a string of vector to a stream
    * @param os ostream 
    * @param vector vector have to print 
    * @return ostream to send to the output
    */
    friend ostream & operator<<(ostream & os, const Vector2D & vector);
};

// To be able to write u * a and a * u
extern const Vector2D operator*(const double & a, const Vector2D & vector);
extern ostream & operator<<(ostream & os, const Vector2D & vector);
