CFLAGS = -Wall -ansi

all: test-vector2D

test-vector2D: test-vector2D.o vector2d.o radianangle.o geometryexception.o
	g++ -o ../bin/test-vector2D ../bin/test-vector2D.o ../bin/vector2d.o ../bin/radianangle.o ../bin/geometryexception.o $(CFLAGS)

test-vector2D.o: Tests/test-vector2D.cpp Geometry/Vector2D.hpp
	g++ -o ../bin/test-vector2D.o -c Tests/test-vector2D.cpp $(CFLAGS)

vector2d.o: Geometry/Vector2D.cpp Geometry/Vector2D.hpp Geometry/RadianAngle.hpp
	g++ -o ../bin/vector2d.o -c Geometry/Vector2D.cpp $(CFLAGS)

geometryexception.o: Geometry/GeometryException.cpp Geometry/GeometryException.hpp
	g++ -o ../bin/geometryexception.o -c Geometry/GeometryException.cpp $(CFLAGS)

networkexception.o: Network/NetworkException.cpp Network/NetworkException.hpp
	g++ -o ../bin/networkexception.o -c Network/NetworkException.cpp $(CFLAGS)

socket.o: Network/Socket.cpp Network/Socket.hpp Network/NetworkException.hpp
	g++ -o ../bin/socket.o -c Network/Socket.cpp $(CFLAGS)

radianangle.o: Geometry/RadianAngle.cpp Geometry/RadianAngle.hpp Geometry/GeometryException.hpp
	g++ -o ../bin/radianangle.o -c Geometry/RadianAngle.cpp $(CFLAGS)

clean:
	rm -rf ../bin/*.o

mrproprer: clean
	rm -rf ../bin/sujet_2015
