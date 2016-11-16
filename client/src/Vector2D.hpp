#include <iostream>

using std::string;

class Vector2D
{
private:
    double _x;
    double _y;

public:
    Vector2D(double x, double y);
    virtual ~Vector2D();
    double getX() const { return _x;}
    double getY() const { return _y;}

    // Operators
    operator string() const;
    friend const Vector2D operator+ (const Vector2D & lhv,
        const Vector2D & rhv);
    friend const Vector2D operator* (const Vector2D & lhv,
        const Vector2D & rhv);
    friend const Vector2D operator- (const Vector2D & lhv,
        const Vector2D & rhv);
};

extern const Vector2D operator+ (const Vector2D & lhv,
    const Vector2D & rhv);
extern const Vector2D operator* (const Vector2D & lhv,
    const Vector2D & rhv);
extern const Vector2D operator- (const Vector2D & lhv,
    const Vector2D & rhv);
