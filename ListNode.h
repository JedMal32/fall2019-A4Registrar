#include <iostream>
#include "Student.h"
class Student;

using namespace std;

template<typename t>
class ListNode{
  public:
    t data;
    ListNode *next;
    ListNode *prev;

    ListNode();
    ListNode(t d);
    ~ListNode();
};
