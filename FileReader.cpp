#include <iostream>
#include <fstream>
#include "FileReader.h"

using namespace std;

FileReader::FileReader(){

}

GenQueue<Student*> * FileReader::createStudents(string s){
  ifstream input(s);
  string windowsInput;
  getline(input, windowsInput);
  numWindows = stoi(windowsInput);
  GenQueue<Student*> *stu = new GenQueue<Student*>();
  string timeArrivalInput;
  while(getline(input, timeArrivalInput)){ //might be wrong?
    //get line time students arrive
    int timeArrival = stoi(timeArrivalInput);
    //get line number of students
    string numStudentsInput;
    getline(input, numStudentsInput);
    int numStudents = stoi(numStudentsInput);
    for(int i = 0; i < numStudents; i++){
      //get line for time student needs at window
      string timeWindowInput;
      getline(input, timeWindowInput);
      int timeWindow = stoi(timeWindowInput);
      //create student
      Student *temp = new Student(timeWindow, timeArrival);
      //add student to queue
      stu->insert(temp);
    }
  }
  return stu;
}

int FileReader::getWindows(){
  return numWindows;
}
