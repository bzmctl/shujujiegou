#include <iostream>
#include <stdexcept>
#include "DoubleNode.h"                 //双链表结点类

using namespace std;
template <class T> class CirDoublyList;
template <class T> ostream& operator<<(ostream &out,CirDoublyList<T> &list);

template <class T>
class CirDoublyList                               //循环双链表类
{
 public:
  DoubleNode<T> *head;                     //头指针
  CirDoublyList();                                  //构建空的循环双链表
  CirDoublyList(T values[],int n);           //由values数组提供元素构建循环双链表
  ~CirDoublyList();                               //析构函数

  bool empty();                                    //判断循环双链表是否为空
  int count();                                       //返回循环双链表结点个数
  T& get(int i);                                     //返回第i(i>=0)个元素
  virtual void set(int i,T x);    
  //设置第i(i>=0)个元素为x，虚函数
  friend ostream& operator<<<>(ostream&,CirDoublyList<T>&);//输出循环双链表
  void printPrevious();                         //输出循环双链表，从后向前，沿着前驱链
  DoubleNode<T>* insert(int i,T x);   //插入元素x作为循环链表的第i(i>=0)个结点
  virtual DoubleNode<T>* insert(T x);//在循环链表尾部插入x元素结点，虚函数
  T remove(int i);                                //删除第i(i>=0)个元素结点
  void removeAll();                             //清空循环双链表
  DoubleNode<T>* search(T key);     //查找关键字为key元素，返回结点，T需重载==
  virtual void operator+=(CirDoublyList<T>&list);//将循环链表list连接到当前循环链表this之后
};
template <class T>
CirDoublyList<T>::CirDoublyList()
{
  this->head = new DoubleNode<T>();
  this->head->prev = this->head->next = this->head;
}
template <class T>
CirDoublyList<T>::CirDoublyList(T values[],int n)
{
  //CirDoublyList();
  this->head = new DoubleNode<T>();
  DoubleNode<T> *q = this->head;
  for(int i =0; i < n; i++)
    {
      q->next = new DoubleNode<T>(values[i],q,q->next);
      q = q->next;
    }
  this->head->prev = q;
}
template <class T>
CirDoublyList<T>::~CirDoublyList()
{
  removeAll();
  delete this->head;
}
template <class T>
bool CirDoublyList<T>::empty()
{
  return this->head->next == this->head;
}
template <class T>
int CirDoublyList<T>::count()
{
  DoubleNode<T> *tmp = this->head;
  int count;
  while(tmp->next != this ->head)
    {
      tmp = tmp->next;
      count++;
    }
  return count;
}
template <class T>
T& CirDoublyList<T>::get(int i)
{
  DoubleNode<T> *p = this->head;
  for(int j =0; j < i && p->next != this->head; j++)
    p = p->next;
  if(i>=0 && p->next != this->head)
    return p->next->data;
  throw out_of_range("参数i超出查找范围！");
}
template <class T>
void CirDoublyList<T>::set(int i,T x)
{
  DoubleNode<T> *p = this->head->next;
  int j = 0;
  while(p != this->head && j < i)
    {
      p = p->next;
    }
  p->data = x;
}
template <class T>
ostream& operator<<(ostream&out,CirDoublyList<T>&list)
{
  out<<"(";
  DoubleNode<T> *next = list.head->next;
  while(next != list.head)
    {
      out<<next->data;
      if(next->next != NULL)
	out<<",";
      next = next->next;
    }
  out<<")\n";
}
template <class T>
void CirDoublyList<T>::printPrevious()
{
  DoubleNode<T> * prev = this->head->prev;
  while(prev != this->head)
    {
      cout<<prev->data;
      prev = prev->prev;
    }
  cout<<"\n";
}
template <class T>
DoubleNode<T>* CirDoublyList<T>::insert(int i,T x)
{
  DoubleNode<T> *front = this->head;
  for(int j = 0; front->next != this->head && j < i; j++)
    front = front->next;
  DoubleNode<T> *q = new DoubleNode<T>(x,front,front->next);
  front->next->prev = q;
  front->next = q;
  return q;
}
template <class T>
DoubleNode<T>* CirDoublyList<T>::insert(T x)
{
  DoubleNode<T> *q = new DoubleNode<T>(x,this->head->prev,this->head);
  this->head->prev->next = q;
  this->head->prev = q;
  return q;
}
template <class T>
T CirDoublyList<T>::remove(int i)
{
  DoubleNode<T> *q = this->head->next;
  for(int j =0; j < i && q != this->head; j++)
    q = q->next;
  if(i >= 0 && q !=this->head)
    {
      T old = q->data;
      q->prev->next = q->next;
      q->next->prev = q->prev;
      delete q;
      return old;
    }
  throw out_of_range("参数i指定元素序号超出范围!");
}
template <class T>
void CirDoublyList<T>::removeAll()
{
  DoubleNode<T> *p = this->head->next;
  while(p != this->head)
    {
      DoubleNode<T> *tmp = p;
      p = p->next;
      delete tmp;
    }
  this->head->prev = this->head->next = this->head;
}
template <class T>
DoubleNode<T>* CirDoublyList<T>::search(T key)
{
  DoubleNode<T> *search = this->head;
  while(search->next != this->head)
    {
      search = search->next;
      if(search->data == key)
	return search;
    }
  return NULL;
}
template <class T>
void CirDoublyList<T>::operator+=(CirDoublyList<T>&list)//将循环链表list连接到当前循环链表this之后
{
  this->head->prev->next = list.head->next;
  list.head->next->prev = this->head->prev;
  this->head->prev = list.head->prev;
  list.head->prev->next = this->head;
  list.head->prev = list.head->next = list.head;
}
