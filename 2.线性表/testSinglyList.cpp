#include <iostream>
//#include "SinglyList.h"
#include "SortedSinglyList.h"
#include "Computer.h"
#include "CircularSinglyLinkedList.h"
using namespace std;
int
main()
{
  //////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////SinglyList.h测试///////////////////////////////////////
  //////////////////////////////////////////////////////////////////////////////////////////////
/*
  Computer c(1,16.0),c1(4,4.0),c2(8,8.0);
  Computer values[]={c,c1,c2};
  SinglyList<Computer> list(values,3);
  cout<<list;
  
  SinglyList<char> list1("abcde",5),list2("fgh",3);
  cout<<list1;
  cout<<list2;
  list1+=list2;
  cout<<list1;
  cout<<list2;
 */
  //////////////////////////////////删除测试///////////////////////////////////////////////
  /*
  list.removeFirst(c1);
  cout<<"删除c1测试：\n";
  cout<<list; 
*/
 ////////////////////////////////在单链表最后插入测试//////////////////////////////////////////
/*
  list.insert(c2);
  cout<<"单链表最后插入c2\n";
  cout<<list;
*/
  ////////////////////////////////设置第i个结点数据为c1///////////////////////////////////////
  /*
  cout<<"设置第3个结点数据为c\n";
  list.set(2,c);
  cout<<list;
  */
  ///////////////////////////////链接两个单链表//////////////////////////////////////////////
   /*
  Computer c3(8,32.5),values1[]={c3};
  SinglyList<Computer> list1(values1,1);
  list+=list1;
  cout<<list;
  cout<<list1;
  */
  /////////////////////////按结点数据查找元素，Node<T>* search(T key)////////////////////////
  /*
  cout<<"查找c\n";
  Node<Computer> *result = list.search(c);
  cout<<result->data<<endl;
  */
  /////////////////删除单链表的所有元素，并释放空间removeAll()//////////////////////////////////
   /*  
  cout<<"删除单链表的所有元素:\n";
  list.removeAll();
  cout<<list;
   */
  ///////////////返回单链表结点个数，count()///////////////////////////////////////////////////
  /*
    cout<<"返回链表结点个数:\n";
    cout<<list.count();
    */
  ///////////////////删除第i个结点，并返回被删除结点的元素，T remove(int i)////////////////
  /*
    cout<<"删除第i个结点，并返回被删除的元素\n";
    Computer result = list.remove(1);
    cout<<list;
    cout<<result<<endl;
     */
  ////////////////插入元素，并返回插入结点的地址，Node<T>* insert(int i,T x)/////////////
   /*
    cout<<"插入元素，并返回插入结点的地址\n";
    Node<Computer> *addr = list.insert(2,c2);
    cout<<list;
    cout<<addr<<":"<<addr->data<<endl;
    */
  /////////////////用于返回第i个元素，T& get(int i)/////////////////////////////////////
   /*
    cout<<"用于返回第2个元素\n";
    Computer result = list.get(1);
    cout<<result<<endl;
    */
  ///////////////////////判断链表是否为空bool empty()/////////////////////////////////////
  /*
    cout<<"判断链表是否为空\n";
    bool flag = list.empty();
    cout<<flag<<endl;
    */
  ////////////////////////重载单链表==运算符/////////////////////////////////////////////
   /* 
 Computer c3(1,16.0),c4(4,4.0),c5(8,32);
  Computer values3[]={c3,c4,c5};
  SinglyList<Computer> list3(values3,3);
  bool flag = list != list3;
   */
  /////////////////////////////单链表的拷贝构造函数，必须重载单链表的=运算符///////////////////
  /*
  SinglyList<Computer> list3(list);
  bool flag = list==list3;
  */
  /////////////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////SortedSinglyList.h测试/////////////////////////////////
  /////////////////////////////////////////////////////////////////////////////////////

  ////////////////////////////////SortedSinglyList(T values[],int n,bool asc)//////////
  Computer c1(1,8),c2(1,16),c3(2,8),c[3]={Computer(1,4),Computer(1,8),Computer(2,16)};
  //  SortedSinglyList<Computer> list(c,3,false);
  //SinglyList<Computer> *list = new SortedSinglyList<Computer>(c,3,true);
  //cout<<list;
  SinglyList<Computer> list(c,3);
  cout<<list;
  SortedSinglyList<Computer> s_list(list,false);
  cout<<s_list;
  /*
  CircularSinglyLinkedList<Computer> cs_list(list,true);
  //设置cs_list为循环单链表
  cs_list.ccsll();
  cs_list.print();
  */
  /*
  list->print();
  list->removeFirst(c1);
  list->print();
  list->insert(c2);
  list->print();
  list->insertUnrepeatable(c3);
  list->print();
  list->insertUnrepeatable(c2);
  list->print();
  */
  return 0;
}
