#include <iostream>
#include "Window.h"

using namespace std;

Window::Window(){
  currStudent = NULL;
  timeCurrStu = 0;
  open = true;
  idleTime = 0;
  idleMoreThan5 = false;
}

bool Window::isOpen(){
  return open;
}

void Window::setOpen(bool o){
  open = o;
}

void Window::setStudent(Student* s){
  currStudent = s;
}

Student* Window::getStudent(){
  return currStudent;
}

void Window::incIdle(){
  ++idleTime;
}

void Window::setIdle(int i){
  idleTime = i;
}

int Window::getIdle(){
  return idleTime;
}

void Window::incCurrStuTime(){
  ++timeCurrStu;
}

void Window::setCurrStuTime(int c){
  timeCurrStu = c;
}

int Window::getCurrStuTime(){
  return timeCurrStu;
}

void Window::reset(){
  currStudent = NULL;
  open = true;
  idleTime = 0;
  timeCurrStu = 0;
}
