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
    Color red(Color::getColor("red"));
    //Color blue(Color::getColor("blue"));
    //Color white(Color::getColor("white"));
    //Color black(Color::getColor("black"));

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
        cout << "Homothety : "  << *CModif << " Aire : " << CModif->getArea() << endl;

        CModif = C.translation(translationVector);
        cout << "Translation : " << *CModif << " Aire : " << CModif->getArea() << endl;

        CModif = C.rotation(rotationCenter, rotationAngle);
        cout << "Rotation : " << *CModif << " Aire : " << CModif->getArea() << endl << endl;

    cout << "===== Polygon =====" << endl << endl;

        Shape* PModif;

        Polygon P = Polygon(red);
        Vector2D P1P = Vector2D(10,10);
        P.addPoint(P1P);
        Vector2D P2P = Vector2D(20,10);
        P.addPoint(P2P);
        Vector2D P3P = Vector2D(20,20);
        P.addPoint(P3P);
        Vector2D P4P = Vector2D(10,20);
        P.addPoint(P4P);

        cout << "       Polygone convexe        " << endl;

        cout << "Normal : " << P << " Aire : " << P.getArea() << endl;

        PModif = P.homothety(invariantPoint, homothetyRatio);
        cout << "Homothety : "  << *PModif << " Aire : " << PModif->getArea() << endl;

        PModif = P.translation(translationVector);
        cout << "Translation : " << *PModif << " Aire : " << PModif->getArea() << endl;

        PModif = P.rotation(rotationCenter, rotationAngle);
        cout << "Rotation : " << *PModif << " Aire : " << PModif->getArea() << endl << endl;

        Vector2D P5P = Vector2D(15,15);
        P.addPoint(P5P);

        cout << "       Polygone concave        " << endl;

        cout << "Normal : " << P << " Aire : " << P.getArea() << endl;

        PModif = P.homothety(invariantPoint, homothetyRatio);
        cout << "Homothety : "  << *PModif << " Aire : " << PModif->getArea() << endl;

        PModif = P.translation(translationVector);
        cout << "Translation : " << *PModif << " Aire : " << PModif->getArea() << endl;

        PModif = P.rotation(rotationCenter, rotationAngle);
        cout << "Rotation : " << *PModif << " Aire : " << PModif->getArea() << endl << endl;


    cout << "===== Segment =====" << endl << endl;

        Shape* SModif;
        Vector2D P1S = Vector2D(10,10);
        Vector2D P2S = Vector2D(20,10);
        Segment S = Segment(P1S,P2S,red);

        cout << "Normal : " << S << " Aire : " << S.getArea() << endl;

        SModif = S.homothety(invariantPoint, homothetyRatio);
        cout << "Homothety : "  << *SModif << " Aire : " << SModif->getArea() << endl;

        SModif = S.translation(translationVector);
        cout << "Translation : " << *SModif << " Aire : " << SModif->getArea() << endl;

        SModif = S.rotation(rotationCenter, rotationAngle);
        cout << "Rotation : " << *SModif << " Aire : " << SModif->getArea() << endl << endl;

    cout << "===== Triangle =====" << endl << endl;

        Shape* TModif;
        Vector2D P1T = Vector2D(10,10);
        Vector2D P2T = Vector2D(20,10);
        Vector2D P3T = Vector2D(20,20);
        Triangle T = Triangle(P1T,P2T,P3T,red);

        cout << "Normal : " << T << " Aire : " << T.getArea() << endl;

        TModif = T.homothety(invariantPoint, homothetyRatio);
        cout << "Homothety : "  << *TModif << " Aire : " << TModif->getArea() << endl;

        TModif = T.translation(translationVector);
        cout << "Translation : " << *TModif << " Aire : " << TModif->getArea() << endl;

        TModif = T.rotation(rotationCenter, rotationAngle);
        cout << "Rotation : " << *TModif << " Aire : " << TModif->getArea() << endl << endl;

    cout << "===== Composed Shape =====" << endl << endl;

        Shape* CSModif;
        ComposedShape CS = ComposedShape(red);

        CS.addShape(&C);
        CS.addShape(&P);
        CS.addShape(&S);
        CS.addShape(&T);

        cout << "Normal : " << CS << " Aire : " << CS.getArea() << endl<< endl;

        CSModif = CS.homothety(invariantPoint, homothetyRatio);
        cout << "Homothety : "  << *CSModif << " Aire : " << CSModif->getArea() << endl<< endl;

        CSModif = CS.translation(translationVector);
        cout << "Translation : " << *CSModif << " Aire : " << CSModif->getArea() << endl<< endl;

        CSModif = CS.rotation(rotationCenter, rotationAngle);
        cout << "Rotation : " << *CSModif << " Aire : " << CSModif->getArea() << endl << endl;







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
