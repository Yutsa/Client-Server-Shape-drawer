#include <iostream>
#include "../Loader/ShapeLoaderText.hpp"
#include "../Shape/Segment.hpp"
#include "../Utils/Color.hpp"
#include "../Visitor/SaveTextVisitor.hpp"
#include "../Loader/SegmentCreator.hpp"
#include "../Loader/ShapeLoaderException.hpp"
#include <string> // std::string
#include <cstddef> // std::size_t

using std::string;
using std::size_t;
using std::cout;

int main()
{
    SaveTextVisitor* savior = new SaveTextVisitor();
    ShapeCreator* creator = new SegmentCreator(NULL);
    Vector2D p1 = Vector2D(10, 10);
    Vector2D p2 = Vector2D(20, 10);
    Color color = Color::getColor("blue");
    Segment segment = Segment(p1, p2, color);
    const string filename = "Segment.save";
    segment.save(savior, filename);
    ShapeLoader* loader = new ShapeLoaderText(NULL, creator);
    try
    {
        Shape* shape = loader->load(filename);
        cout << *shape << std::endl;
    }
    catch (ShapeLoaderException & e)
    {
        cout << e << endl;
    }
    return 0;
}
