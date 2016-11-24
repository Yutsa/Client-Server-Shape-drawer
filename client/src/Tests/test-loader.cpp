#include <iostream>
#include "../Loader/ShapeLoaderText.hpp"
#include "../Shape/ComposedShape.hpp"
#include "../Utils/Color.hpp"
#include "../Visitor/SaveTextVisitor.hpp"
#include "../Loader/SegmentCreator.hpp"
#include "../Loader/TriangleCreator.hpp"
#include "../Loader/PolygonCreator.hpp"
#include "../Loader/CircleCreator.hpp"
#include "../Loader/ComposedShapeCreator.hpp"
#include "../Loader/ShapeLoaderException.hpp"
#include <string> // std::string
#include <cstddef> // std::size_t

using std::string;
using std::size_t;
using std::cout;
using std::endl;

int main()
{
    SaveTextVisitor* savior = new SaveTextVisitor();
    ShapeCreatorLink* segmentCreator = new SegmentCreator(NULL);
    ShapeCreatorLink* circleCreator = new CircleCreator(segmentCreator);
    ShapeCreatorLink* triangleCreator = new TriangleCreator(circleCreator);
    ShapeCreatorLink* polygonCreator = new PolygonCreator(triangleCreator);
    ShapeCreatorLink* composedShapeCreator = new ComposedShapeCreator(polygonCreator);
    ShapeCreator* shapeCreatorCOR = composedShapeCreator;
    
    Vector2D p1 = Vector2D(10, 10);
    Vector2D p2 = Vector2D(20, 10);
    Vector2D p3 = Vector2D(10, 20);
    Color color = Color::getColor("blue");
    Shape* segment = new Segment(p1, p2, color);
    Shape* circle = new Circle(p1, 30, color);
    Shape* triangle = new Triangle(p1, p2, p3, color);
    
    ComposedShape CP = ComposedShape(color);
    CP.addShape(circle);
    CP.addShape(triangle);
    CP.addShape(segment);
    
    const string filename = "segment.save";
    const string fileTriangle = "triangle.save";
    const string fileCircle = "circle.save";
    const string filePolygon = "polygon.save";
    const string fileComposedShape = "composedShape.save";
        
    segment->save(savior, filename);
    triangle->save(savior, fileTriangle);
    circle->save(savior, fileCircle);
    CP.save(savior, fileComposedShape);
    
    ShapeLoader* loader = new ShapeLoaderText(NULL, shapeCreatorCOR);
    try
    {
        Shape* shape = loader->load(filename);
        cout << *shape << endl;
        
        shape = loader->load(fileTriangle);
        cout << *shape << endl;
        
        shape = loader->load(fileCircle);
        cout << *shape << endl;
        
        shape = loader->load(fileComposedShape);
        cout << *shape << endl;
    }
    catch (ShapeLoaderException & e)
    {
        cout << e << endl;
    }
    return 0;
}
