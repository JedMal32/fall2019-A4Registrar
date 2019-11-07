#include <iostream>
#include <fstream>
#include "Window.h"
class Window;

using namespace std;

class FileReader{
public:
  int numWindows;

  FileReader();
  GenQueue<Student*> * createStudents(string s);
  int getWindows();

};
