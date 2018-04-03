// #include "SeqList.h"
// int main()
// {
//   int a1[] = {5,3,2,4,1}, a2[] = {4,5,6,7,3,2,2};
  
//   SeqList<int> list5,list1(a1,5),list2(a2,6),list3(10);
//   delete &(list1*list2);
//   return 0;
// }
//#include "SortedSeq List.h"
// int
// main()
// {
//   int a[10000],b[10000],c[10000];
//   for(int i = 0; i < 10000; i++)
//     a[i]=i,b[i]=i,c[i]=i;
//   SeqList<int> list(a,10000);
//   SortedSeqList<int> list1(b,10000),list2(c,10000);
//   list1+list2;
//   cout<<list1;
//   return 0;
// }
// // #include <iostream>
// using namespace std;
// #include "mysort.h"
// int main()
// {
//   int arr[] = {2,1,4,3,6,5,9,7,8,0};
//   mysort(arr,0,10);
//   for(int i = 0 ; i < 10; i++)
//     cout<<arr[i]<<",";
//   cout<<endl;
//   return 0;
// }
/*SinglyList*/
#include "Computer.h"
#include "SinglyList.h"
int
main()
{
  Computer c[]={Computer(1,2),Computer(2,16),Computer(1,6),Computer(1,4),Computer(1,8),Computer(2,8),Computer(1,2)},
    c2(1,2),c1(1,32),c4(1,8),
       c3[]={Computer(1,2),Computer(1,4),Computer(1,8),Computer(2,8)},
       c5[]={Computer(2,8),Computer(2,4),Computer(1,8)};
  SinglyList<Computer> list(c,7);
  // /*实验2-3*/
  // //1.实现所有未实现的成员函数
  // //2.实现基于查找的替换和删除操作
  // void removeAll(T key);                                 //删除所有关键字为key的元素;要求元素一次移动到位
  cout<<list;
  list.removeAll(c2);
  cout<<list;
  // void replaceFirst(T key,T x);                        //将首次出现的关键字为key的元素替换为x
  SinglyList<Computer> list1(c,7);
  cout<<list1;
  list1.replaceFirst(c2,c1);
  cout<<list1;
  // void replaceAll(T key,T x);                           //将所有关键字为key的元素替换为x
  SinglyList<Computer> list2(c,7);
  cout<<list2;
  list2.replaceAll(c2,c1);
  cout<<list2;
  // //3.SingList类增加下列成员函数，按迭代方式遍历单链表
  // Node<T>* first();                                       //返回单链表第0个元素结点(非头结点)
  SinglyList<Computer> list3(c3,4);
  cout<<list3;
  Node<Computer> *co1 = list3.first();//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////bug从此处开始！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
  cout<<co1->data;
  // Node<T>* next(Node<T> *p);                   //返回p的后继结点
  SinglyList<Computer> list4(c3,4);
  Node<Computer> *p = new Node<Computer>(c4);
  p = list4.next(p);
  cout<<p->data;
  // Node<T>* previous(Node<T> *p);             //返回p的前驱结点
  Node<Computer> *p1 = new Node<Computer>(c4);
  p1 = list4.previous(p1);
  cout<<p1->data;
  // Node<T>* last();                                        //返回单链表最后一个结点
  SinglyList<Computer> list6(c3,4);
  cout<<list6;
  Node<Computer> *co2 = list6.last();
  cout<<co2->data;
  // //4.SingList类增加以下操作
  // bool isSorted(bool asc=true);                   //判断是否已排序，asc指定升序或降序
  SinglyList<Computer> list7(c5,3);
  bool bool1=!(list2.isSorted()),bool2=list6.isSorted(),bool3=list7.isSorted(false);
  cout<<bool1<<","<<bool2<<","<<bool3<<endl;
  // T max(SinglyList<T> &list);                      //返回list单链表最大值，T必须重载>
  Computer c6=list7.max(list7);
  cout<<c6;
  // void reverse(SinglyList<T> &list);            //将单链表逆转
  list7.reverse(list7);
  cout<<list7;
  return 0;
}
