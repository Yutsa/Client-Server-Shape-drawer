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
    
//=============== Variables Init ===============//
    
    Vector2D center(50, 50), beginSeg(100, 100), endSeg(100, 150), point1(200, 200), point2(250, 250), point3(300, 200);
    Vector2D point4(300, 300), point5(400, 300), point6(300, 400), point7(450, 450), point8(500, 500);
    Vector2D centerRotation(100, 100);
    Vector2D vectorTranslation(100, 0);
    Vector2D invariantPoint(50, 50);
    double ratio = 1;
    
    RadianAngle angle(M_PI/2);
    
    Segment S(beginSeg, endSeg, Color::getColor("blue"));
    Circle C(center, 50, Color::getColor("red"));
    Triangle T(point1, point2, point3, Color::getColor("green"));
    Polygon P(Color::getColor("black"));
    
    Shape *C1, *C2, *C3, *C4, *C5;
    Shape *T1, *T2;
    
    P.addPoint(point4);
    P.addPoint(point5);
    P.addPoint(point7);
    P.addPoint(point6);
    
//=============== Start Connexion ===============//
    
    ServerDrawer *serverDrawer = new ServerDrawer();
    sleep(1);
    
//=============== Draw Circles ===============//
    
    C.draw(serverDrawer);
    sleep(1);
    
    C1 = C.rotation(centerRotation, angle);
        
    C1->draw(serverDrawer);
    sleep(1);
    
    C2 = C1->rotation(centerRotation, angle);
    
    C2->draw(serverDrawer);
    sleep(1);
    
    C3 = C2->rotation(centerRotation, angle);
        
    C3->draw(serverDrawer);
    sleep(1);
    
    C3->setColor(Color::getColor("blue"));
    C4 = C3->homothety(center, 2);
    
    C4->draw(serverDrawer);
    sleep(1);
    
    C5 = C4->translation(vectorTranslation);
    
    C5->draw(serverDrawer);
    sleep(1);
   
//=============== Draw Segment ===============//
    
    S.draw(serverDrawer);
    cout << "Segment drawn" << endl;
    
    sleep(1);
    
    T.draw(serverDrawer);
    cout << "Triangle drawn" << endl;
    
    sleep(1);
    
    T1 = T.translation(vectorTranslation);
    
    T1->draw(serverDrawer);
    cout << "Triangle drawn" << endl;
    
    sleep(1);
    
    T2 = T.homothety(invariantPoint, ratio);
    
    T2->draw(serverDrawer);
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
