#include "StackArray.h"
#include <assert.h>
#include <iostream>
#include <gtest/gtest.h>

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

class StackArrayTest: public ::testing::Test {
	protected:
		StackArray<int>* stack1 = new StackArray<int>(2);
		StackArray<int>* stack2 = new StackArray<int>(1);
		void SetUp() override {
			stack1->push(3);
			stack2->push(1);
			stack2->push(9);
		}
};

TEST_F(StackArrayTest, FunctionTests) {
	EXPECT_EQ(stack1->top(), 3);
	EXPECT_EQ(stack1->empty(), false);
	stack2->pop();
	EXPECT_EQ(stack2->top(), 1);
	stack1->pop();
	EXPECT_EQ(stack1->empty(), true);
}

int main(int argc, char **argv) {
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
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}