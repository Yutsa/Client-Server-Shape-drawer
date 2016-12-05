#include "QtDrawer.hpp"

using std::string;

QtDrawer::QtDrawer() : DrawingVisitor()
{
    _app = new QApplication(NULL);
    _scene = new QGraphicsScene();
    _pen = new QPen();
    _vue = new QGraphicsView(_scene);

}

QtDrawer::~QtDrawer()
{

}

void QtDrawer::draw(const Circle* circle)
{
    _scene->clear();
    this->addToScene(circle);
    this->displayWindow();
}

void QtDrawer::draw(const Segment* segment)
{
    _scene->clear();
    this->addToScene(segment);
    this->displayWindow();
}

void QtDrawer::draw(const Triangle* triangle)
{
    _scene->clear();
    this->addToScene(triangle);
    this->displayWindow();
}

void QtDrawer::draw(const Polygon* polygon)
{
    _scene->clear();
    this->addToScene(polygon);
    this->displayWindow();
}

void QtDrawer::draw(const Shape *shape)
{

}

void QtDrawer::addToScene(const Circle* circle)
{
    Color color = circle->getColor();
    Vector2D center = circle->getCenter();
    double radius = circle->getDiameter() / 2;
    QColor qcolor = QColor(color.getRed(), color.getGreen(),
			   color.getBlue());


    _vue->setWindowTitle("Cercle");

    QBrush brush = QBrush(qcolor);
    _pen->setColor(qcolor);
    
    _scene->addEllipse(center.getX(), center.getY(),
		       radius, radius, *_pen, brush);
}

void QtDrawer::addToScene(const Segment* segment)
{
    Color color = segment->getColor();
    QColor qcolor = QColor(color.getRed(), color.getGreen(),
			   color.getBlue());

    QBrush brush = QBrush(qcolor);
    _pen->setColor(qcolor);

    _vue->setWindowTitle("Segment");
    Vector2D firstPoint = segment->getFirstPoint();
    Vector2D secondPoint = segment->getSecondPoint();

    _scene->addLine(firstPoint.getX(), firstPoint.getY(),
		    secondPoint.getX(), secondPoint.getY(),
		    *_pen);
}

void QtDrawer::addToScene(const Triangle* triangle)
{
    Color color = triangle->getColor();
    QColor qcolor = QColor(color.getRed(), color.getGreen(),
			   color.getBlue());

    QBrush brush = QBrush(qcolor);
    _pen->setColor(qcolor);

    Vector2D firstPoint = triangle->getFirstPoint();
    Vector2D secondPoint = triangle->getSecondPoint();
    Vector2D thirdPoint = triangle->getThirdPoint();

    QPolygon polygon;

    _vue->setWindowTitle("Triangle");
    polygon << QPoint(firstPoint.getX(), firstPoint.getY())
	    << QPoint(secondPoint.getX(), secondPoint.getY())
	    << QPoint(thirdPoint.getX(), thirdPoint.getY());

    _scene->addPolygon(polygon, *_pen, brush);
}

void QtDrawer::addToScene(const Polygon* polygon)
{
    Color color = polygon->getColor();
    QPolygon polygonDraw;

    QColor qcolor = QColor(color.getRed(), color.getGreen(),
			   color.getBlue());

    QBrush brush = QBrush(qcolor);
    _pen->setColor(qcolor);

    _vue->setWindowTitle("Polygone");
    for(int i = 0; i < polygon->getPointsSize(); i++)
    {
        polygonDraw << QPoint(polygon->getPoint(i).getX(),
			      polygon->getPoint(i).getY());
    }

    _scene->addPolygon(polygonDraw, *_pen, brush);
}

void QtDrawer::addToScene(const ComposedShape* composedShape)
{
    /*
     * We need to add each shape composing the ComposedShape to
     * the scene. But the getShape method gives us a Shape* and it
     * doens't work with our addToScene method because of that.
     */
    
    // for(unsigned int i = 0; i < composedShape->getShapeNumber(); i++)
    // {
    // 	composedShape->getShape(i);
    // }
}

void QtDrawer::displayWindow()
{
    _vue->setScene(_scene);
    _vue->show();
    _app->exec();
}
