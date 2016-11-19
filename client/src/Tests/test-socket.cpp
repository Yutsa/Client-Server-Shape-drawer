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
    Color color = Color::getColor("red");
    Vector2D center(20, 30);
    Circle C(center, 50, color);
    
    ServerDrawer *serverDrawer = new ServerDrawer();
    
    C.draw(serverDrawer);
    
    return 0;
}
