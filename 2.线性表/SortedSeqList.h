#include "SeqList.h"  //顺序表类
#include "mysort.h"
#include <stdexcept>
using namespace std;

template <class T>
class SortedSeqList:public SeqList<T>      //排序顺序表类(升序)，公有继承顺序表类
{
 public:
  SortedSeqList();                                   //构造排序顺序表，默认执行SeqList<T>()
  SortedSeqList(T values[],int n);               //构造排序顺序表，由values数组提供元素
  SortedSeqList(SeqList<T> &list);            //重载拷贝构造函数，由顺序表构造排序顺序表
  int search(T key,int start=0);                  //从start开始查找关键字为key元素；覆盖
  void insert(T x);                                      //插入，根据元素x大小确定插入位置；覆盖
  void removeFirst(T key);                         //删除首次出现关键字为key元素；覆盖
  void insertUnrepeatable(T x);                  //插入不重复元素

  /*实验2-2 排序顺序表增加以下成员函数：*/
  SortedSeqList<T> operator+(SeqList<T> &list);  //返回将list顺序表插入到*this的排序顺序表
  SortedSeqList<T> operator+(SortedSeqList<T> &list);  //返回*this与list合并后的排序顺序表
};
template <class T>
SortedSeqList<T>::SortedSeqList(){}
template <class T>
SortedSeqList<T>::SortedSeqList(T values[],int n):SeqList<T>(n*2)                  //构造排序顺序表，由values数组提供元素
{
  for(int i = 0; i < n; i++)
    this->insert(values[i]);
}
template <class T>
SortedSeqList<T>::SortedSeqList(SeqList<T> &list)               //重载拷贝构造函数，由顺序表构造排序顺序表
{
  for(int i = 0; i < list.count(); i++)
    this->insert(list[i]);  //根据实际调用对象，执行父类或子类insert方法
}
template <class T>
int SortedSeqList<T>::search(T key,int start)                    //从start开始查找关键字为key元素；覆盖
{
  for(int i = start; i < this->n && key >= this->element[i]; i++)
    if(key == this->element[i])
      return i;
  return -1;
}
template <class T>
void SortedSeqList<T>::insert(T x)                                        //插入，根据元素x大小确定插入位置；覆盖
{
  int i = 0;
  for(; i < this->n && x > this->element[i];i++)
    ;
  SeqList<T>::insert(i,x);
}
template <class T>
void SortedSeqList<T>::removeFirst(T key)                          //删除首次出现关键字为key元素；覆盖
{
  this->remove(this->search(key));
}
template <class T>
void SortedSeqList<T>::insertUnrepeatable(T x)                 //插入不重复元素
{
  int i = 0;
  while(i < this->n && this->element[i] <= x)
    i++;
  if(x != this->element[i])
    SeqList<T>::insert(i,x);
  else
    throw out_of_range("插入元素重复！");
}
template <class T>
SortedSeqList<T> SortedSeqList<T>::operator+(SeqList<T> &list)
{
  int n = this->n;
  this->append(list);
  mysort(this->element,n,this->n);
  return *this;
}
template <class T>
SortedSeqList<T> SortedSeqList<T>::operator+(SortedSeqList<T> &list)
{
  T *tmp = this->element;
  if(this->length <= this->n + list.n)  //当*this空间太小，则重新分配*this空间并复制旧空间内容到新的空间
    {
      this->length += list.length;
      this->element = new T[this->length];
      for(int i = 0; i < this->n; i++)
	this->element[i] = tmp[i];
    }
  //拷贝list排序顺序表内容追加到*this排序顺序表中
  for(int i = 0; i < list.n; i++)
    this->element[i+this->n] = list.element[i];
  int total = this->n + list.n;
  //插入排序，由于*this前面的是排好序的，所以插入排序可以从指定位置开始排序
  mysort(this->element,this->n,total);
  //设置*this新的元素个数
  this->n = total;
  //释放旧的空间
  if(tmp != this->element)
    delete []tmp;
  return *this;
}
