#include "SortedSeqList.h"
#include "Computer.h"
void test()
{
  Computer c[3] = {Computer(1,2),Computer(1,4),Computer(2,8)},c1(2,8),c2(1,16);
  //  SortedSeqList(){}                                   //构造排序顺序表，默认执行SeqList<T>()
  cout<<" SortedSeqList()="<<endl;
  SortedSeqList<Computer> s;
  cout<<s;
  //  SortedSeqList(T values[],int n);               //构造排序顺序表，由values数组提供元素
  cout<<"SortedSeqList(T values[],int n)="<<endl;
  SortedSeqList<Computer> list(c,3);
  cout<<list;
  //  SortedSeqList(SeqList<T> &list);            //重载拷贝构造函数，由顺序表构造排序顺序表
  cout<<"SortedSeqList(SeqList<T> &list)="<<endl;
  SeqList<Computer> list1(c,3);
  SortedSeqList<Computer> list2(list1);
  cout<<list2;
  //  int search(T key,int start=0);                  //从start开始查找关键字为key元素；覆盖
  cout<<"int search(T key,int start=0)="<<endl;
  int i=list2.search(c1);
  cout<<i<<endl;
  //  void insert(T x);                                      //插入，根据元素x大小确定插入位置；覆盖
  cout<<"void insert(T x)="<<endl;
  list2.insert(c1);
  cout<<list2;
  //  void removeFirst(T key);                         //删除首次出现关键字为key元素；覆盖
  cout<<"void removeFirst(T key)="<<endl;
  list2.removeFirst(c1);
  cout<<list2;
  //  void insertUnrepeatable(T x);                  //插入不重复元素
  cout<<"void insertUnrepeatable(T x)="<<endl;
  list2.insertUnrepeatable(c2);
  cout<<list2;
}
void test1()
{
  //滞后联编与虚函数
  //当基类成员函数没有声明为虚函数时，派生类调用与基类同名成员函数时，执行的是基类的成员函数
  //当基类成员函数声明为虚函数时，执行的则是派生类的成员函数
  int a[3]={3,2,1},b[2]={5,4};
  SeqList<int> list(a,3);
  SortedSeqList<int> list1(b,2);
  list1+=list;
  cout<<"list1+=list="<<list1;
}
int main()
{
  test();
  test1();
  return 0;
}
