#include "List.h"
#include <iostream>

using namespace std;
int main() {
	List* list = new List();
	list->append(1);
	list->append(2);
	list->append(3);
	list->append(15);
	int l = list->head();
	cout << l << endl << endl;
	int s = list->size();
	cout << s << endl << endl;
	list->print();
	cout << endl;

	int x = list->index(2);
	cout << x << endl << endl;

	list->print();
	return 0;
}
