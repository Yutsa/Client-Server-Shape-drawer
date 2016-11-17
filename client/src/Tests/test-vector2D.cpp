#include <iostream>
#include "../Geometry/Vector2D.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    Vector2D a = Vector2D(1, 2);
    Vector2D b = Vector2D(3, 4);
    
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
    return 0;
}
