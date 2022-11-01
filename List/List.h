struct Node {
  int data;
  Node* next;
};
class List {
  public:
    List();
    List* append(int);
    int head();
    List* tail();
    bool isEmpty();
		int size();
    void print();
    int index(int);
  private:
    Node* last;  
};
