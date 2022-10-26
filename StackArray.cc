#include "StackArray.h"
#include <assert.h>
#include <iostream>

using namespace std;

template<typename T>
void StackArray<T>::push(T e) {
	int numElem = sp - data;
	if(numElem == size) {
		resize();
	}
	*sp = e;
	sp++;
}

template<typename T>
void StackArray<T>::pop() {
	if(empty())
		return;
	sp--;
}

template<typename T>
T StackArray<T>::top() {
	return *(sp - 1);
}

template<typename T>
bool StackArray<T>::empty() {
	assert(!empty());
	return sp == data;
}

template<typename T>
void StackArray<T>::resize() {
	int newSize = size + RESIZEFACTOR;
	T newdata[] = new T[newSize];
	int numElem = sp - data;
	sp = newdata + numElem;
	for(int i = 0; i < size; i++)
		newdata[i] = data[i];
	T olddata[] = data;
	data = newdata;
	size = newSize;
	sp = newdata + numElem;

	delete[] olddata;
}

template<typename T>
void StackArray<T>::print() {
	assert(!empty());
	T* n = data;
	while(n <= sp) {
		cout << *n << "\n";
		n++;
	}
}