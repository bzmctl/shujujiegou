#include <iostream>
#include <stdexcept>
#include "Computer.h"
#include "SeqList.h"
#include "SortedSinglyList.h"
#include "CircularSinglyLinkedList.h"
//#include "CirDoublyList.h"
#include "SortedCirDoublyList.h"
using namespace std;


/*
void testSeqList()
{
  
   Computer
      c[3] = {Computer(1,2),Computer(1,4),Computer(2,8)},
      c1[2] = {Computer(2,12),Computer(2,16)},
      c2(4,32),
      c3(2,16);
  
    //SeqList<Computer> list(c,3),list1(c1,2),list2(10,c2);

  //  cout<<list;
  //  list+list1;
  //  cout<<list;
  //  bool flag = list != list1;
  //  list.insert(c2);
  //  list.printPrevious();
  //  cout<<list2;

    //SeqList(int length=32);                                 //构造空表，length指定(默认)容量
      SeqList<Computer> list1(100);
    cout<<"SeqList list1(int length=32)="<<list1<<endl;
    //  SeqList(int length,T x);                                  //构造顺序表，length个元素值为x
    SeqList<Computer> list2(32,c2);
    cout<<"SeqList list2(int length,T x)="<<list2<<endl;
    //  SeqList(T values[],int n);                               //构造顺序表，由values数组提供元素
    SeqList<Computer> list3(c,3),list4(c1,2);
    cout<<"SeqList(T values[],int n)="<<list3<<endl;
    //  ~SeqList();                                                   //析构函数

    //  bool empty();                                                //顺序表是否为空
    bool flag = list1.empty();
    bool flag1 = list2.empty();
    cout<<"bool flag = list1.empty()="<<flag<<endl;
    cout<<"bool flag1 = list2.empty()="<<flag1<<endl;
    //  int count();                                                   //顺序表元素个数
    cout<<"list2.count()="<<list2.count()<<endl;
    //  T& operator[](int i);                                       //重载下标运算符[]
    try
      {
	cout<<"T& operator[](int i)="<<endl;
	cout<<"list3[0]="<<list3[0]<<endl;
	cout<<"list3[3]="<<list3[3]<<endl;
      }
    catch (const out_of_range& oor)
      {
	cerr << "Out of Range error: " << oor.what() << '\n';
      }
    //  friend ostream& operator<<<>(ostream&,SeqList<T>&);  //输出顺序表所有元素
    //  void printPrevious();                                      //反序输出，从后到前
    cout<<"void printPrevious()="<<endl;
    list3.printPrevious();
    // void insert(int i,T x);                                      //插入x作为第i个元素
    cout<<"void insert(int i,T x)"<<endl;
    list3.insert(2,c2);
    cout<<list3;
    // virtual void insert(T x);                                  //在顺序表最后插入x;虚函数
    cout<<"virtual void insert(T x)="<<endl;
    list3.insert(c2);
    cout<<list3;
    //T remove(int i);                                             //删除第i个元素，返回被删除元素
    cout<<"T remove(int i)="<<endl;
    list3.remove(2);
    cout<<list3;
    // void removeAll();                                           //删除顺序表所有元素
    cout<<"void removeAll()="<<endl;
    list3.removeAll();
    cout<<list3;
    // virtual int search(T key,int start=0);              //从start开始查找key元素，返回元素序号
    cout<<"virtual int search(T key,int start)="<<endl;
    cout<<list4.search(c3,0)<<endl;
    // virtual void removeFirst(T key);                     //删除首次出现关键字为key的元素;虚函数
    cout<<list4;
    cout<<"virtual void removeFirst(T key)="<<endl;
    list4.removeFirst(c3);
    cout<<list4;
    // SeqList(SeqList<T> &list);                            //拷贝构造函数
    cout<<"SeqList(SeqList<T> &list)="<<endl;
    SeqList<Computer> list5(list4);
    cout<<list5;
    // SeqList<T>& operator=(SeqList<T> &list);  //重载=赋值运算符，深拷贝
    cout<<"SeqList<T>& operator=(SeqList<T> &list)="<<endl;
    SeqList<Computer> list6(list1);
    list6 = list5;
    cout<<list6;
    // bool operator==(SeqList<T>&);                   //比较两个顺序表对象的值是否相等
    cout<<"bool operator==(SeqList<T>&)="<<endl;
    bool flag3 = list5==list6;
    cout<<"list5==list6="<<flag3<<endl;
    // bool operator!=(SeqList<T>&);                     //比较两个顺序表是否不等 
    cout<<"bool operator!=(SeqList<T>&)="<<endl;
    cout<<"list5!=list6="<<(list5 != list6)<<endl;
    // void operator+=(SeqList<T>&);                   //在*this当前顺序表之后合并连接list
    cout<<"void operator+=(SeqList<T>&)="<<endl;
    cout<<"list5+=list6="<<endl;
    list5+=list6;
    cout<<list5;
    // SeqList<T> operator+(SeqList<T>&);          //返回*this与list合并连接的对象
    cout<<"SeqList<T> operator+(SeqList<T>&)="<<endl;
    SeqList<Computer> list7(10);
    list5+list6;
    list7=list5;
    cout<<list7;
}
*/


//void testSinglyList()
//{
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
  /*
  Computer c1(1,8),c2(1,16),c3(2,8),c[3]={Computer(1,4),Computer(1,8),Computer(2,16)};
  //  SortedSinglyList<Computer> list(c,3,false);
  //SinglyList<Computer> *list = new SortedSinglyList<Computer>(c,3,true);
  //cout<<list;
  SinglyList<Computer> list(c,3);
  cout<<list;
  SortedSinglyList<Computer> s_list(list,false);
  cout<<s_list;
  */
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
//}

/*
void testCirDoublyList()
{
  Computer c[3] = {Computer(1,2),Computer(1,4),Computer(2,8)},c1[2] = {Computer(2,12),Computer(2,16)},c2(4,32),c3(2,16);
  CirDoublyList<Computer> list(c,3),list1(c1,2);
  list+=list1;
  cout<<list;
  list.printPrevious();
  //bool empty();                                    //判断循环双链表是否为空
 bool flag = list.empty();
 cout<<flag<<endl;
 // int count();                                       //返回循环双链表结点个数
 cout<<list.count()<<endl;
 //  T& get(int i);                                     //返回第i(i>=0)个元素
 cout<<list.get(0)<<endl;
 //  virtual void set(int i,T x);    
 list.set(0,c2);
 cout<<list;
  //设置第i(i>=0)个元素为x，虚函数
 //  friend ostream& operator<<<>(ostream&,CirDoublyList<T>&);//输出循环双链表
 // void printPrevious();                         //输出循环双链表，从后向前，沿着前驱链
 // DoubleNode<T>* insert(int i,T x);   //插入元素x作为循环链表的第i(i>=0)个结点
 list.insert(2,c3);
 cout<<list;
 // virtual DoubleNode<T>* insert(T x);//在循环链表尾部插入x元素结点，虚函数
 list.insert(c3);
 cout<<list;
 //  T remove(int i);                                //删除第i(i>=0)个元素结点
 list.remove(1);
 cout<<list;
 //  void removeAll();                             //清空循环双链表
 //  DoubleNode<T>* search(T key);     //查找关键字为key元素，返回结点，T需重载==
 cout<<list.search(c2)->data<<endl;
 // virtual void operator+=(CirDoublyList<T>&list);//将循环链表list连接到当前循环链表this之后
 list.removeAll();
 cout<<list;

}
*/
/*
void testSortedCirDoublyList()
{
  Computer c[3] = {Computer(1,8),Computer(1,4),Computer(1,16)};
  SortedCirDoublyList<Computer> list(c,3);
  }*/
int
main()
{
  //testSeqList();
  //testSinglyList();
  //testCirDoublyList();
  //testSortedCirDoublyList();
  return 0;
}
