#include <iostream>
#include "../Geometry/Vector2D.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    Vector2D a = Vector2D(1, 2);
    Vector2D b = Vector2D(3, 4);
    
    cout << "----- Basics operations -----" << endl << endl;
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "-a = " << -a << endl;
    
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * 3 = " << a * 3 << endl;
    
    a += b;
    cout << "a += b; a = " << a << endl;
    
    a *= 3;
    cout << "a *= 3; a = " << a << endl;
    
    a -= b;
    cout << "a -= b; a = " << a << endl;
    
    cout << endl << "----- Geometrics operations -----" << endl << endl;
    
    a = Vector2D(1, 3);
    b = Vector2D(2, 0);
    Vector2D c = Vector2D(2, 2);
    Vector2D d = Vector2D(3, 3);
    Vector2D point1 = Vector2D(1, 2);
    Vector2D point2 = Vector2D(2, 0);
    RadianAngle pi = RadianAngle(M_PI);
    RadianAngle halfPi = RadianAngle(M_PI/2);
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
    cout << "pi = " << pi.getValue() << endl;
    cout << "invariant point 1 = " << point1 << endl;
    cout << "invariant point 2 = " << point2 << endl;
    
    a.homothety(point1, 2);
    cout << "a.homothety(point1, 3) = " << a << endl;
    
    b.rotation(point1, pi);
    cout << "b.rotation(point1, pi) = " << b << endl;
    
    c.homothety(point2, -3);
    cout << "c.homothety(point2, -3) = " << c << endl;
    
    d.rotation(point2, halfPi);
    cout << "d.rotation(point2, pi/2) = " << d << endl;
    
    return 0;
}
