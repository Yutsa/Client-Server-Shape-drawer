#include "../Network/Socket.hpp"
#include "../Visitor/ServerDrawer.hpp"
#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"
#include "../Shape/ComposedShape.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{    
    //=============== Variables Init ===============//

    Vector2D center(50, 50);
    Vector2D beginSeg(300, 100), endSeg(400, 150);
    Vector2D point1(450, 200), point2(500, 270), point3(500, 200);
    Vector2D point4(600, 150), point5(650, 300), point6(570, 450), point7(450, 450), point8(500, 500);
    Vector2D centerRotation(100, 100), centerRotation2(250, 150), centerRotation3(500, 100);
    Vector2D vectorTranslation(100, 0), vectorTranslation2(300, -50);
    double ratio = 1.5, ratio2 = 2;

    RadianAngle pi(M_PI);
    
    //=============== Shape Init ===============//
    
    Shape* S = new Segment(beginSeg, endSeg, Color::getColor("blue"));
    
    Shape* C = new Circle(center, 50, Color::getColor("red"));
    
    Shape* T = new Triangle(point1, point2, point3, Color::getColor("green"));
    
    Polygon* P1 = new Polygon(Color::getColor("black"));
    P1->addPoint(point5);
    P1->addPoint(point6);
    P1->addPoint(point8);
    P1->addPoint(point7);
    P1->addPoint(point4);
    Shape* P = P1;

//=============== Start Connexion ===============//

    ServerDrawer *serverDrawer = new ServerDrawer();

//=============== Draw Circles ===============//

    C->draw(serverDrawer);

    C = C->rotation(centerRotation, pi);
    C->draw(serverDrawer);

    C = C->homothety(center, ratio);
    C->draw(serverDrawer);

    C = C->translation(vectorTranslation);
    C->draw(serverDrawer);

//=============== Draw Segment ===============//

    S->draw(serverDrawer);

    S = S->rotation(centerRotation2, pi/2);
    S->draw(serverDrawer);

    S = S->homothety(centerRotation2, ratio2);
    S->draw(serverDrawer);

    S = S->translation(vectorTranslation);
    S->draw(serverDrawer);

//=============== Draw Triangle ===============//

    T->draw(serverDrawer);
    
    T = T->rotation(centerRotation3, pi/2);
    T->draw(serverDrawer);

    T = T->translation(vectorTranslation);
    T->draw(serverDrawer);

    T = T->homothety(point1, ratio);
    T->draw(serverDrawer);

//=============== Draw Polygon ===============//

    P->draw(serverDrawer);

    P = P->translation(vectorTranslation2);
    P->draw(serverDrawer);

    P = P->homothety(point1, ratio);
    P->draw(serverDrawer);
    
    P = P->rotation(point3, pi/4);
    P->draw(serverDrawer);
    
    return 0;
}