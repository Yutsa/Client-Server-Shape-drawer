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

void QtDrawer::draw(const Circle* circle) const
{
    Color color = circle->getColor();
    Vector2D center = circle->getCenter();
    double radius = circle->getDiameter()/2;
    QColor qcolor = QColor(color.getRed(), color.getGreen(), 			  color.getBlue());

    _vue->setWindowTitle("Cercle");
    _scene->addEllipse(center.getX(), center.getY(),
		       radius, radius, *_pen);

    _vue->setScene(_scene);
    _vue->show();
    _app->exec();
}

void QtDrawer::draw(const Segment* segment) const
{
    Color color = segment->getColor();
    QColor qcolor = QColor(color.getRed(), color.getGreen(),
			color.getBlue());
    _pen->setColor(qcolor);
    Vector2D firstPoint = segment->getFirstPoint();
    Vector2D secondPoint = segment->getSecondPoint();
    _scene->addLine(firstPoint.getX(),firstPoint.getY(),secondPoint.getX(),secondPoint.getY(), *_pen);

    _vue->setScene(_scene);
    _vue->show();
    _app->exec();
}

void QtDrawer::draw(const Triangle* triangle) const
{
    Color color = triangle->getColor();
    QColor qcolor = QColor(color.getRed(), color.getGreen(),
			  color.getBlue());
    _pen->setColor(qcolor);  
    Vector2D firstPoint = triangle->getFirstPoint();
    Vector2D secondPoint = triangle->getSecondPoint();
    Vector2D thirdPoint = triangle->getThirdPoint();

    QPolygon polygon;

    polygon << QPoint(firstPoint.getX(),firstPoint.getY()) << QPoint(secondPoint.getX(),secondPoint.getY()) << QPoint(thirdPoint.getX(),thirdPoint.getY());

    _scene->addPolygon(polygon);

    _vue->setScene(_scene);    
    _vue->show();
    _app->exec();
}

void QtDrawer::draw(const Polygon* polygon) const
{
    Color color = polygon->getColor();
    QPolygon polygonDraw;

    QColor qcolor = QColor(color.getRed(), color.getGreen(),
			  color.getBlue());
    _pen->setColor(qcolor);

    for(int i = 0; i < polygon->getPointsSize(); i++)
    {
        polygonDraw << QPoint(polygon->getPoint(i).getX(), polygon->getPoint(i).getY());
    }
    _scene->addPolygon(polygonDraw);
    _vue->setScene(_scene);    
    _vue->show();
    _app->exec();
}

void QtDrawer::draw(const Shape *shape) const
{

}
