all: main.o StackArray.o
	g++ -c main.o StackArray.o
StackArray.o: StackArray.cc
	g++ -c StackArray.cc
main.o: main.cc
	g++ -c main.cc

