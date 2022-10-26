#include "StackArray.h"

int main() {
  StackArray<float> s(8);
  s.push(5.2);
  s.push(3.9);
  s.print(); 
  return 0;
}
