#include "List.h"
#include <iostream>

using namespace std;

List::List(){
  last = nullptr;
}

List* List::append(int e){
  if(isEmpty()){
    last = new Node;
    last->data = e;
    last->next = last;
    return this;
  }
  Node* n = new Node;
  n->data = e;
  n->next = last->next;
  last->next = n;
  last = n;
  return this;
}

int List::head(){
  return last->next->data;
}

int List::size(){
  int c = 0;
  Node* iter = last;
  while(iter){
    iter = iter->next;
    if(iter == last)
      iter = NULL;
    c++;
  }
  return c;
}

bool List::isEmpty() {
	if(this->last == nullptr) {
		return true;
	}
	return false;
}

void List::print() {
  if(isEmpty()) { return; }
  Node* iter = last;
  while(iter){
    iter = iter->next;
    cout << iter->data << endl;
    if(iter == last)
      iter = NULL;
  }
}

int List::index(int k) {
  int s = size();
  if(k < 0 && k >= s) { return -1; }
  
  int i = 0;
  Node* iter = last;
  Node* n;
  while(iter) {
    iter = iter->next;
    if(i == (k - 1)) {
      n = iter->next;
      iter->next = n->next;
      return n->data;
    }
    i++;
  }
  return 0;
}