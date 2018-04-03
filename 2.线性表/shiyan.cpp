#include "SeqList.h"
#include <cassert>
void testSeqList()
{
  /*试验内容：*/
  /*1.基于查找(从前向后次序)的删除和替换操作*/
  //void removeAll(T key);                                 //删除所有关键字为key的元素;要求元素一次移动到位
  int a[10]={1,2,3,2,4,2,5,6,2,2};
  SeqList<int> list(a,10);
  list.removeAll(2);
  assert(list.count()==5);
  cout<<list;
  // void replaceFirst(T key,T x);                        //将首次出现的关键字为key的元素替换为x
  int a1[10]={3,1,2,8,4,2,5,7,7,7};
  SeqList<int> list1(a1,10);
  list1.replaceFirst(2,3);
  cout<<list1;
  assert(list1.searchLast(3,0)==2);
  // void replaceAll(T key,T x);                           //将所有关键字为key的元素替换为x
  list1.replaceAll(7,8);
  assert(list1.searchLast(8,0)==9);
  /*2.查找(从后向前次序)及删除和替换操作*/
  //int searchLast(T key,int start);                     //从start开始顺序查找最后出现的关键字为key的元素
  assert(list1.searchLast(5,0)==6);
  // void removeLast(T key);                              //删除最后出现关键字为key的元素
  cout<<list1;
  list1.removeLast(8);
  assert(list1.count()==9);
  cout<<list1;
  //void replaceLast(T key,T x);                         //将最后出现的关键字为key的元素替换为x
  list1.replaceLast(8,6);
  assert(list1.searchLast(6,0)==8);
  /*3.SeqList类增加以下对子表进行操作的成员函数，要求元素一次移动到位 */
  //  SeqList<T> sub(int i,int n);                         //返回从第i个结点开始，长度为n的子表
  cout<<list1;
  SeqList<int> aa(10);
  aa = list1.sub(1,3);
  assert(aa.searchLast(3,0)==1);
  // bool contain(SeqList<T> &list);                   //判断*this单链表是否包含list所有结点
  assert(list1.contain(aa));
  //  void insert(int i,SeqList<T> &list);               //复制list所有结点插入到*this第i个结点前
  cout<<list1;
  list1.insert(0,aa);
  cout<<list1;
  assert(list1.search(3,0)==1);
  //void append(SeqList<T> &list);                   //将list中所有结点复制添加到*this最后
  list1.append(list);
  assert(list1.search(5)==9);
  // SeqList<T> operator+(SeqList<T> &list);    //返回*this与list合并连接后的单链表
  // void remove(int i,int n);                               //删除从第i个结点开始，长度为n的子表
  list1.remove(6,5);
  assert(list1.searchLast(8,0)==5);
  // SeqList<T> operator*(SeqList<T> &list);     //返回*this与list的所有共同元素，交集
  SeqList<int> bb(10);
  list1*list;
  cout<<list1;
  //void operator-=(SeqList<T> &list);              //删除那些也包含在list中的元素，差集
  //list -= list1;
  //  cout<<list;
  //SeqList<T> operator-(SeqList<T> &list);     //返回*this与list的差集
  // list-list1;
  //  cout<<list;
  // void retainAll(SeqList<T> &list);                  //仅保留那些也包含在list中的元素
  //  list.retainAll(list1);
  //  cout<<list;
  
  //SeqList<T>* search(SeqList<T> &list);          //判断*this是否包含与list匹配的子表
  //SeqList<int> *temp = list.search(list1);
  //  cout<<"*temp="<<*temp;
  //void removeAll(SeqList<T> list);                 //删除*this中所有与list匹配的子表
  list.removeAll(list1);
  cout<<list;
  // void replaceAll(SeqList<T> listkey,SeqList<T> listx);//将所有与listkey匹配子表替换为listx
  cout<<"==============="<<endl;
  cout<<"list="<<list;
  cout<<"list1="<<list1;
  int abc[]={4,5};
  SeqList<int> list2(abc,2);
  list.replaceAll(list2,list1);
  cout<<list;
  //  void random();    
  // list.random();
  // cout<<list;
}
int
main()
{
  testSeqList();
  exit(0);
}
/*
  void r()
  {
  // int min,max;  
  //定义上下边界  
  default_random_engine e;  
  //创建引擎  
  uniform_int_distribution<unsigned> u(0,10);  
  //创建取值范围  
  int randNum=u(e);  
  for(int i = 0; i < 100; i++)
  {
  int rnum = u(e);
  cout<<rnum<<",";
  }
  
  //获取伪随机数  
  }
*/
