#include "../Network/Socket.hpp"
#include "../Visitor/ServerDrawer.hpp"
#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"
#include "../Shape/Triangle.hpp"
#include "../Shape/Segment.hpp"
#include "../Shape/ComposedShape.hpp"
#include "../Visitor/QtDrawer.hpp"
#include "../Visitor/SaveTextVisitor.hpp"
#include "../Loader/SegmentCreator.hpp"
#include "../Loader/TriangleCreator.hpp"
#include "../Loader/PolygonCreator.hpp"
#include "../Loader/CircleCreator.hpp"
#include "../Loader/ComposedShapeCreator.hpp"
#include "../Loader/ShapeLoaderException.hpp"
#include "../Loader/ShapeLoaderText.hpp"


using std::cout;
using std::endl;
using std::string;

int main(int argc, char* argv[])
{
    //=============== Variables Init ===============//

    RadianAngle pi(M_PI);
    Vector2D pRec1 = Vector2D(1, -1);
    Vector2D pRec2 = Vector2D(5, -1);
    Vector2D pRec3 = Vector2D(5, 1);
    Vector2D pRec4 = Vector2D(1, 1);

    Vector2D pTri1 = Vector2D(6, -1);
    Vector2D pTri2 = Vector2D(8, 0);
    Vector2D pTri3 = Vector2D(6, 1);

    Vector2D centre = Vector2D(11, 0);
    double diametre = 4;

    /* Création rectangle */
    Polygon* rectangle1 = new Polygon(Color::getColor("blue"));
    rectangle1->addPoint(pRec1);
    rectangle1->addPoint(pRec2);
    rectangle1->addPoint(pRec3);
    rectangle1->addPoint(pRec4);

    Shape* rectangle = rectangle1;

    /* Création Triangle */
    Color jaune(255, 255, 0);
    Shape* triangle = new Triangle(pTri1, pTri2, pTri3, jaune);

    /* Création cercle */
    Shape* cercle = new Circle(centre, diametre,
			       Color::getColor("green")); // mettre en jaune

    /* Création composed shape */
    ComposedShape* composedShape =
	new ComposedShape(Color::getColor("red"));

    composedShape->addShape(rectangle);
    composedShape->addShape(triangle);
    composedShape->addShape(cercle);

    Shape* groupe = composedShape;

    Vector2D translation = Vector2D(-1, 0);
    groupe = groupe->translation(translation);

    Vector2D rotation = Vector2D(0, 0);
    groupe = groupe->rotation(rotation, pi / 4);

    cout << "Aire de G1 = " << groupe->getArea() << endl;

    ServerDrawer *serverDrawer = new ServerDrawer();

    Vector2D pointInvariant = Vector2D(-10, -10);
    
    groupe = groupe->homothety(pointInvariant, 15);
    groupe->draw(serverDrawer);

    const string filename = "mabellefigure1.save";
    SaveTextVisitor* savior = new SaveTextVisitor();
    ShapeCreatorLink* segmentCreator = new SegmentCreator(NULL);
    ShapeCreatorLink* circleCreator = new CircleCreator(segmentCreator);
    ShapeCreatorLink* triangleCreator = new TriangleCreator(circleCreator);
    ShapeCreatorLink* polygonCreator = new PolygonCreator(triangleCreator);
    ShapeCreatorLink* composedShapeCreator = new ComposedShapeCreator(polygonCreator);
    ShapeCreator* shapeCreatorCOR = composedShapeCreator;

    groupe->save(savior, filename);

    ShapeLoader* loader = new ShapeLoaderText(NULL, shapeCreatorCOR);

    Shape* g2 = loader->load(filename);

    Vector2D translation2 = Vector2D(150, 0);
    //g2 = g2->translation(translation2);

    
    g2 = g2->rotation(Vector2D(0, 0), pi * 0.2);

    cout << "g1 " << *groupe << endl;
    cout << *g2 << endl;

    g2->draw(serverDrawer);
    return 0;
}
