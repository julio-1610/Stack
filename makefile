all: StackArray.o
	g++ StackArray.o
StackArray.o: StackArray.cc 
	g++ -c StackArray.cc

