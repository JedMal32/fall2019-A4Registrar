#include <iostream>
#include "GenQueue.h"

using namespace std;

template<typename t>
GenQueue<t>::GenQueue(){
  //myLL = new ;
}

template<typename t>
GenQueue<t>::~GenQueue(){
  //I need to do this
}

template<typename t>
void GenQueue<t>::insert(t d){
  myLL->insertBack(d);
}

template<typename t>
t GenQueue<t>::remove(){
  return myLL->removeFront();
}

template<typename t>
t GenQueue<t>::peek(){
  //return myLL.peekPosition(0);
  return myLL->peekPosition(0);
}

template<typename t>
bool GenQueue<t>::isEmpty(){
  return myLL->isEmpty();
}

template<typename t>
int GenQueue<t>::getSize(){
  return myLL->getSize();
}

template<typename t>
void GenQueue<t>::print(){
  myLL->printList();
}
