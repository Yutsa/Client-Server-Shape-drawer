#include <iostream>
#include "../Geometry/Vector2D.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    Vector2D a = Vector2D(3, 4);
    Vector2D b = Vector2D(5, 9);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a + b = " << a + b << endl;
    cout << "a * 3 = " << a * 3 << endl;
    cout << "-a = " << -a << endl;
    return 0;
}
