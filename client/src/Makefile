CFLAGS = -Wall -ansi

all: test-vector2D

test-vector2D: test-vector2D.o vector2d.o
	g++ -o ../bin/test-vector2D ../bin/test-vector2D.o ../bin/vector2d.o $(CFLAGS)

test-vector2D.o: test-vector2D.cpp Geometry/Vector2D.hpp
	g++ -o ../bin/test-vector2D.o -c test-vector2D.cpp $(CFLAGS)

vector2d.o : Geometry/Vector2D.cpp
	g++ -o ../bin/vector2d.o -c Geometry/Vector2D.cpp $(CFLAGS)

clean:
	rm -rf ../bin/*.o

mrproprer: clean
	rm -rf ../bin/sujet_2015
