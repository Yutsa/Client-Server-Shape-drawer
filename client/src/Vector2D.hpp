#include <iostream>

class Vector2D
{
private:
    double _x;
    double _y;
public:
    Vector2D(double x, double y);
    virtual ~Vector2D();
    operator string() const;
    friend const Vector2D operator+ (const Vector2D & lhv,
        const Vector2D & rhv);
    friend const Vector2D operator* (const Vector2D & lhv,
        const Vector2D & rhv);
    friend const Vector2D operator- (const Vector2D & lhv,
        const Vector2D & rhv);
    const Vector2D & add(const Vector2D & lhv,
        const Vector2D & rhv);
    const Vector2D & multiply(const Vector2D & lhv,
        const Vector2D & rhv);
    const Vector2D & substract(const Vector2D & lhv,
        const Vector2D & rhv);
}

extern const Vector2D operator+ (const Vector2D & lhv,
    const Vector2D & rhv);
extern const Vector2D operator* (const Vector2D & lhv,
    const Vector2D & rhv);
extern const Vector2D operator- (const Vector2D & lhv,
    const Vector2D & rhv);
