#include "Student.h"
#include "SinglyList.h"//使用单链表管理学生成绩表
class StuManager
{
public:
  StuManager()
  {
    int score[] = {98,97,91},score1[]={93,90,100},score2[]={98,99,90};
    Student s[] = {Student("desk","1001",score),Student("door","1002",score1),Student("light","1003",score2)};
    list = new SinglyList<Student>(s,3);//初始化学生信息
  }
  ~StuManager()
  {
    delete list;
  }
  //1.存储管理学生的多门课程成绩
  void setscore(Student &,double sc[],int n);//设置学生分数
  //2.提供学生对象的插入，删除，查找操作
  Student& insert(SinglyList<Student>&,Student &);
  void del(SinglyList<Student>&,Student &);
  Student& search(SinglyList<Student>&,Student &);
  //3.提供学生各门成绩的查询操作
  Student& searchscore(SinglyList<Student>&,Student &);
  //4.提供统计指定课程的平均值功能
  double avgall(SinglyList<Student> &,int i);
  //5.提供指定课程按完美，优秀，良好，中等，及格，不及格6个等级统计人数功能
  void statistics(SinglyList<Student>& ,int i,int grade[],int num,int res[]);//i用于指定哪门课程,grade指定成绩分组信息,num分组个数,res返回结果数组
  //6.指定学生成绩表按学号排序，或按成绩排序
  void sort(SinglyList<Student> &);
  //7.能够从文件中读取学生信息，并将学生信息的各种修改结果写入文件
  //分析:
  //1.构造学生信息时从文件中构造
  void readfile(string path);
  //2.将学生信息用单链表存储,从而实现对文件信息的管理
  //3.将修改后的单链表信息输出到文件中
  void savefile(SinglyList<Student> &,string path);
  // void alterbyfile(SinglyList<Student> &,string path);//path文件路径
  //private:
  SinglyList<Student> *list,*list1;
  //从文件中读取数据
  // Student* read(Student stu[],string path);
};
void StuManager::setscore(Student &stu,double sc[],int n)
{
  for(int i = 0; i < n; i++)
    stu.score[i] = sc[i];
}
Student& StuManager::insert(SinglyList<Student> &list, Student &stu)
{
  return list.insert(stu)->data;
}
void StuManager::del(SinglyList<Student> &list, Student &stu)
{
  list.removeFirst(stu);
}
Student& StuManager::search(SinglyList<Student> &list, Student &stu)
{
  return list.search(stu)->data;
}
Student& StuManager::searchscore(SinglyList<Student> &list, Student &stu)
{
  return search(list,stu);
}
double StuManager::avgall(SinglyList<Student> &list, int i)
{
  return list.averagestusc(i);
}
void StuManager::statistics(SinglyList<Student> &list,int i,int grade[],int num,int res[])
{
  list.groupCount(i,grade,num,res);
}
void StuManager::sort(SinglyList<Student> &list)
{
  list.sort();
}
void StuManager::readfile(string path)
{
  list1 = new SinglyList<Student>(path);
}
void StuManager::savefile(SinglyList<Student> &list, string path)
{
  ofstream out;
  list.savefile(out,path);
  delete list1;
}
int main()//程序修改时一定要保证不影响以前的程序正常运行
{
  StuManager s;
  int score[]={91,92,93},sc1[]={100,100,100};
  Student s1("农夫山泉","10004",score);

  // s.readfile("application/11.txt");
  s.readfile("student.txt");
  // s.setscore(s1,sc1,3);
  //s.del(*s.list1,s1);
  //s.insert(*s.list1,s1);
  // double res = s.avgall(*s.list1,0);
  //cout<<res;
  //分段统计学生信息
  int grade[]={0,60,70,80,90,100};
  int res[6]={0};
  s.statistics(*s.list1,2,grade,6,res);
  for(int i = 0; i < 6; i++)
    cout<<res[i]<<" ";
  cout<<endl;
  s.sort(*s.list1);
  // cout<<*s.list1;
  s.savefile(*s.list1,"student.txt");
  //  cout<<*s.list;
}
