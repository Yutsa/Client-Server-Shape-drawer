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
    QtDrawer *qtDrawer = new QtDrawer();

    Vector2D center(10, 50);
    Circle C(center, 400, Color::getColor("red"));
    C.draw(qtDrawer);

    Vector2D P1P = Vector2D(250,250);
    Vector2D P2P = Vector2D(300,250);
    Vector2D P3P = Vector2D(300,300);
    Vector2D P4P = Vector2D(250, 300);
    Triangle T = Triangle(P1P, P2P, P3P, Color::getColor("red"));
    T.draw(qtDrawer);

    Segment S(P1P, P2P, Color::getColor("red"));
    S.draw(qtDrawer);

    Polygon P(Color::getColor("red"));
    P.addPoint(P1P);
    P.addPoint(P2P);
    P.addPoint(P3P);
    P.addPoint(P4P);
    P.draw(qtDrawer);
    return 0;
}
