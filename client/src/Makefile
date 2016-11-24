CFLAGS = -Wall -ansi -fdiagnostics-color=auto
INCDIRS=-I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore
LIBS=-lQtCore -lQtGui

all: test-vector2D

test-vector2D: test-vector2D.o vector2d.o radianangle.o geometryexception.o
	g++ -o ../bin/test-vector2D ../bin/test-vector2D.o ../bin/vector2d.o ../bin/radianangle.o ../bin/geometryexception.o $(CFLAGS)

test-socket: test-socket.o socket.o networkexception.o circle.o geometryexception.o composedshape.o radianangle.o color.o utilsexception.o shape.o serverdrawer.o socket.o networkexception.o polygon.o triangle.o segment.o qtdrawer.o
	g++ -o ../bin/test-socket ../bin/test-socket.o ../bin/circle.o ../bin/composedshape.o ../bin/polygon.o ../bin/triangle.o ../bin/segment.o ../bin/vector2d.o ../bin/geometryexception.o ../bin/radianangle.o ../bin/color.o ../bin/utilsexception.o ../bin/shape.o ../bin/serverdrawer.o  ../bin/socket.o ../bin/networkexception.o ../bin/qtdrawer.o $(LIBS) $(CFLAGS)

test-shape: vector2d.o test-shape.o circle.o geometryexception.o radianangle.o color.o utilsexception.o shape.o serverdrawer.o socket.o networkexception.o polygon.o triangle.o segment.o composedshape.o
	g++ -o ../bin/test-shape ../bin/test-shape.o  ../bin/circle.o ../bin/polygon.o ../bin/composedshape.o ../bin/triangle.o ../bin/segment.o ../bin/vector2d.o ../bin/geometryexception.o ../bin/radianangle.o ../bin/color.o ../bin/utilsexception.o ../bin/shape.o ../bin/serverdrawer.o ../bin/socket.o ../bin/networkexception.o $(CFLAGS)

test-color: test-color.o color.o utilsexception.o
	g++ -o ../bin/test-color ../bin/test-color.o ../bin/color.o ../bin/utilsexception.o $(CFLAGS)

test-saving: test-saving.o circle.o color.o savetextvisitor.o vector2d.o shape.o radianangle.o utilsexception.o geometryexception.o
	g++ -o ../bin/test-saving ../bin/test-saving.o ../bin/circle.o ../bin/color.o ../bin/vector2d.o ../bin/savetextvisitor.o ../bin/shape.o ../bin/radianangle.o ../bin/utilsexception.o ../bin/geometryexception.o $(CFLAGS)

test-saving.o: Tests/test-saving.cpp Shape/Circle.hpp Utils/Color.hpp Visitor/SaveTextVisitor.hpp
	g++ -o ../bin/test-saving.o -c Tests/test-saving.cpp $(CFLAGS)

test-vector2D.o: Tests/test-vector2D.cpp Geometry/Vector2D.hpp
	g++ -o ../bin/test-vector2D.o -c Tests/test-vector2D.cpp $(CFLAGS)

vector2d.o: Geometry/Vector2D.cpp Geometry/Vector2D.hpp Geometry/RadianAngle.hpp
	g++ -o ../bin/vector2d.o -c Geometry/Vector2D.cpp $(CFLAGS)

geometryexception.o: Geometry/GeometryException.cpp Geometry/GeometryException.hpp
	g++ -o ../bin/geometryexception.o -c Geometry/GeometryException.cpp $(CFLAGS)

networkexception.o: Network/NetworkException.cpp Network/NetworkException.hpp
	g++ -o ../bin/networkexception.o -c Network/NetworkException.cpp $(CFLAGS)

utilsexception.o: Utils/UtilsException.cpp Utils/UtilsException.hpp
	g++ -o ../bin/utilsexception.o -c Utils/UtilsException.cpp $(CFLAGS)

socket.o: Network/Socket.cpp Network/Socket.hpp Network/NetworkException.hpp
	g++ -o ../bin/socket.o -c Network/Socket.cpp $(CFLAGS)

radianangle.o: Geometry/RadianAngle.cpp Geometry/RadianAngle.hpp Geometry/GeometryException.hpp
	g++ -o ../bin/radianangle.o -c Geometry/RadianAngle.cpp $(CFLAGS)

test-socket.o: Tests/test-socket.cpp Network/Socket.hpp
	g++ -o ../bin/test-socket.o $(INCDIRS) -c Tests/test-socket.cpp $(CFLAGS)

test-shape.o: Tests/test-shape.cpp Shape/Circle.hpp
	g++ -o ../bin/test-shape.o -c Tests/test-shape.cpp $(CFLAGS)

test-color.o: Tests/test-color.cpp Utils/Color.hpp
	g++ -o ../bin/test-color.o -c Tests/test-color.cpp $(CFLAGS)

color.o: Utils/Color.cpp Utils/Color.hpp Utils/UtilsException.hpp
	g++ -o ../bin/color.o -c Utils/Color.cpp $(CFLAGS)

shape.o: Shape/Shape.cpp Shape/Shape.hpp Geometry/Vector2D.hpp Utils/Color.hpp
	g++ -o ../bin/shape.o -c Shape/Shape.cpp $(FLAGS)

circle.o: Shape/Circle.cpp Shape/Circle.hpp Shape/Shape.hpp Visitor/ServerDrawer.hpp Visitor/SaveVisitor.hpp
	g++ -o ../bin/circle.o -c Shape/Circle.cpp $(CFLAGS)

polygon.o: Shape/Polygon.cpp Shape/Polygon.hpp Shape/Shape.hpp Visitor/ServerDrawer.hpp Visitor/SaveVisitor.hpp
	g++ -o ../bin/polygon.o -c Shape/Polygon.cpp $(CFLAGS)

composedshape.o: Shape/ComposedShape.cpp Shape/ComposedShape.hpp Shape/Shape.hpp Visitor/ServerDrawer.hpp Visitor/SaveVisitor.hpp
	g++ -o ../bin/composedshape.o -c Shape/ComposedShape.cpp $(CFLAGS)

segment.o: Shape/Segment.cpp Shape/Segment.hpp Shape/Shape.hpp Visitor/ServerDrawer.hpp Visitor/SaveVisitor.hpp
	g++ -o ../bin/segment.o -c Shape/Segment.cpp $(CFLAGS)

triangle.o: Shape/Triangle.cpp Shape/Triangle.hpp Shape/Shape.hpp Visitor/ServerDrawer.hpp Visitor/SaveVisitor.hpp
	g++ -o ../bin/triangle.o -c Shape/Triangle.cpp $(CFLAGS)

qtdrawer.o: Visitor/QtDrawer.cpp Visitor/QtDrawer.hpp Visitor/DrawingVisitor.hpp Network/Socket.hpp Shape/Circle.hpp Shape/Segment.hpp Shape/Triangle.hpp Shape/Polygon.hpp
	g++ -o ../bin/qtdrawer.o $(INCDIRS) -c Visitor/QtDrawer.cpp $(FLAGS)

serverdrawer.o: Visitor/ServerDrawer.cpp Visitor/ServerDrawer.hpp Visitor/DrawingVisitor.hpp Network/Socket.hpp Shape/Circle.hpp Shape/Segment.hpp Shape/Triangle.hpp Shape/Polygon.hpp
	g++ -o ../bin/serverdrawer.o -c Visitor/ServerDrawer.cpp $(FLAGS)

savetextvisitor.o: Visitor/SaveTextVisitor.cpp Visitor/SaveTextVisitor.hpp Shape/Circle.hpp Shape/Triangle.hpp Shape/Segment.hpp Shape/Polygon.hpp
	g++ -o ../bin/savetextvisitor.o -c Visitor/SaveTextVisitor.cpp $(FLAGS)

shapecreatorlink.o: Loader/ShapeCreatorLink.cpp Loader/ShapeCreatorLink.hpp Loader/ShapeCreator.hpp
	g++ -o ../bin/shapecreatorlink.o -c Loader/ShapeCreatorLink.cpp $(FLAGS)

segmentcreator.o: Loader/SegmentCreator.cpp Loader/ShapeCreatorLink.hpp
	g++ -o ../bin/segmentcreator.o -c Loader/SegmentCreator.cpp $(FLAGS)

trianglecreator.o: Loader/SegmentCreator.cpp Loader/ShapeCreatorLink.hpp
	g++ -o ../bin/trianglecreator.o -c Loader/TriangleCreator.cpp $(FLAGS)

polygoncreator.o: Loader/PolygonCreator.cpp Loader/ShapeCreatorLink.hpp
	g++ -o ../bin/polygoncreator.o -c Loader/PolygonCreator.cpp $(FLAGS)

composedshapecreator.o: Loader/ComposedShapeCreator.cpp Loader/ShapeCreatorLink.hpp
	g++ -o ../bin/composedshapecreator.o -c Loader/ComposedShapeCreator.cpp $(FLAGS)

circlecreator.o: Loader/CircleCreator.cpp Loader/ShapeCreatorLink.hpp
	g++ -o ../bin/circlecreator.o -c Loader/CircleCreator.cpp $(FLAGS)

shapeloader.o: Loader/ShapeLoader.hpp
	g++ -o ../bin/shapeloader.o -c Loader/ShapeLoader.hpp $(FLAGS)

shapeloaderlink.o: Loader/ShapeLoaderLink.hpp Loader/ShapeLoaderLink.cpp Loader/ShapeLoaderException.hpp
	g++ -o ../bin/shapeloaderlink.o -c Loader/ShapeLoaderLink.cpp

shapeloadertext.o: Loader/ShapeLoaderText.hpp Loader/ShapeLoaderText.cpp Loader/ShapeLoaderException.hpp Loader/ShapeCreator.hpp
	g++ -o ../bin/shapeloadertext.o -c Loader/ShapeLoaderText.cpp

test-loader.o: Tests/test-loader.cpp Loader/ShapeLoaderText.hpp Shape/Circle.hpp Utils/Color.hpp Visitor/SaveTextVisitor.hpp
	g++ -o ../bin/test-loader.o -c Tests/test-loader.cpp $(CFLAGS)

shapeloaderexception.o: Loader/ShapeLoaderException.hpp Loader/ShapeLoaderException.cpp
	g++ -o ../bin/shapeloaderexception.o -c Loader/ShapeLoaderException.cpp

test-loader: shapeloadertext.o color.o savetextvisitor.o vector2d.o shapeloaderexception.o radianangle.o shapeloaderlink.o utilsexception.o test-loader.o segmentcreator.o shapecreatorlink.o circlecreator.o trianglecreator.o polygoncreator.o composedshapecreator.o shape.o circle.o segment.o triangle.o polygon.o composedshape.o
	g++ -o ../bin/test-loader ../bin/shapeloadertext.o ../bin/color.o ../bin/savetextvisitor.o ../bin/vector2d.o ../bin/shapeloaderexception.o ../bin/radianangle.o ../bin/shapeloaderlink.o ../bin/utilsexception.o ../bin/test-loader.o ../bin/segmentcreator.o ../bin/shapecreatorlink.o ../bin/circlecreator.o ../bin/polygoncreator.o ../bin/trianglecreator.o ../bin/composedshapecreator.o ../bin/shape.o ../bin/circle.o ../bin/triangle.o ../bin/polygon.o ../bin/composedshape.o ../bin/segment.o

test-qtdrawer.o:
	g++ -o ../bin/test-qtdrawer.o $(INCDIRS) -c Tests/test-qtdrawer.cpp $(CFLAGS)

test-qtdrawer: test-qtdrawer.o circle.o geometryexception.o \
composedshape.o radianangle.o color.o utilsexception.o shape.o \
polygon.o triangle.o segment.o qtdrawer.o vector2d.o
	g++ -o ../bin/test-qtdrawer ../bin/test-qtdrawer.o \
../bin/circle.o ../bin/composedshape.o ../bin/polygon.o \
../bin/triangle.o ../bin/segment.o ../bin/vector2d.o \
../bin/geometryexception.o ../bin/radianangle.o ../bin/color.o \
../bin/utilsexception.o ../bin/shape.o ../bin/qtdrawer.o \
$(LIBS) $(CFLAGS)

clean:
	rm -rf ../bin/*.o

mrproprer: clean
	rm -rf ../bin/*
