#include "QtDrawer.hpp"

using std::string;

QtDrawer::QtDrawer(int argc, char* argv[]) : DrawingVisitor()
{
    _app(argc, argv);
    _vue(&_scene);
}

QtDrawer::~QtDrawer()
{

}

void QtDrawer::draw(const Circle* circle) const
{
    Color color = circle->getColor();
    Vector2D center = circle->getCenter();
    double radius = circle->getDiameter()/2;

    pen = pen(QColor(color.getRed(),color.getGreen(),color.getBlue()));
    _scene.addEllipse(center.getX(),center.getY(),radius,radius,pen);

    _vue.show();
    _app.exec();

}

void QtDrawer::draw(const Segment* segment) const
{
    Color color = segment->getColor();
    pen = pen(QColor(color.getRed(),color.getGreen(),color.getBlue()));
    Vector2D firstPoint = segment->getFirstPoint();
    Vector2D secondPoint = segment->getSecondPoint();
    _scene.addLine(firstPoint.getX(),firstPoint.getY(),secondPoint.getX(),secondPoint.getY(),pen);

    _vue.show();
    _app.exec();
}

void QtDrawer::draw(const Triangle* triangle) const
{
    Color color = triangle->getColor();
    pen = pen(QColor(color.getRed(),color.getGreen(),color.getBlue()));
    Vector2D firstPoint = triangle->getFirstPoint();
    Vector2D secondPoint = triangle->getSecondPoint();
    Vector2D thirdPoint = triangle->getThirdPoint();

    QPolygon polygon;

    polygon << QPoint(firstPoint.getX(),firstPoint.getY()) << QPoint(secondPoint.getX(),secondPoint.getY()) << QPoint(thirdPoint.getX(),thirdPoint.getY());

    _scene.addPolygon(polygon);

    _vue.show();
    _app.exec();
}

void QtDrawer::draw(const Polygon* polygon) const
{
    Color color = triangle->getColor();
    pen = pen(QColor(color.getRed(),color.getGreen(),color.getBlue()));

    QPolygon polygonDraw;

    for(int i = 0; i < polygon->getPointsSize(); i++)
    {
        QPolygon << QPoint(polygon->getPoint(i).getX(), polygon->getPoint(i).getY());
    }
    _scene.addPolygon(polygon);
    _vue.show();
    _app.exec();
}

void QtDrawer::draw(const Shape *shape) const
{

}
