#include <iostream>
#include <fstream>
#include "FileReader.h"
class FileReader;

using namespace std;

int main (int argc, char **argv)
{
  //Initialize preLine
  FileReader fR = FileReader();
  GenQueue<Student*> *preLine = fR.createStudents(argv[1]);
  //Initialize line
  GenQueue<Student*> *line = new GenQueue<Student*>();
  //Initialize Windows
  int numWindows = fR.getWindows();
  GenLinkedList<Window*> *windows = new GenLinkedList<Window*>();
  for(int i=0; i<numWindows; ++i){
    Window *tempWindow = new Window();
    windows->insertBack(tempWindow);
  }
  //Initialize Clock
  int clock = 0;
  //Initialize array for student wait times
  int studentWaitTimes[preLine->getSize()] = {0};
  int studentWaitPos = 0;
  //Initialize LL for Window idle times
  GenLinkedList<int> windowIdleTimes = GenLinkedList<int>();

  int totalStudents = preLine->getSize();

  //TESTING VARIABLE
  int windowTester = 0;

  //main loop for each clock tick
  bool keepGoing = true;
  while(keepGoing){

    /*
    //TESTING
    cout << endl;
    cout << "---BEGINNING OF ROUND---" << endl;
    cout << "Clock Tick: " << clock << endl;
    //END TESTING

    //TESTING
    windowTester = 0;
    for(int i=0; i<numWindows; i++){
      if(windows->peekPosition(i)->isOpen()){
        windowTester++;
      }
    }
    cout << "Before window->deletion (open Windows): " << windowTester << endl;
    //END TESTING
    */

    cout << "around " << clock << endl;

    //--Move student from window to deletion (and get window stats)
    for(int i=0; i<numWindows; ++i){
      //cout << "     Window " << i << "'s open status is: " << windows->peekPosition(i)->isOpen() << endl;
      if(!(windows->peekPosition(i)->isOpen())){ //If window is not open
        //test to see if current window student time == the time the student needs
        //cout << "     Window " << i << "'s Window time and student needed time (w/s): " << windows->peekPosition(i)->getCurrStuTime() << "/" << windows->peekPosition(i)->getStudent()->getWindow() << endl;
        if(windows->peekPosition(i)->getCurrStuTime() == windows->peekPosition(i)->getStudent()->getWindow()){
          //***COLLECT IDLE STATISTICS
          windowIdleTimes.insertBack(windows->peekPosition(i)->getIdle());
          //RESET
          windows->peekPosition(i)->reset();
          //cout << "        WINDOW RESET- OPEN STATUS IS: "  << windows->peekPosition(i)->isOpen() << endl;
        }
      }
    }

    /*
    //TESTING
    windowTester = 0;
    for(int i=0; i<numWindows; i++){
      if(windows->peekPosition(i)->isOpen()){
        windowTester++;
      }
    }
    cout << "After window->deletion (open Windows): " << windowTester << endl;
    //END TESTING

    //TESTING
    windowTester = 0;
    for(int i=0; i<numWindows; i++){
      if(windows->peekPosition(i)->isOpen()){
        windowTester++;
      }
    }
    cout << "Before line->window (line Size/open Windows): " << line->getSize() << "/" << windowTester << endl;
    //END TESTING
    */

    //---Move student from line to Window (and get line stats)
    while(line->getSize()>0){
      //Check if any windows are open
      int openWindow = -1;
      for(int i=0; i<numWindows; ++i){
        if(windows->peekPosition(i)->isOpen()){
          openWindow=i;
          windows->peekPosition(i)->setOpen(false);
          break;
        }
      }
      //Move student to next window
      if(openWindow == -1){ //BREAK WHEN NO WINDOWS ARE OPEN
        break;
      }else{
        //***ADD WAIT TIME TO ARRAY
        studentWaitTimes[studentWaitPos] = clock - line->peek()->getArrival()-1;
        ++studentWaitPos;
        //ELSE POP FROM LINE AND ADD TO WINDOW
        windows->peekPosition(openWindow)->setStudent(line->remove());
      }
    }

    /*
    //TESTING
    windowTester = 0;
    for(int i=0; i<numWindows; i++){
      if(windows->peekPosition(i)->isOpen()){
        windowTester++;
      }
    }
    cout << "After line->window (line Size/open Windows): " << line->getSize() << "/" << windowTester << endl;
    //END TESTING

    //TESTING
    cout << "Before pLine->Line (preLine Size/Line Size): " << preLine->getSize() << "/" << line->getSize() << endl;
    //END TESTING
    */

    //---Move student from preLine to line
    if(preLine->getSize()>0){
      while(preLine->peek()->getArrival()==clock){
        line->insert(preLine->remove());
        if(preLine->getSize()==0){
          break;
        }
      }
    }

    /*
    //TESTING
    cout << "After pLine->Line (preLine Size/Line Size): " << preLine->getSize() << "/" << line->getSize() << endl;
    //END TESTING
    */

    cout << "bround " << clock << endl;

    //Increment idle time for open Winddows
    for(int i=0; i<numWindows; ++i){
      //IF WINDOW IS OPEN
      if(windows->peekPosition(i)->isOpen()){
        cout << "Incrementing window #" << i << endl;
        windows->peekPosition(i)->incIdle();
        //if statement to check if window gets left open for more than 10 minutes
        if(windows->peekPosition(i)->getIdle()>5){
          windows->peekPosition(i)->idleMoreThan5 = true; //first time I realized I can just set member vars like this
        }
      //IF WINDOW IS CLOSED
      }else{
        windows->peekPosition(i)->incCurrStuTime();
      }
    }

    ++clock;

    //make keepGoing false if all 3 are empty (preline, line, windows)
    int finalWindowCheckInt = 0;
    for(int i=0; i<numWindows; i++){
      if(windows->peekPosition(i)->isOpen()){
        finalWindowCheckInt++;
      }
    }
    bool finalWindowCheckBool = false;
    if(finalWindowCheckBool=numWindows){
      finalWindowCheckBool = true;
    }
    if(preLine->getSize()==0 && line->getSize()==0 && finalWindowCheckBool){
      keepGoing = false;
    }
  }







  /*
  //Print the array of wait times (accurate)
  for(int i = 0; i < totalStudents; i++){
    cout << studentWaitTimes[i] << endl;
  }
  */

  //Print the list of idle times (not accurate)
  cout << endl;
  windowIdleTimes.printList();
  cout << endl;

  //Calculate the following:
  //1. The mean student wait time.
  float calcStudentMean = 0;
  for(int i = 0; i < totalStudents; i++){
    calcStudentMean += studentWaitTimes[i];
  }
  cout << "1. The mean student wait time: " << float(calcStudentMean)/float(totalStudents) << endl;

  //2. The median student wait time.
  //I ran out of time and couldn't find this in one of my previous projects, didn't want to copy from internet

  //3. The longest student wait time.
  int calcStudentMax = 0;
  for(int i = 0; i < totalStudents; i++){
    if(studentWaitTimes[i]>calcStudentMax){
      calcStudentMax = studentWaitTimes[i];
    }
  }
  cout << "3. The longest student wait time: " << calcStudentMax << endl;

  //4. The number of students waiting over 10 minutes
  int calcStudent10 = 0;
  for(int i = 0; i < totalStudents; i++){
    if(studentWaitTimes[i]>10){
      ++calcStudent10;
    }
  }
  cout << "4. The number of students waiting over 10 minutes: " << calcStudent10 << endl;

  //5. The mean window idle time
  int calcWindowMean = 0;
  for(int i = 0; i < windowIdleTimes.getSize(); i++){
    calcWindowMean += windowIdleTimes.peekPosition(i);
  }
  cout << "5. The mean window idle time: " << float(calcWindowMean)/float(windowIdleTimes.getSize()) << endl;


  //6. The longest window idle time
  int calcWindowMax = 0;
  for(int i = 0; i < windowIdleTimes.getSize(); i++){
    if(windowIdleTimes.peekPosition(i)>calcWindowMax){
      calcWindowMax = windowIdleTimes.peekPosition(i);
    }
  }
  cout << "6. The longest window idle time: " << calcWindowMax << endl;

  //7. Number of windows idle for over 5 minutes.
  int calcWindowNum5 = 0;
  for(int i=0; i<numWindows; i++){
    if(windows->peekPosition(i)->idleMoreThan5){
      ++calcWindowNum5;
    }
  }
  cout << "7. Number of windows idle for over 5 minutes: " << calcWindowNum5 << endl;

  /*
  //TESTING PRINT
  cout << "---Round Statistics--" << endl;
  cout << "BEGINNING" << endl;
  cout << "Clock: " << clock << endl;
  cout << "preLine Size: " << preLine->getSize() << endl;
  cout << "line Size: " << line->getSize() << endl;
  cout << endl;
  //END TESTING PRINT
  */

  /*
  //TESTING
  for(int i=0; i<numWindows; i++){
    cout << "Window Number: " << i << endl;
    cout << "Is open?:" << windows->peekPosition(i)->isOpen() << endl;
    cout << endl;
  }
  //END TESTING
  */

  /*
  //TESTING
  cout << "---LEAVING LINE---" << endl;
  cout << "Clock: " << clock << endl;
  cout << "Student wait position: " << studentWaitPos << endl;
  cout << "Number to be added: " << clock - line->peek()->getArrival() << endl;
  //END TESTING
  */

}
