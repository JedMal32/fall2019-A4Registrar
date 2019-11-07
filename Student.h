#include <iostream>

using namespace std;

class Student{
public:
   int timeWindow = 0;
   int timeArrival = 0;

   Student();
   Student(int w, int a);
   int getWindow();
   int getArrival();
};
