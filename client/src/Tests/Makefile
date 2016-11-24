CFLAGS = -Wall -ansi -fdiagnostics-color=auto
INCDIRS=-I/usr/include/qt4 -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtCore
LIBS=-lQtCore -lQtGui

testqt: testqt.o
	g++ -o ./bin/testqt ./bin/testqt.o $(LIBS) $(CFLAGS)

testqt.o: TestQt.cpp
	g++ -o ./bin/testqt.o $(INCDIRS) -c TestQt.cpp $(FLAGS)

clean:
	rm -rf ./bin/*.o

mrproprer: clean
	rm -rf ./bin/*
