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

    RadianAngle pi(M_PI);



    Vector2D beginSeg(31, 84), endSeg(31, 120);
    Vector2D InvPointSeg(0, 102);
    double ratioSeg = 1;
    Vector2D translationSeg(50,0);


    Vector2D center(31, 175);
    Vector2D translationCircle(70,0);
    Vector2D InvPointCir(0, 175);
    double ratioCir = 1.5;

    Vector2D point1(31, 300), point2(62, 331), point3(0, 331);
    Vector2D translationTri(70,0);
    Vector2D InvPointTri(0, 315);
    double ratioTri = 1.5;

    Vector2D point4(31, 400), point5(62, 400), point6(62, 431), point7(31, 431);
    Vector2D translationPol(70,0);
    Vector2D InvPointPoly(0, 415);
    double ratioPol = 1.5;

    Vector2D translationCC(0,100);
    Vector2D InvPointCC(750, 0);
    double ratioCC = 1.5;

    //=============== Shape Init ===============//

    Shape* S = new Segment(beginSeg, endSeg, Color::getColor("blue"));
    Shape* C = new Circle(center, 50, Color::getColor("red"));
    Shape* T = new Triangle(point1, point2, point3, Color::getColor("green"));
    Polygon* P1 = new Polygon(Color::getColor("black"));
    P1->addPoint(point4);
    P1->addPoint(point5);
    P1->addPoint(point6);
    P1->addPoint(point7);

    Shape* P = P1;

    //=============== Start Connexion ===============//

        ServerDrawer *serverDrawer = new ServerDrawer();

    //=============== Draw Segment ===============//

        cout << "Press Enter to draw a segment" << endl;
        getchar();
        S->draw(serverDrawer);

        cout << "Press Enter to do a translation on the segment" << endl;
        getchar();
        S = S->translation(translationSeg);
        S->draw(serverDrawer);

        cout << "Press Enter to zoom on the segment" << endl;
        getchar();
        S = S->homothety(InvPointSeg, ratioSeg);
        S->draw(serverDrawer);

        cout << "Press Enter to rotate the segment" << endl;
        getchar();
        S = S->translation(translationSeg);
        Vector2D rotationSeg(((Segment*)S)->getFirstPoint().getX(),(((Segment*)S)->getFirstPoint().getY()+((Segment*)S)->getSecondPoint().getY())/2);
        S = S->rotation(rotationSeg, pi/2);
        S->draw(serverDrawer);

    //=============== Draw Circles ===============//

        cout << "Press Enter to draw a circle" << endl;
        getchar();
        C->draw(serverDrawer);

        cout << "Press Enter to do a translation on the circle." << endl;
        getchar();
        C = C->translation(translationCircle);
        C->draw(serverDrawer);

        cout << "Press Enter to zoom on circle." << endl;
        getchar();
        C = C->homothety(InvPointCir, ratioCir);
        C->draw(serverDrawer);

        cout << "Press Enter to rotate the Circle" << endl;
        getchar();
        C = C->translation(translationCircle);
        Vector2D rotationCir(((Circle*)C)->getCenter().getX()-10,((Circle*)C)->getCenter().getY());
        C = C->rotation(rotationCir, pi/2);
        C->draw(serverDrawer);

    //=============== Draw Triangle ===============//

        cout << "Press Enter to draw a triangle" << endl;
        getchar();
        T->draw(serverDrawer);

        cout << "Press Enter to do a translation on the triangle" << endl;
        getchar();
        T = T->translation(translationTri);
        T->draw(serverDrawer);

        cout << "Press Enter to do a zoom on the triangle" << endl;
        getchar();
        T = T->homothety(InvPointTri, ratioTri);
        T->draw(serverDrawer);

        cout << "Press Enter to do a rotation on the triangle" << endl;
        getchar();
        T = T->translation(translationTri);
        Vector2D rotationTri(((Triangle*)T)->getFirstPoint().getX(),(((Triangle*)T)->getFirstPoint().getX()+((Triangle*)T)->getSecondPoint().getY())/2);
        T = T->rotation(rotationTri, pi/2);
        T->draw(serverDrawer);

    //=============== Draw Polygon ===============//

        cout << "Press Enter to draw a polygon" << endl;
        getchar();
        P->draw(serverDrawer);

        cout << "Press Enter to do a translation on the polygon" << endl;
        getchar();
        P = P->translation(translationPol);
        P->draw(serverDrawer);

        cout << "Press Enter to do a zoom on the polygon" << endl;
        getchar();
        P = P->homothety(InvPointPoly, ratioPol);
        P->draw(serverDrawer);

        cout << "Press Enter to do a rotation on the polygon" << endl;
        getchar();
        P = P->translation(translationPol);
        Vector2D rotationPol((((Polygon*)P)->getPoint(0).getX()+((Polygon*)P)->getPoint(1).getX())/2,(((Polygon*)P)->getPoint(1).getY()+((Polygon*)P)->getPoint(2).getY())/2);
        P = P->rotation(rotationPol, pi/4);
        P->draw(serverDrawer);


        //=============== Draw Compsed Shape ===============//

        cout << "Press Enter to do draw the composed shape" << endl;
        getchar();
        Vector2D centerCP(800, 55);
        Vector2D beginSegCP(700, 55), endSegCP(725, 55);
        Vector2D point1CP(750, 80), point2CP(762, 105), point3CP(737, 105);
        Vector2D point4CP(725, 30), point5CP(775, 30), point6CP(775, 80), point7CP(725, 80);
        Shape* SCP = new Segment(beginSegCP, endSegCP, Color::getColor("blue"));

        Shape* CCP = new Circle(centerCP, 25, Color::getColor("red"));

        Shape* TCP = new Triangle(point1CP, point2CP, point3CP, Color::getColor("green"));

        Polygon* PCP = new Polygon(Color::getColor("black"));
        PCP->addPoint(point4CP);
        PCP->addPoint(point5CP);
        PCP->addPoint(point6CP);
        PCP->addPoint(point7CP);

        ComposedShape* CC1 = new ComposedShape(Color::getColor("red"));
        CC1->addShape(SCP);
        CC1->addShape(CCP);
        CC1->addShape(TCP);
        CC1->addShape(PCP);

        CC1->draw(serverDrawer);

        Shape* CC = CC1;

        cout << "Press Enter to do a translation on the Composed Shape" << endl;
        getchar();
        CC = CC->translation(translationCC);
        CC->draw(serverDrawer);

        cout << "Press Enter to do a zoom on the Composed Shape" << endl;
        getchar();
        CC = CC->homothety(InvPointCC, ratioCC);
        CC->draw(serverDrawer);

        cout << "Press Enter to do a rotation on the Composed Shape" << endl;
        getchar();
        CC = CC->translation(translationCC);
        Vector2D rotationCC((((Polygon*)(((ComposedShape*)CC)->getShape(3)))->getPoint(0).getX()+((Polygon*)(((ComposedShape*)CC)->getShape(3)))->getPoint(1).getX())/2,(((Polygon*)(((ComposedShape*)CC)->getShape(3)))->getPoint(1).getY()+(((Polygon*)(((ComposedShape*)CC)->getShape(3)))->getPoint(2).getY())/2));
        CC= CC->rotation(rotationCC, pi/4);
        CC->draw(serverDrawer);

        //=============== Draw Compsed Shape ===============//

        cout << "Press Enter to do draw the composed shape" << endl;
        getchar();
        Vector2D centerQT(50, 50);
        Vector2D beginSegQT(25, 25), endSegQT(25, 75);
        Vector2D point1QT(25, 25), point2QT(0, 75), point3QT(50, 75);
        Vector2D point4QT(25, 25), point5QT(75, 25), point6QT(75, 75), point7QT(25, 75);
        Shape* SQT = new Segment(beginSegQT, endSegQT, Color::getColor("blue"));

        Shape* CQT = new Circle(centerQT, 25, Color::getColor("red"));

        Shape* TQT = new Triangle(point1QT, point2QT, point3QT, Color::getColor("green"));

        Polygon* PQT = new Polygon(Color::getColor("black"));
        PQT->addPoint(point4QT);
        PQT->addPoint(point5QT);
        PQT->addPoint(point6QT);
        PQT->addPoint(point7QT);


        QtDrawer *qtDrawer = new QtDrawer();

        cout << "Press Enter to do draw the Segment in QT" << endl;
        getchar();
        SQT->draw(qtDrawer);

        cout << "Press Enter to do draw the Circle in QT" << endl;
        getchar();
        CQT->draw(qtDrawer);

        cout << "Press Enter to do draw the Triangle in QT" << endl;
        getchar();
        TQT->draw(qtDrawer);

        cout << "Press Enter to do draw the Polygon in QT" << endl;
        getchar();
        PQT->draw(qtDrawer);


    return 0;
}
