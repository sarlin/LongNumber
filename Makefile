all: thirdLin
first:
	g++ MainFirst.c LibraryLong.c -o LabFirst -lm
second:
	g++ -c ClassLong.cpp LibraryLong.c
	g++ -shared -o ClassLong.dll ClassLong.o LibraryLong.o
	g++ MainSecond.cpp ClassLong.dll -I. -Wl,-rpath,. -L. -o LabSecond

thirdwin:
	swig -c++ -python ClassLong.i
	g++ -c ClassLong.cpp
	g++ -c LibraryLong.c
	g++ -c ClassLongWRAP.cxx -IC:\Python27\include
	g++ ClassLong.o LibraryLong.o ClassLongWRAP.o -Ic:\Python27\include -Lc:\Python27\libs -lPython27 -shared -o ClassLong.pyd
	rm -rf *.o *.cxx

thirdlin:
	swig -c++ -python -o ClassLongWRAP.cpp ClassLong.i
	g++ -c -fPIC ClassLong.cpp -o ClassLong.o
	g++ -c -fPIC LibraryLong.c -o LibraryLong.o
	g++ -fPIC -c ClassLongWRAP.cpp -I/usr/include/python2.7
	g++ -shared ClassLong.o LibraryLong.o ClassLongWRAP.o -o ClassLong.so
