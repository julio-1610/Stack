#include "StackArray.h"
#include <assert.h>
#include <iostream>

template<typename T>
void StackArray<T>::push(T e) {
	assert(sp >= data);
	int numElem = sp - data;
	if(numElem == size) {
		resize();
	}
	*sp = e;
	sp++;
	assert(!empty());
	assert(top() == e);
	assert(sp > data);
}

template<typename T>
void StackArray<T>::pop() {
	assert(!empty());
	sp--;
	assert(sp >= data);
}

template<typename T>
T StackArray<T>::top() {
	assert(!empty());
	return *(sp - 1);
}

template<typename T>
bool StackArray<T>::empty() {
	assert(sp >= data);
	return sp == data;
}

template<typename T>
void StackArray<T>::resize() {
	assert(!empty());
	int newSize = size + RESIZEFACTOR;
	T* newdata = new T[newSize];
	int numElem = sp - data;
	sp = newdata + numElem;
	for(int i = 0; i < size; i++)
		newdata[i] = data[i];
	T* olddata = data;
	data = newdata;
	size = newSize;
	sp = newdata + numElem;
	
	delete[] olddata;
}
template<typename T>
void StackArray<T>::print() {
	assert(!empty());
	T* aux = data;
	std::cout << "Stack\n";
	while(aux < sp) {
		std::cout << *aux << "\n";
		aux++;
	}
}

int main() {
	Stack<int>* s = new StackArray<int>(2);
	s->push(12);
	s->push(9);
	s->push(1);
	std::cout << s->top() << "\n";
	s->print();

	StackArray<int> stack(3);
	stack.push(3);
	stack.push(1);
	std::cout << stack.top() << "\n";
	stack.pop();
	stack.push(4);
	stack.push(9);
	stack.push(1);
	stack.print();
	return 0;
}