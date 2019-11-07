#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(){

}

Student::Student(int w, int a){
  timeWindow = w;
  timeArrival = a;
}

int Student::getWindow(){
  return timeWindow;
}

int Student::getArrival(){
  return timeArrival;
}
