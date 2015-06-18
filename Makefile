firstwin:
	g++ MainFirst.c LibraryLong.c -o LabFirst -lm
firstlin:
	gcc -c -fPIC LibraryLong.c -o LibraryLong.o
	gcc -shared -o LibraryLong.so LibraryLong.o
	gcc -c MainFirst.c
	gcc main.o -L. -lLibraryLong -o LabFirst
secondwin:
	g++ -c ClassLong.cpp LibraryLong.c
	g++ -shared -o ClassLong.dll ClassLong.o LibraryLong.o
	g++ MainSecond.cpp ClassLong.dll -I. -Wl,-rpath,. -L. -o LabSecond
