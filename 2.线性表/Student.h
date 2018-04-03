#include <iostream>
#include <string.h>
using namespace std;

struct Student
{
  char name[20];
  double score;
  friend ostream& operator<<(ostream& out,Student &stu)
  {
    out<<"("<<stu.name<<","<<stu.score<<")";
    return out;
  }
  bool operator==(Student &stu)
  {
    return strcmp(this->name,stu.name)==0;
  }
};
