exe: lab1-1.o main.o
	g++   main.o lab1-1.o -o exe
main.o: main.cpp
	g++ -c main.cpp
lab1-1.o: lab1-1.cpp
	g++ -c lab1-1.cpp

clean:
	rm -f main.o lab1-1.o exe