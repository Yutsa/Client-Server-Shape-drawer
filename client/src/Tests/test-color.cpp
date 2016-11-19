#include "../Utils/Color.hpp"

using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
    Color color1(25, 50, 75);
    Color color2(100, 150, 200);
    Color color3(255, 255, 255);
    Color red(Color::getColor("red"));
    Color blue(Color::getColor("blue"));
    Color white(Color::getColor("white"));
    Color black(Color::getColor("black"));
    
    cout << "Color 1 (25, 50, 75) => " << color1 << endl;
    cout << "Color 2 (100, 150, 200) => " << color2 << endl;
    cout << "Color 3 (255, 255, 255) => " << color3 << endl;
    cout << "Red (255, 0, 0) => " << red << endl;
    cout << "Blue (0, 0, 255) => " << blue << endl;
    cout << "White (255, 255, 255) => " << white << endl;
    cout << "Black (0, 0, 0) => " << black << endl;
    
    cout << "Need cast to int for display unsigned char" << endl;
    cout << "Red.getRed() => " << (int)red.getRed() << endl;
    cout << "Red.getGreen() => " << (int)red.getGreen() << endl;
    cout << "Red.getBlue() => " << (int)red.getBlue() << endl;
    
    return 0;
}