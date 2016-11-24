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
    Polygon P = Polygon(Color::getColor("red"));
    Vector2D P1P = Vector2D(250,250);
    P.addPoint(P1P);
    Vector2D P2P = Vector2D(300,250);
    P.addPoint(P2P);
    Vector2D P3P = Vector2D(300,300);
    P.addPoint(P3P);
    P.draw(qtDrawer);
    return 0;
}
