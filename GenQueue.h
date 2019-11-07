#include <iostream>
#include "GenLinkedList.cpp"

using namespace std;

template<typename t>
class GenQueue
{
  public:
    GenLinkedList<t> *myLL = new GenLinkedList<t>();

    GenQueue();
    GenQueue(int maxSize);
    ~GenQueue();
    void insert(t d);
    t remove();
    t peek();
    bool isEmpty();
    int getSize();
    void print();

};
