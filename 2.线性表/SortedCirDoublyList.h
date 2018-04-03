#include "CirDoublyList.h"
template <class T>
class SortedCirDoublyList:public CirDoublyList<T>
{
 public:
   SortedCirDoublyList(T values[],int n);
 
  DoubleNode<T>* insert(T x);
};
template <class T>
SortedCirDoublyList<T>::SortedCirDoublyList(T values[],int n)
{
  //此处自动执行CirDoublyList(),创建头结点
  for(int i = 0; i < n; i++)
    this->insert(values[i]);  //调用当前对象的insert按序插入
}
template <class T>
DoubleNode<T>* SortedCirDoublyList<T>::insert(T x)
{
  DoubleNode<T> *p = this->head->next;
  if(this->head->prev->data <= x)
    {
      DoubleNode<T> *q = new DoubleNode<T>(x,this->head->prev,this->head);
      this->head->prev->next = q;
      this->head->prev = q;
    }
  else
    {
      while(p != this->head && x >= p->data)
	p = p->next;
      DoubleNode<T> *q = new DoubleNode<T>(x,p->prev,p);
      p->prev->next = q;
      p->prev = q;
    }
}
