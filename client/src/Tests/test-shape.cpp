#include "../Shape/Circle.hpp"

using std::cout;
using std::endl;
using std::string;

int main()
{
    Vector2D center1 = Vector2D(10, 10);
    Circle C1 = Circle(center1, 20);
    
    cout << C1 << endl;
    
    return 0;
}
