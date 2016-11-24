#include <QApplication>
#include <QtGui>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    	QGraphicsScene scene;
    	scene.addText("Hello world !");

    	QGraphicsView vue(&scene);
    	vue.show();

    	return app.exec();
}
