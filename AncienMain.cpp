#include "../Network/Socket.hpp"
#include "../Visitor/ServerDrawer.hpp"
#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"
#include "../Shape/ComposedShape.hpp"
#include "../Visitor/QtDrawer.hpp"

#include <QApplication>
#include <QtGui>


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
    QtDrawer *qtDrawer = new QtDrawer();

//=============== Draw Circles ===============//

    getchar();
    C->draw(serverDrawer);
    C->draw(qtDrawer);


    cout << "Press Enter to zoom on circle." << endl;
    getchar();
    C = C->homothety(center, ratio);
    C->draw(serverDrawer);

    cout << "Press Enter to do a translation on the circle." << endl;
    getchar();
    C = C->translation(vectorTranslation);
    C->draw(serverDrawer);

//=============== Draw Segment ===============//

    cout << "Press Enter to draw a segment" << endl;
    getchar();
    S->draw(serverDrawer);
    S->draw(qtDrawer);

    cout << "Press Enter to rotate the segment" << endl;
    getchar();
    S = S->rotation(centerRotation2, pi/2);
    S->draw(serverDrawer);

    cout << "Press Enter to zoom on the segment" << endl;
    getchar();
    S = S->homothety(centerRotation2, ratio2);
    S->draw(serverDrawer);

    cout << "Press Enter to do a translation on the segment" << endl;
    getchar();
    S = S->translation(vectorTranslation);
    S->draw(serverDrawer);

//=============== Draw Triangle ===============//

    cout << "Press Enter to draw a triangle" << endl;
    getchar();
    T->draw(serverDrawer);
    T->draw(qtDrawer);

    cout << "Press Enter to do a rotation on the triangle" << endl;
    getchar();
    T = T->rotation(centerRotation3, pi/2);
    T->draw(serverDrawer);

    cout << "Press Enter to do a translation on the triangle" << endl;
    getchar();
    T = T->translation(vectorTranslation);
    T->draw(serverDrawer);

    cout << "Press Enter to do a zoom on the triangle" << endl;
    getchar();
    T = T->homothety(point1, 0.5);
    T->draw(serverDrawer);

//=============== Draw Polygon ===============//

    cout << "Press Enter to draw a polygon" << endl;
    getchar();
    P->draw(serverDrawer);
    P->draw(qtDrawer);

    cout << "Press Enter to do a translation on the polygon" << endl;
    getchar();
    P = P->translation(vectorTranslation2);
    P->draw(serverDrawer);

    cout << "Press Enter to do a zoom on the polygon" << endl;
    getchar();
    P = P->homothety(point1, 0.3);
    P->draw(serverDrawer);

    cout << "Press Enter to do a rotation on the polygon" << endl;
    getchar();
    P = P->rotation(point3, pi/4);
    P->draw(serverDrawer);



//=============== Draw Compsed Shape ===============//

    cout << "Press Enter to do draw the composed shape" << endl;
    getchar();
    Vector2D centerCP(50, 100);
    Vector2D beginSegCP(300, 100), endSegCP(400, 150);
    Vector2D point1CP(450, 200), point2CP(500, 270), point3CP(500, 200);
    Vector2D point4CP(600, 150), point5CP(650, 300), point6CP(570, 450), point7CP(450, 450), point8CP(500, 500);
    Shape* SCP = new Segment(beginSegCP, endSegCP, Color::getColor("blue"));

    Shape* CCP = new Circle(centerCP, 50, Color::getColor("red"));

    Shape* TCP = new Triangle(point1CP, point2CP, point3CP, Color::getColor("green"));

    Polygon* PCP = new Polygon(Color::getColor("black"));
    PCP->addPoint(point5CP);
    PCP->addPoint(point6CP);
    PCP->addPoint(point8CP);
    PCP->addPoint(point7CP);
    PCP->addPoint(point4CP);

    ComposedShape* CC = new ComposedShape(Color::getColor("red"));
    CC->addShape(SCP);
    CC->addShape(CCP);
    CC->addShape(TCP);
    CC->addShape(PCP);

    CC->draw(serverDrawer);




    return 0;
}
