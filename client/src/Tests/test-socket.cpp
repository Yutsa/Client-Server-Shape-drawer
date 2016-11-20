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
    Vector2D center(20, 30), beginSeg(100, 100), endSeg(100, 150), point1(200, 200), point2(250, 250), point3(300, 200);
    Vector2D point4(300, 300), point5(400, 300), point6(300, 400), point7(450, 450), point8(500, 500);
    
    Segment S(beginSeg, endSeg, Color::getColor("blue"));
    Circle C(center, 50, Color::getColor("red"));
    Triangle T(point1, point2, point3, Color::getColor("green"));
    Polygon P(Color::getColor("black"));
    
    P.addPoint(point4);
    P.addPoint(point5);
    P.addPoint(point6);
    P.addPoint(point7);
    
    ServerDrawer *serverDrawer = new ServerDrawer();
    
    C.draw(serverDrawer);
    cout << "Circle drawn" << endl;
    
    sleep(1);
    
    S.draw(serverDrawer);
    cout << "Segment drawn" << endl;
    
    sleep(1);
    
    T.draw(serverDrawer);
    cout << "Triangle drawn" << endl;
    
    sleep(1);
    
    P.draw(serverDrawer);
    cout << "Polygon drawn" << endl;
    
    P.addPoint(point8);
    
    sleep(1);
    
    P.draw(serverDrawer);
    cout << "New polygon drawn" << endl;
    
    return 0;
}
