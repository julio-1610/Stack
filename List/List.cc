#include "List.h"
#include <iostream>
#include <assert.h>

using namespace std;

List::List(){
  last = nullptr;
  assert(size() == 0);
}

List* List::append(int e){
  if(isEmpty()){
    last = new Node;
    last->data = e;
    last->next = last;
    assert(size() == 1);
    assert(head() == e);
    return this;
  }
  Node* n = new Node;
  n->data = e;
  n->next = last->next;
  last->next = n;
  last = n;
  return this;
  assert(size() > 0);
  assert(!isEmpty());
}

int List::head(){
  assert(!isEmpty());
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
	return this->last == nullptr;
}

void List::print() {
  assert(!isEmpty());
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
  assert(!(k < 0 && k >= s));
  
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