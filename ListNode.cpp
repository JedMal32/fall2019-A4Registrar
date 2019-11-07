#include <iostream>
#include "ListNode.h"

using namespace std;

template<typename t>
ListNode<t>::ListNode(){

}

template<typename t>
ListNode<t>::ListNode(t d){
  data = d;
  next = NULL; //null pointer
  prev = NULL;
}

template<typename t>
ListNode<t>::~ListNode(){
  next == NULL;
  prev == NULL;
}
