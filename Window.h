#include <iostream>
#include "GenQueue.cpp"

using namespace std;

class Window{
public:
  Student* currStudent;
  int timeCurrStu;
  bool open;
  int idleTime;
  bool idleMoreThan5;

  Window();
  bool isOpen();
  void setOpen(bool o);

  void setStudent(Student* s);
  Student* getStudent();

  void incIdle();
  void setIdle(int i);
  int getIdle();

  void incCurrStuTime();
  void setCurrStuTime(int c);
  int getCurrStuTime();


  void reset();
};
