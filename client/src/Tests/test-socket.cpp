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

    Vector2D center(50, 50), beginSeg(300, 100), endSeg(400, 150);
    Vector2D point1(450, 200), point2(500, 270), point3(500, 200);
    Vector2D point4(600, 150), point5(650, 300), point6(570, 450), point7(450, 450), point8(500, 500);
    Vector2D centerRotation(100, 100), centerRotation2(250, 150), centerRotation3(500, 100);
    Vector2D vectorTranslation(100, 0), vectorTranslation2(300, -50);
    Vector2D invariantPoint(50, 50);
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

    ServerDrawer *serverDrawer = new ServerDrawer();
    sleep(1);

//=============== Draw Circles ===============//

    C.draw(serverDrawer);
    sleep(1);

    C1 = C.rotation(centerRotation, halfPi);

    C1->draw(serverDrawer);
    sleep(1);

    C2 = C1->rotation(centerRotation, halfPi);

    C2->draw(serverDrawer);
    sleep(1);

    C3 = C2->rotation(centerRotation, halfPi);

    C3->draw(serverDrawer);
    sleep(1);

    C4 = C3->homothety(center, ratio);

    C4->draw(serverDrawer);
    sleep(1);

    C5 = C4->translation(vectorTranslation);

    C5->draw(serverDrawer);
    sleep(1);

//=============== Draw Segment ===============//

    S.draw(serverDrawer);
    sleep(1);

    S1 = S.rotation(centerRotation2, halfPi);

    S1->draw(serverDrawer);
    sleep(1);

    S2 = S1->homothety(centerRotation2, ratio);

    S2->draw(serverDrawer);
    sleep(1);

    S3 = S2->translation(vectorTranslation);

    S3->draw(serverDrawer);
    sleep(1);

//=============== Draw Triangle ===============//

    T.draw(serverDrawer);
    sleep(1);

    T1 = T.translation(vectorTranslation);

    T1->draw(serverDrawer);
    sleep(1);

    T2 = T1->homothety(point1, ratio);

    T2->draw(serverDrawer);
    sleep(1);

    T3 = T2->rotation(centerRotation3, pi);

    T3->draw(serverDrawer);
    sleep(1);

//=============== Draw Polygon ===============//

    P.draw(serverDrawer);
    sleep(1);

    P1 = P.translation(vectorTranslation2);

    P1->draw(serverDrawer);

    return 0;
}
