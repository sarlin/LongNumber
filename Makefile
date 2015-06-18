first:
	g++ MainFirst.c LibraryLong.c -o LabFirst -lm
second:
	g++ -c ClassLong.cpp LibraryLong.c
	g++ -shared -o ClassLong.dll ClassLong.o LibraryLong.o
	g++ MainSecond.cpp ClassLong.dll -I. -Wl,-rpath,. -L. -o LabSecond
