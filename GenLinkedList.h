#include <iostream>
#include "ListNode.cpp"

using namespace std;

template<typename t>
class GenLinkedList{
  private:
    ListNode<t> *front;
    ListNode<t> *back;
    unsigned int size;
  public:
    GenLinkedList();
    ~GenLinkedList();

    void insertFront(t d);
    void insertBack(t d);
    t removeFront();
    t removeBack();
    t removePosition(int position);
    int find(t d); //returns position of a value
    t peekPosition(int position);

    bool isEmpty();
    void printList();
    unsigned int getSize();
};
