CFLAGS = -Wall -ansi

all: test-vector2D

test-vector2D: test-vector2D.o vector2d.o radianangle.o geometryexception.o
	g++ -o ../bin/test-vector2D ../bin/test-vector2D.o ../bin/vector2d.o ../bin/radianangle.o ../bin/geometryexception.o $(CFLAGS)

test-socket: test-socket.o socket.o networkexception.o circle.o vector2d.o geometryexception.o radianangle.o color.o utilsexception.o shape.o serverdrawer.o
	g++ -o ../bin/test-socket ../bin/test-socket.o ../bin/socket.o ../bin/networkexception.o ../bin/circle.o ../bin/vector2d.o ../bin/geometryexception.o ../bin/radianangle.o ../bin/color.o ../bin/utilsexception.o ../bin/shape.o ../bin/serverdrawer.o $(CFLAGS)

test-shape: test-shape.o circle.o  vector2d.o geometryexception.o radianangle.o color.o utilsexception.o shape.o serverdrawer.o socket.o networkexception.o 
	g++ -o ../bin/test-shape ../bin/test-shape.o  ../bin/circle.o ../bin/vector2d.o ../bin/geometryexception.o ../bin/radianangle.o ../bin/color.o ../bin/utilsexception.o ../bin/shape.o ../bin/serverdrawer.o ../bin/socket.o ../bin/networkexception.o $(CFLAGS)

test-color: test-color.o color.o utilsexception.o
	g++ -o ../bin/test-color ../bin/test-color.o ../bin/color.o ../bin/utilsexception.o $(CFLAGS)

test-vector2D.o: Tests/test-vector2D.cpp Geometry/Vector2D.hpp
	g++ -o ../bin/test-vector2D.o -c Tests/test-vector2D.cpp $(CFLAGS)

vector2d.o: Geometry/Vector2D.cpp Geometry/Vector2D.hpp Geometry/RadianAngle.hpp
	g++ -o ../bin/vector2d.o -c Geometry/Vector2D.cpp $(CFLAGS)

geometryexception.o: Geometry/GeometryException.cpp Geometry/GeometryException.hpp
	g++ -o ../bin/geometryexception.o -c Geometry/GeometryException.cpp $(CFLAGS)

networkexception.o: Network/NetworkException.cpp Network/NetworkException.hpp
	g++ -o ../bin/networkexception.o -c Network/NetworkException.cpp $(CFLAGS)

utilsexception.o: Utils/UtilsException.cpp Utils/UtilsException.hpp
	g++ -o ../bin/utilsexception.o -c Utils/Utilsexception.cpp $(CFLAGS)

socket.o: Network/Socket.cpp Network/Socket.hpp Network/NetworkException.hpp
	g++ -o ../bin/socket.o -c Network/Socket.cpp $(CFLAGS)

radianangle.o: Geometry/RadianAngle.cpp Geometry/RadianAngle.hpp Geometry/GeometryException.hpp
	g++ -o ../bin/radianangle.o -c Geometry/RadianAngle.cpp $(CFLAGS)

test-socket.o: Tests/test-socket.cpp Network/Socket.hpp Shape/Circle.hpp Shape/Polygon.hpp Shape/Triangle.hpp Shape/Segment.hpp
	g++ -o ../bin/test-socket.o -c Tests/test-socket.cpp $(CFLAGS)

test-shape.o: Tests/test-shape.cpp Shape/Circle.hpp Shape/Polygon.hpp Shape/Triangle.hpp Shape/Segment.hpp
	g++ -o ../bin/test-shape.o -c Tests/test-shape.cpp $(CFLAGS)

test-color.o: Tests/test-color.cpp Utils/Color.hpp
	g++ -o ../bin/test-color.o -c Tests/test-color.cpp $(CFLAGS)

color.o: Utils/Color.cpp Utils/Color.hpp Utils/UtilsException.hpp
	g++ -o ../bin/color.o -c Utils/Color.cpp $(CFLAGS)

shape.o: Shape/Shape.cpp Shape/Shape.hpp Geometry/Vector2D.hpp Utils/Color.hpp
	g++ -o ../bin/shape.o -c Shape/Shape.cpp $(FLAGS)

circle.o: Shape/Circle.cpp Shape/Circle.hpp Shape/Shape.hpp Visitor/ServerDrawer.hpp Visitor/SaveVisitor.hpp
	g++ -o ../bin/circle.o -c Shape/Circle.cpp $(CFLAGS)

serverdrawer.o: Visitor/ServerDrawer.cpp Visitor/ServerDrawer.hpp Visitor/DrawingVisitor.hpp Network/Socket.hpp Shape/Circle.hpp Shape/Segment.hpp Shape/Triangle.hpp Shape/Polygon.hpp
	g++ -o ../bin/serverdrawer.o -c Visitor/ServerDrawer.cpp $(FLAGS)

clean:
	rm -rf ../bin/*.o

mrproprer: clean
	rm -rf ../bin/sujet_2015
