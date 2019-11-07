#include <iostream>
#include "GenLinkedList.h"

using namespace std;

template<typename t>
GenLinkedList<t>::GenLinkedList(){
  size = 0;
  front = NULL; //nullptr
  back = NULL;
}

template<typename t>
GenLinkedList<t>::~GenLinkedList(){
  //I need to do this (use book!)
  //I will have to iterate through the list
}

template<typename t>
void GenLinkedList<t>::insertFront(t d){
  ListNode<t> *node = new ListNode<t>(d);
  if(isEmpty()){ //isEmpty only checks if size == 0
    back = node;
  }else{
    node->next = front;
    front->prev = node;
  }
  front = node;
  size++;
}

template<typename t>
void GenLinkedList<t>::insertBack(t d){
  ListNode<t> *node = new ListNode<t>(d);
  if(isEmpty()){ //isEmpty only checks if size == 0
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

template<typename t>
t GenLinkedList<t>::removeFront(){
  if(isEmpty()){
    cout << "List is Empty! Nothing to remove." << endl;
  }else{
    ListNode<t> *ft = front; //ft is temp pointer
    if(size == 1){ //or if(front->next == NULL), both evaluate the same thing
      back = NULL;
    }else{ //more than one element in the list
      front->next->prev = NULL;
    }
    front = front->next; //updates front to next variable
    t temp = ft->data; //temp var to hold data for first item
    ft->next = NULL; //deletes the old front using temp pointer
    size--;
    delete ft; //deletes pointer
    return temp; //returns value
  }
}

template<typename t>
t GenLinkedList<t>::removeBack(){
  if(isEmpty()){
    cout << "List is Empty! Nothing to remove." << endl;
  }else{
    ListNode<t> *bk = back;
    if(size == 1){
      front = NULL;
    }else{
      back->prev->next = NULL;
    }
    back = back->prev;
    t temp = bk->data;
    bk->prev = NULL;
    size--;
    delete bk;
    return temp;
  }
}

template<typename t>
t GenLinkedList<t>::removePosition(int position){ //aka int key
  if(isEmpty()){
    cout << "List is Empty! Nothing to remove." << endl;
  }else{
    int index = 0;
    ListNode<t> *curr = front;
    while(index != position){
      curr = curr->next;
      if(curr == NULL){
        cout << "Index not found in list! Nothing to remove." << endl;
      }
      ++index;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    curr->next = NULL;
    curr->prev = NULL;
    size--;
    return curr->data;
  }
}

template<typename t>
int GenLinkedList<t>::find(t d){
  if(isEmpty()){
    cout << "List is Empty! Nothing to find." << endl;
  }else{
    int index = 0;
    ListNode<t> *curr = front;
    while(curr->data != d){
      curr = curr->next;
      if(curr == NULL){
        cout << "Value not found in list!" << endl;
        index = -1;
        break;
      }
      ++index;
    }
    return index;
  }
}

template<typename t>
t GenLinkedList<t>::peekPosition(int position){
  if(isEmpty()){
    cout << "List is Empty! Can not peek." << endl;
  }else{
    int index = 0;
    ListNode<t> *curr = front;
    while(index != position){
      curr = curr->next;
      if(curr == NULL){
        cout << "Index not found in list! Nothing to remove." << endl;
      }
      ++index;
    }
    return curr->data;
  }
}

template<typename t>
bool GenLinkedList<t>::isEmpty(){
  return (size == 0);
}

template<typename t>
void GenLinkedList<t>::printList(){
  ListNode<t> *curr = front;
  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
}

template<typename t>
unsigned int GenLinkedList<t>::getSize(){
  return size;
}
