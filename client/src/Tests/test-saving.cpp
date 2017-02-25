#include <cstring>
#include <iostream>
#include "../Shape/Circle.hpp"
#include "../Utils/Color.hpp"
#include "../Visitor/SaveTextVisitor.hpp"
//#include "../Visitor/SaveVisitor.hpp"

using std::cout;
using std::endl;
using std::string;

int main ()
{
    SaveTextVisitor* savior = new SaveTextVisitor();
    Vector2D center = Vector2D(10, 10);
    Color color = Color::getColor("blue");
    Circle prout = Circle(center, 30, color);
    const string filename = "PROUT";
    prout.save(savior, filename);
}
