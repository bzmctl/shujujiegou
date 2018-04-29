#include <iostream>
#include <string.h>
#define N 3//N用来表示课程数目
using namespace std;

struct Student
{
  char name[20];//姓名
  char number[20];//学号
  int score[N];//多门课程成绩
  Student(){}
  Student(const char *name,const char *number,int sc[])
  {
    strcpy(this->name,name);
    strcpy(this->number,number);
    for(int i = 0; i < N; i++)
      this->score[i] = sc[i];
  }
  friend ostream& operator<<(ostream& out,Student &stu)
  {
    out<<stu.name<<" "<<stu.number<<" "<<stu.score[0]<<" "<<stu.score[1]<<" "<<stu.score[2];
    return out;
  }
  //练习2-9重载<,>运算符
  bool operator<(Student &stu)//按平均成绩分重载<
  {
    return (this->score[0]+this->score[1]+this->score[2]) / 3.0 < (stu.score[0]+stu.score[1]+stu.score[2]) / 3.0;
  }
  bool operator>(Student &stu)//按学号重载>
  {
    return strcmp(this->number,stu.number) > 0;
  }
  
  bool operator==(Student &stu)
  {
    return strcmp(this->name,stu.name)==0;
  }
  void operator=(Student &stu)
  {
    strcpy(this->name,stu.name);
    strcpy(this->number,stu.number);
    for(int i = 0; i < N; i++)
      this->score[i] = stu.score[i];
  }
};
