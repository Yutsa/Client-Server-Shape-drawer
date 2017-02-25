#include "../Network/Socket.hpp"
#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"
#include "../Shape/ComposedShape.hpp"
#include "../Visitor/QtDrawer.hpp"


using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
  //    ServerDrawer *serverDrawer = new ServerDrawer();
    QtDrawer *qtDrawer = new QtDrawer();
    Color red(Color::getColor("red"));
    Color blue(Color::getColor("blue"));
    Color white(Color::getColor("white"));
    Color black(Color::getColor("black"));

    Vector2D invariantPoint = Vector2D(50, 50);
    Vector2D translationVector = Vector2D(200, 0);
    Vector2D rotationCenter = Vector2D(100, 100);
    double homothetyRatio = 1;
    RadianAngle rotationAngle = RadianAngle(1.5);

    /*  cout << "===== Circle =====" << endl << endl;

        Vector2D center = Vector2D(400, 250);

        Circle C = Circle(center, 100, red);
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
        Vector2D P1P = Vector2D(250,250);
        P.addPoint(P1P);
        Vector2D P2P = Vector2D(300,250);
        P.addPoint(P2P);
        Vector2D P3P = Vector2D(300,300);
        P.addPoint(P3P);
        Vector2D P4P = Vector2D(250,300);
        P.addPoint(P4P);

        cout << "       Polygone convexe        " << endl;

        cout << "Normal : " << P << " Aire : " << P.getArea() << endl;

        PModif = P.homothety(invariantPoint, homothetyRatio);
        cout << "Homothety : "  << *PModif << " Aire : " << PModif->getArea() << endl;

        PModif = P.translation(translationVector);
        cout << "Translation : " << *PModif << " Aire : " << PModif->getArea() << endl;

        PModif = P.rotation(rotationCenter, rotationAngle);
        cout << "Rotation : " << *PModif << " Aire : " << PModif->getArea() << endl << endl;

        Vector2D P5P = Vector2D(275,275);
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
        Vector2D P1S = Vector2D(500,350);
        Vector2D P2S = Vector2D(500,500);
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
        Vector2D P1T = Vector2D(200,200);
        Vector2D P2T = Vector2D(150,250);
        Vector2D P3T = Vector2D(250,250);
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
        CS.draw(serverDrawer);
        sleep(5);

        CSModif = CS.homothety(invariantPoint, homothetyRatio);
        cout << "Homothety : "  << *CSModif << " Aire : " << CSModif->getArea() << endl<< endl;
        CSModif->draw(serverDrawer);
        sleep(5);

        CSModif = CS.translation(translationVector);
        cout << "Translation : " << *CSModif << " Aire : " << CSModif->getArea() << endl<< endl;
        CSModif->draw(serverDrawer);
        sleep(5);

        CSModif = CS.rotation(rotationCenter, rotationAngle);
        cout << "Rotation : " << *CSModif << " Aire : " << CSModif->getArea() << endl << endl;
        CSModif->draw(serverDrawer);
*/

//=============== Variables Init ===============//

    Vector2D center(50, 50), beginSeg(300, 100), endSeg(400, 150);
    Vector2D point1(450, 200), point2(500, 270), point3(500, 200);
    Vector2D point4(600, 150), point5(650, 300), point6(570, 450), point7(450, 450), point8(500, 500);
    Vector2D centerRotation(100, 100), centerRotation2(250, 150), centerRotation3(500, 100);
    Vector2D vectorTranslation(100, 0), vectorTranslation2(300, -50);
    //    Vector2D invariantPoint(50, 50);
    double ratio = 1.5;

    RadianAngle pi(M_PI), halfPi(M_PI/2);

    Segment S(beginSeg, endSeg, Color::getColor("blue"));
    Circle C(center, 50, Color::getColor("red"));
    Triangle T(point1, point2, point3, Color::getColor("green"));
    Polygon P(Color::getColor("black"));

    Shape *C1, *C2, *C3, *C4, *C5;
    Shape *S1, *S2, *S3;
    Shape *T1, *T2, *T3;
    Shape *P1;

    P.addPoint(point5);
    P.addPoint(point6);
    P.addPoint(point8);
    P.addPoint(point7);
    P.addPoint(point4);

//=============== Start Connexion ===============//

    /*ServerDrawer *serverDrawer = new ServerDrawer();
      sleep(1);*/

//=============== Draw Circles ===============//

    C.draw(qtDrawer);
    sleep(1);

    C1 = C.rotation(centerRotation, halfPi);

    C1->draw(qtDrawer);
    sleep(1);

    C2 = C1->rotation(centerRotation, halfPi);

    C2->draw(qtDrawer);
    sleep(1);

    C3 = C2->rotation(centerRotation, halfPi);

    C3->draw(qtDrawer);
    sleep(1);

    C4 = C3->homothety(center, ratio);

    C4->draw(qtDrawer);
    sleep(1);

    C5 = C4->translation(vectorTranslation);

    C5->draw(qtDrawer);
    sleep(1);

//=============== Draw Segment ===============//

    S.draw(qtDrawer);
    sleep(1);

    S1 = S.rotation(centerRotation2, halfPi);

    S1->draw(qtDrawer);
    sleep(1);

    S2 = S1->homothety(centerRotation2, ratio);

    S2->draw(qtDrawer);
    sleep(1);

    S3 = S2->translation(vectorTranslation);

    S3->draw(qtDrawer);
    sleep(1);

//=============== Draw Triangle ===============//

    T.draw(qtDrawer);
    sleep(1);

    T1 = T.translation(vectorTranslation);

    T1->draw(qtDrawer);
    sleep(1);

    T2 = T1->homothety(point1, ratio);

    T2->draw(qtDrawer);
    sleep(1);

    T3 = T2->rotation(centerRotation3, pi);

    T3->draw(qtDrawer);
    sleep(1);

//=============== Draw Polygon ===============//

    P.draw(qtDrawer);
    sleep(1);

    P1 = P.translation(vectorTranslation2);

    P1->draw(qtDrawer);


    return 0;
}
