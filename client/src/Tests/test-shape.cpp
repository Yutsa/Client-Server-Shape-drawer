#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"


using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
    Color red(Color::getColor("red"));
    Color blue(Color::getColor("blue"));
    Color white(Color::getColor("white"));
    Color black(Color::getColor("black"));

    Vector2D invariantPoint = Vector2D(0, 0);
    Vector2D translationVector = Vector2D(1, 2);
    Vector2D rotationCenter = Vector2D(0, 0);
    double homothetyRatio = 10;
    RadianAngle rotationAngle = RadianAngle(3.14);

    cout << "===== Circle =====" << endl << endl;

    Vector2D center = Vector2D(10, 10);

    Circle C = Circle(center, 30, red);
    Shape* CModif;

    cout << "Normal : " << C << " Aire : " << C.getArea() << endl;

    CModif = C.homothety(invariantPoint, homothetyRatio);
    cout << "Homothety : "  << *CModif << " Aire : " << C.getArea() << endl;

    CModif = C.translation(translationVector);
    cout << "Translation : " << *CModif << " Aire : " << C.getArea() << endl;

    CModif = C.rotation(rotationCenter, rotationAngle);
    cout << "Rotation : " << *CModif << " Aire : " << C.getArea() << endl;

    cout << "===== Polygon =====" << endl << endl;

    cout << "===== Segment =====" << endl << endl;

    cout << "===== Triangle =====" << endl << endl;








/**
    Vector2D center1 = Vector2D(10, 10);
    Vector2D center2 = Vector2D(1, 1);
    Vector2D center3 = Vector2D(5, 5);
    Vector2D center4 = Vector2D(30, 30);

    cout << "===== Circle =====" << endl << endl;

    Circle C1 = Circle(center1, 20);
    cout << "C1(Vector2D(10, 10), 20) => " << C1 << endl;
    C1.setColor(white);
    cout << "C1.setColor(white) => " << C1 << endl;

    Circle C2 = Circle(center2, 30, red);
    cout << "C1(Vector2D(1, 1), 30, red) => " << C2 << endl;

//    Circle C2 = Circle(center1, 30, red);
//    Circle C1 = Circle(center1, 20);
//    Circle C2 = Circle(center1, 30, red);
//
//    cout << (int)color1.getRed() << endl;
//    cout << (int)color1.getGreen() << endl;
//    cout << color1 << endl;
//    cout << color2 << endl;
//    cout << C1 << endl;
//    cout << C2 << endl;

**/

    return 0;
}
