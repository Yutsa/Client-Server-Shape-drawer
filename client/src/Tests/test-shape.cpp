#include "../Shape/Circle.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
    Color red(Color::getColor("red"));
    Color blue(Color::getColor("blue"));
    Color white(Color::getColor("white"));
    Color black(Color::getColor("black"));
    
    Vector2D center1 = Vector2D(10, 10);
    Vector2D center2 = Vector2D(1, 1);
    Vector2D vectorTranslation = Vector2D(5, 4);
    Vector2D vectorHomothety = Vector2D(4, 3);
    Vector2D vectorRotation = Vector2D(2, 1);
    double ratioHomothety = 2;
    RadianAngle angle = RadianAngle(M_PI);
    
    cout << "===== Circle =====" << endl << endl;
    
    Circle C1 = Circle(center1, 20);
    cout << "C1(Vector2D(10, 10), 20) => " << C1 << endl;
    C1.setColor(white);
    cout << "C1.setColor(white) => " << C1 << endl;
    
    Circle C2 = Circle(center2, 30, red);
    cout << "C2(Vector2D(1, 1), 30, red) => " << C2 << endl;
    
    cout << "Vector translation => " << vectorTranslation << endl;
    Circle *C = C2.translation(vectorTranslation);
    cout << "C = C2.translation(vectorTranslation) => " << C << endl;
    
    cout << "Vector homothety => " << vectorHomothety << endl;
    cout << "Ratio homothety => " << ratioHomothety << endl;
    C = C2.homothety(vectorHomothety, ratioHomothety);
    cout << "C = C2.homothety(vectorTranslation, ratioHomothety) => " << C << endl;
    
    cout << "Vector rotation => " << vectorRotation << endl;
    cout << "Angle => " << angle << endl;
    C = C2.rotation(vectorRotation, angle);
    cout << "C = C2.rotation(vectorRotation, angle) => " << C << endl;
    
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
    
    return 0;
}
