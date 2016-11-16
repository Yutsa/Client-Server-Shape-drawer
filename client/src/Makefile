CFLAGS = -Wall -ansi

all: client

client:

vector2d.o : Vector2D.cpp
	g++ -o ../bin/vector2d.o -c Vector2D.cpp $(CFLAGS)

clean:
	rm -rf ../bin/*.o

mrproprer: clean
	rm -rf ../bin/sujet_2015
