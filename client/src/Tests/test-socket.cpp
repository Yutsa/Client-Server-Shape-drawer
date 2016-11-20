#include "../Network/Socket.hpp"
#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"


using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
    Vector2D center(20, 30), beginSeg(100, 100), endSeg(100, 150);
    
    Segment S(beginSeg, endSeg, Color::getColor("blue"));
    Circle C(center, 50, Color::getColor("red"));
    
    ServerDrawer *serverDrawer = new ServerDrawer();
    
    C.draw(serverDrawer);
    cout << "Circle drawn" << endl;
    
    sleep(1);
    
    S.draw(serverDrawer);
    cout << "Segment drawn" << endl;
    
    return 0;
}
