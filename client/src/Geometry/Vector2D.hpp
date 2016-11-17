#include <iostream>

using std::string;
using std::ostream;

class Vector2D
{
private:
    double _x;
    double _y;

public:
    Vector2D(const double & x = 0, const double & y = 0);
    virtual ~Vector2D();
    double getX() const { return _x;}
    double getY() const { return _y;}
    void setX(double x) { _x = x;}
    void setY(double y) { _y = y;}

    // Operators
    operator string() const;
    const Vector2D operator+ (const Vector2D & rhv) const;
    const Vector2D operator* (const double & a) const;
    const Vector2D operator- () const;
    friend ostream & operator<<(ostream & os, const Vector2D & vector);
};

// To be able to write u * a and a * u
extern const Vector2D operator*(const double & a, const Vector2D & vector);
extern ostream & operator<<(ostream & os, const Vector2D & vector);
