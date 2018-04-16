#include "SinglyList.h"  //单链表类
#include <stdexcept>
//using namespace std;
template <class T> class SortedSinglyList;
template <class T> ostream& operator<<(ostream &out,SortedSinglyList<T>* list);

//排序单链表类，T必须重载==,！=,>,>=,<,<=关系运算符
template <class T>
class SortedSinglyList:public SinglyList<T>{
  bool asc;    //排序次序约定，asc的取值：true升序，false降序
 public:
  SortedSinglyList(bool asc=true);//构造空排序单链表，asc指定升序或降序
  SortedSinglyList(T values[],int n,bool asc=true);  //由values数组元素构造排序单链表
  /*2-5*/
  SortedSinglyList(SinglyList<T> &list,bool asc=true);  //由单链表构造排序单链表

  void set(int i,T x);  //不支持该操作，抛出异常；覆盖
  Node<T>* insert(T x);  //插入，根据x大小确定插入位置；覆盖
  Node<T>* insertUnrepeatable(T x);  //插入不重复元素，返回插入结点地址；覆盖
  Node<T>* search(T key);  //顺序查找首次出现的关键字为key元素；覆盖
  void removeFirst(T key);  //删除首次出现的关键字为key元素的结点；覆盖
  friend ostream& operator<<<>(ostream &out,SortedSinglyList<T>* list);
  void print();
};

//构造空的排序单链表，asc指定升序，降序，此处执行SinglyList<T>(),创建头结点
template <class T>
SortedSinglyList<T>::SortedSinglyList(bool asc)
{
  this->asc = asc;
}

//由values数组元素构造排序单链表，n指定values数组长度，asc指定升序，降序
template <class T>
SortedSinglyList<T>::SortedSinglyList(T values[],int n,bool asc)
{
  this->asc = asc;
  for(int i = 0; i < n; i++)
    this->insert(values[i]);
}

//由单链表构造有序单链表
template <class T>
SortedSinglyList<T>::SortedSinglyList(SinglyList<T> &list, bool asc)
{
  //
  this->asc = asc;
  for(Node<T> *p = list.head->next; p != NULL; p = p->next)
    this->insert(p->data);
}

//不支持该操作，抛出C++ STL逻辑错误异常；覆盖
template <class T>
void SortedSinglyList<T>::set(int i,T x)
{
  throw logic_error("不支持set(int i,T x)的操作！");
}

//插入x结点，根据x元素的大小确定插入位置，返回插入结点地址。T必须重载>=,<=运算符
//覆盖基类insert(int i,T x)和insert(T x)成员函数；运行时覆盖基类insert(T x)虚函数
//采用顺序查找算法确定操作位置，查找成功插入相同元素。
template <class T>
Node<T>* SortedSinglyList<T>::insert(T x)
{
  //front是p的前驱结点
  Node<T>* front = this->head, *p = this->head->next;  
  //循环找出x的插入位置，插入x在等值结点之后。升序比较>=，降序比较<=
  while(p != NULL && (asc ? x >= p->data : x <= p->data))
    {
      front = p;
      p = p->next;
    }
  //插入在p结点之前，front结点之后
  Node<T> *q = new Node<T>(x,p);
  front->next = q;
    //返回插入结点地址
  return q;
}

//插入不重复元素
template <class T>
Node<T>* SortedSinglyList<T>::insertUnrepeatable(T x)
{
  //front是p的前驱结点
  Node<T>* front = this->head, *p = this->head->next;  
  //循环找出x的插入位置，插入x在等值结点之后。升序比较>=，降序比较<=
  while(p != NULL && x != p->data && (asc ? x >= p->data : x <= p->data))
    {
      front = p;
      p = p->next;
    }
  if(p->data != x)
    {
      //插入在p结点之前，front结点之后
      Node<T> *q = new Node<T>(x,p);
      front->next = q;
      return q;
    }
  else
    {
      return NULL;
    }
 }

//删除首次出现的关键字为key元素的结点。覆盖基类removeFirst(T key)成员函数。
//采用顺序查找算法确定操作位置，查找成功删除。T必须重载==,>,<运算符
template <class T>
void SortedSinglyList<T>::removeFirst(T key)
{
  //front是p的前驱结点
  Node<T>* front = this->head, *p = this->head->next;
  while(p != NULL &&(asc ? key > p->data : key < p->data))
    {
      front = p;
      p = p->next;
    }
  if(p != NULL && key == p->data)
    {
      front->next = p->next;
      delete p;
    }
}

//重写的<<操作符，用于输出单链表元素到控制台
template <class T>
ostream& operator<<(ostream &out,SortedSinglyList<T>* list)
{
  out<<"(";
  for(Node<T> *next=list->head->next; next != NULL; next = next->next)
    {
      out<<next->data;
      if(next->next != NULL)
	out<<",";
    }
  out<<")\n";
  return out;
}

