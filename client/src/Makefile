CFLAGS = -Wall -ansi

all: main

main: main.o vector2d.o
	g++ -o ../bin/client ../bin/main.o ../bin/vector2d.o $(CFLAGS)

main.o: main.cpp Vector2D.hpp
	g++ -o ../bin/main.o -c main.cpp $(CFLAGS)

vector2d.o : Vector2D.cpp
	g++ -o ../bin/vector2d.o -c Vector2D.cpp $(CFLAGS)

clean:
	rm -rf ../bin/*.o

mrproprer: clean
	rm -rf ../bin/sujet_2015
