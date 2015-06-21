all: thirdlin
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
	g++ -c ClassLong_wrap.cxx -IC:\Python27\include
	g++ ClassLong.o LibraryLong.o ClassLong_wrap.o -Ic:\Python27\include -Lc:\Python27\libs -lPython27 -shared -o _ClassLong.pyd
	rm -rf *.o *.cxx

thirdlin:
	swig -c++ -python -o ClassLong_wrap.cpp ClassLong.i
	g++ -c -fPIC ClassLong.cpp -o ClassLong.o
	g++ -c -fPIC LibraryLong.c -o LibraryLong.o
	g++ -fPIC -c ClassLong_wrap.cpp -I/usr/include/python2.7
	g++ -shared ClassLong.o LibraryLong.o ClassLong_wrap.o -o _ClassLong.so
