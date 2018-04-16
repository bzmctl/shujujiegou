#include "Node.h"        //单链表节点类
#include "mysort.h"                     
//#include <stdio.h>                             
#include <iostream>
#include <stdexcept>
//#include <memory>  //shared_ptr头文件
#include <algorithm>    // std::sort
#include <stdlib.h> //rand
#include <time.h> //time
#define RANDOM(x) (rand() % x)//得到一个随机数对x取余 即得到 0 至 x - 1的随机数,rand()函数本身是返回0到RAND_MAX, RAND_MAX = 32767  
using namespace std;
//template <class T> class SinglyList;
//template <class T> ostream& operator<<(ostream&,SinglyList<T>&);
template <class T>
class SinglyList{                                  //带头结点的单链表类，T指定元素类型，T必须重载==关系运算符
public:
  Node<T> *head;                               //头指针，指向单链表的头结点
  
  SinglyList();                                       //构造空单链表
  SinglyList(T values[],int n);                //构造单链表，由values数组提供元素
  ~SinglyList();                                    //析构函数
  
  bool empty();                                   //判断单链表是否为空
  int count();                                      //返回单链表长度
  T& get(int i);                                    //返回第i(i>=0)个元素的引用
  virtual void set(int i,T x);                  //设置第i（i>=0）个元素的值为x
  template <typename K> friend ostream& operator<<(ostream&,SinglyList<K>&);    //输出单链表所有元素
  Node<T>* insert(int i,T x);              //插入x作为第i个结点，返回插入结点的地址
  virtual Node<T>* insert(T x);          //在单链表最后插入x，虚函数
  T remove(int i);                               //删除第i(i>=0)个结点，返回被删除元素
  void removeAll();                            //清空单链表
  Node<T>* search(T key);               //顺序查找首先出现关键字为key的元素，返回结点地址；若未找到返回NULL。T必须重载==运算，约定比较两个元素(==)的规则
  virtual Node<T>* insertUnrepeatable(T x);    //尾插入不重复元素,返回插入结点地址(virtual的作用:当子类有新的不同实现时，调用子类实现的方法)
  virtual void removeFirst(T key);      //删除首次出现的元素值为key的结点

  bool operator==(SinglyList<T> &list);        //比较两条单链表是否相等
  bool operator!=(SinglyList<T> &list);         //比较两条单链表是否不相等
  SinglyList(SinglyList<T> &list);                  //拷贝构造函数，深拷贝
  //注意：
  //由于函数形参是引用，所以当函数实参为对象时，会出现没有匹配的=赋值运算符
  SinglyList<T>& operator=(SinglyList<T> &list);  //重载=赋值运算符，深拷贝
  
  virtual void operator+=(SinglyList<T> &list);//将list链接在当前链表之后;虚函数

  /*实验2-3*/
  //1.实现所有未实现的成员函数
  //2.实现基于查找的替换和删除操作
  void removeAll(T key);                                 //删除所有关键字为key的元素;要求元素一次移动到位
  void replaceFirst(T key,T x);                        //将首次出现的关键字为key的元素替换为x
  void replaceAll(T key,T x);                           //将所有关键字为key的元素替换为x
  //3.SingList类增加下列成员函数，按迭代方式遍历单链表
  Node<T>* first();                                       //返回单链表第0个元素结点(非头结点)
  Node<T>* next(Node<T> *p);                   //返回p的后继结点
  Node<T>* previous(Node<T> *p);             //返回p的前驱结点
  Node<T>* last();                                        //返回单链表最后一个结点
  //4.SingList类增加以下操作
  bool isSorted(bool asc=true);                   //判断是否已排序，asc指定升序或降序
  T max(SinglyList<T> &list);                      //返回list单链表最大值，T必须重载>
  void reverse(SinglyList<T> &list);            //将单链表逆转
  //5.SinglyList类增加对子链表的操作，函数声明见实验题2-1(3)
  //SinglyList<T>* sub(int i,int n);                       //返回从第i个结点开始，长度为n的子表
  SinglyList<T>& sub(int i,int n);                       //返回从第i个结点开始，长度为n的子表
  // SinglyList<T> sub(int i,int n);                       //返回从第i个结点开始，长度为n的子表
  bool contain(SinglyList<T> &list);                   //判断*this单链表是否包含list所有结点
  void insert(int i,SinglyList<T> &list);               //复制list所有结点插入到*this第i个结点前
  void append(SinglyList<T> &list);                   //将list中所有结点复制添加到*this最后
  SinglyList<T> operator+(SinglyList<T> &list);    //返回*this与list合并连接后的单链表
  void remove(int i,int n);                               //删除从第i个结点开始，长度为n的子表
  SinglyList<T>& operator*(SinglyList<T> &list);     //返回*this与list的所有共同元素，交集
  void operator-=(SinglyList<T> &list);              //删除那些也包含在list中的元素，差集
  SinglyList<T> operator-(SinglyList<T> &list);     //返回*this与list的差集
  void retainAll(SinglyList<T> &list);                  //仅保留那些也包含在list中的元素
  SinglyList<T>* search(SinglyList<T> &list);          //判断*this是否包含与list匹配的子表
  void removeAll(SinglyList<T> list);                 //删除*this中所有与list匹配的子表
  void replaceAll(SinglyList<T> listkey,SinglyList<T> listx);//将所有与listkey匹配子表替换为listx
  void random();                                            //将单链表元素随即排列
  bool eq(T a, T b);  //测试函数
  /*2-4 整数单链表的计算*/
  double average(SinglyList<T> &list);//计算整数单链表的平均值
  double averageExceptMaxMin(SinglyList<T> &list);//去掉最高分和最低分求平均值
};

//无参构造函数，构造空链表
template <class T>
SinglyList<T>::SinglyList()          //构造空链表
{
  this->head = new Node<T>();        //创建头结点，data数据域未初始化
}

//带参构造方法，由values数组元素构造单链表
template <class T>
SinglyList<T>::SinglyList(T values[],int n)  //构造单链表，由values数组提供元素
{
  this->head = new Node<T>();       //创建头结点，构造空链表
  Node<T> * rear = this->head;  //rear指向单链表最后一个结点
  for(int i = 0; i < n; i++)  //若n>0，构造非空链表
    {
      rear->next = new Node<T>(values[i],rear->next);  //创建结点链入rear结点之后，尾插入
      rear = rear->next;  //rear指向新的链尾结点
    }
}

//析构函数，释放空间
template <class T>
SinglyList<T>::~SinglyList()
{
  this->removeAll();
  delete this->head;
}

//用于判断单链表是否为空
template <class T>
bool SinglyList<T>::empty()//O(1)
{
  return this->head->next==NULL;
}

//重写的<<操作符，用于输出单链表元素到控制台
template <typename K>
ostream& operator<<(ostream &out,SinglyList<K> &list)
{
  out<<"(";
  for(Node<K> *next=list.head->next; next != NULL; next = next->next)
    {
      out<<next->data;
      if(next->next != NULL)
	out<<",";
    }
  out<<")\n";
  return out;
}

//用于返回第i个元素，若i<0或大于表长则抛出异常O(n)
template <class T>
T& SinglyList<T>::get(int i) 
{
  Node<T> *p = this->head->next;
  for(int j = 0; j < i && p != NULL; j++) //遍历单链表，寻找第i个结点
    p = p->next;
  if(i >= 0 && p != NULL)//若i的指定范围有效且单链表不空
    return p->data; //返回第i个元素，执行T的拷贝构造函数                             
  throw out_of_range("参数i指定元素序号超出范围");//抛出C++ STL范围越界异常
}

//插入x作为单链表第i个元素，返回插入结点的地址。若i<0,插入x作为第0个元素；若i大于表长，插入x作为最后一个元素。O(n)
template <class T>
Node<T>* SinglyList<T>::insert(int i,T x)//O(n)
{
  Node<T> *front = this->head;  //front指向头结点
  for(int j = 0; front->next != NULL && j<i; j++ ) //遍历部分单链表寻找插入位置
    front = front->next; //循环停止时front定位到第i-1个结点或最后一个结点
  front->next = new Node<T>(x,front->next);//在front之后插入x结点，包括头插入(i<=0)，中间/尾插入(i>0)
  return front->next;  //返回插入结点地址
}

//删除第i(>=0)个结点，返回被删除元素。若i<0或大于表长则抛出异常,O(n)
template <class T>
T SinglyList<T>::remove(int i)//O(n)
{
  Node<T> *front = this->head;
  for(int j = 0; front->next != NULL && j < i; j++)
    front = front->next;
  if(i >= 0 && front->next != NULL)
    {
      Node<T> *q = front->next;
      T old = q->data;
      front->next = q->next;
      delete q;
      return old;
    }
  throw out_of_range("参数i指定元素序号超出范围");
}

//返回单链表结点个数
template <class T>
int SinglyList<T>::count()//O(n)
{
  int count = 0;
  Node<T> *p = this->head;
  while(p->next != NULL)
    {
      p = p->next;
      count++;
    }
  return count;
}

//删除单链表的所有元素，并释放空间 O(n)
template <class T>
void SinglyList<T>::removeAll()
{
  Node<T> *head = this->head;
  while(head->next !=NULL)
    {
      Node<T> *tmp = head->next;
      head->next = head->next->next;
      delete tmp;
    }
  this->head->next = NULL;
}

//按结点内容查找结点
template <class T>
Node<T>* SinglyList<T>::search(T key)
{
  Node<T> *front = this->head;
  while(front->next !=NULL)
    {
      front = front->next;
      if(front->data == key)
	{
	  return front;
	}
    }
  return NULL;
}
//用于链接两个单链表
template <class T>
void SinglyList<T>::operator+=(SinglyList<T> &list)
{
  Node<T> *rear = this->head;
  while(rear->next != NULL)//找到当前单链表的最后一个结点
    rear = rear->next;
  rear->next = list.head->next;//两条单链表首尾相接连接合并成一条单链表
  list.head->next = NULL;//设置list单链表为空，否则运行出错
}

//用于设置单链表第i个结点的数据为x，O(n)
//i的有效取值范围(0~count(),从head后面的结点开始计数，从0计数)
template <class T>
void SinglyList<T>::set(int i,T x)
{
  int j = 0;
  Node<T> *front = this->head;//front指向单链表的头结点
  while(j < i && front->next != NULL)//循环遍历单链表找到第i个结点的前一个结点
    {
      front = front->next;
      j++;
    }
  if(i >= 0 && front->next != NULL)//找到第i个结点元素
    {
      front->next->data=x;//执行T的=
    }
  else
    {
      throw out_of_range("参数i指定元素序号超出范围");
    }
}

//在单链表最后插入x,O(n)
template <class T>
Node<T>* SinglyList<T>::insert(T x)
{
  Node<T> *front = this->head;
  while(front->next!= NULL)//找到最后一个结点的next
    front = front->next;
  front->next = new Node<T>(x,front->next);//在最后位置插入data为x的结点
  return front->next;
}

//在链表尾部插入不重复结点,返回插入结点地址
template <class T>
Node<T>* SinglyList<T>::insertUnrepeatable(T x)
{
  Node<T> *front = this->head;
  while(front->next != NULL)
    {
      front = front->next;
      if(front->data == x)
	throw out_of_range("元素重复异常！");
    }
  front->next = new Node<T>(x);
  return front->next;
}
//删除单链表结点数据中首次出现数据key的结点
template <class T>
void SinglyList<T>::removeFirst(T key)
{
  Node<T> *front = this->head;
  while(front->next != NULL)
    {
      if(front->next->data == key)//T 需要重载==
	{
	  Node<T> *q = front->next;//记录下第一个与key相同的结点位置  
	  front->next = front->next->next;
	  delete q;
	  break;
	}
      front = front->next;
    }
}

//重写链表的==
template <class T>
bool SinglyList<T>::operator==(SinglyList<T> &list)
{
  if(this==&list || this->head == list.head)//指针比较，两个对象引用同一个实例，或者单链表浅拷贝，两个对象引用同一条单链表
    return true;
  Node<T> *p = this->head;
  Node<T> *q = list.head;
  while(p->next != NULL && q->next != NULL)
    {
      p = p->next;
      q = q->next;
      if(p->data != q->data)
	return false;
    }
  return true;
}

//重写链表的！=
template <class T>
bool SinglyList<T>::operator!=(SinglyList<T> &list)
{
  return !(*this==list);
}

//拷贝构造函数，深拷贝
template <class T>
SinglyList<T>::SinglyList(SinglyList<T> &list)
{
  this->head = new Node<T>();
  (*this) = list;//执行单链表的=，深拷贝
}

//重载=赋值运算符，深拷贝，删除再复制插入算法，构造结点将执行T的=运算，是否复制对象取决于T的=是深拷贝还是浅拷贝
template <class T>
SinglyList<T>& SinglyList<T>::operator=(SinglyList<T> &list)
{
  this->removeAll(); //清空当前当前单链表
  Node<T> *rear = this->head;  //rear指向单链表的头结点
  for(Node<T> *p = list.head->next; p != NULL; p = p->next)  //遍历list
    {
      rear->next = new Node<T>(p->data);  //复制结点尾到this单链表
      rear = rear->next;  //rear指向新的链尾结点
    }
  return *this;
}
template <class T>
void SinglyList<T>::removeAll(T key)                                 //删除所有关键字为key的元素;要求元素一次移动到位
{
  Node<T> *rear = this->head;
  while(rear->next != NULL)
    {
      if(rear->next->data == key)
	{
	  Node<T> *temp = rear->next;
	  rear->next = temp->next;
	  delete temp;
	}
      else
	rear = rear->next;
    }
}
template <class T>
void SinglyList<T>::replaceFirst(T key,T x)                        //将首次出现的关键字为key的元素替换为x
{
  Node <T> *rear = this->head;
  while(rear->next != NULL)
    {
      if(rear->next->data == key)
	{
	  rear->next->data = x;
	  break;
	}
      rear = rear->next;
    }
}
template <class T>
void SinglyList<T>::replaceAll(T key,T x)                           //将所有关键字为key的元素替换为x
{
  Node <T> *rear = this->head;
  while(rear->next != NULL)
    {
      if(rear->next->data == key)
	rear->next->data = x;
      rear = rear->next;
    }
}
//3.SingList类增加下列成员函数，按迭代方式遍历单链表
template <class T>
Node<T>* SinglyList<T>::first()                                       //返回单链表第0个元素结点(非头结点)
{
  if(this->head->next != NULL)
    return this->head->next;
  else
    return NULL;
}
template <class T>
Node<T>* SinglyList<T>::next(Node<T> *p)                   //返回p的后继结点
{
  if(p->next != NULL)
    {
      return p->next;
    }
  else
    {
      Node<T> *rear = this->head;
      while(rear->next != NULL)
	{
	  if(rear->next->data == p->data)
	    return rear->next->next;
	  rear = rear->next;
	}
    }
}
template <class T>
Node<T>* SinglyList<T>::previous(Node<T> *p)             //返回p的前驱结点
{
  Node<T> *rear = this->head;
  while(rear->next != NULL)
    {
      if(rear->next->data == p->data)
	return rear;
      rear = rear->next;
    }
  return NULL;
}
template <class T>
Node<T>* SinglyList<T>::last()                                        //返回单链表最后一个结点
{
  Node<T> *rear = this->head;
  while(rear->next != NULL)
    rear = rear->next;
  return rear;
}
//4.SingList类增加以下操作
template <class T>
bool SinglyList<T>::isSorted(bool asc)                  //判断是否已排序，asc指定升序或降序,true升序，false降序，默认升序
{
  Node<T> *p = this->head->next;
  if(p == NULL)
    return 1;
  while(p->next != NULL && (asc ? p->data<=p->next->data : p->data>=p->next->data))
    p = p->next;
  return p->next ==NULL;
}
template <class T>
T SinglyList<T>::max(SinglyList<T> &list)                      //返回list单链表最大值，T必须重载>
{
  Node<T> *rear = list.head->next;
  T max =rear->data;
  while(rear->next != NULL)
    {
      if(max < rear->next->data)
	max = rear->next->data;
      rear = rear->next;
    }
  return max;
}
template <class T>
void SinglyList<T>::reverse(SinglyList<T> &list)            //将单链表逆转
{
  Node<T> *p = list.head->next, *front = NULL;         //front作为p的前驱结点
  while(p != NULL)
    {
      Node<T> *succ = p->next;       //设置succ为p的后继结点
      p->next = front;         //使p->next指向p的前驱结点
      front = p;                   //前驱到达p结点
      p = succ;//p到达原后继结点
    }
  list.head->next = front;  //设置单链表头结点的指针域
}
//5.SinglyList类增加对子链表的操作，函数声明见实验题2-1(3)

/*
//////////////////此处搞明白，必须得返回引用，不能为了快而模糊不清，敷衍了事！////////////////////////////////////
//////////////////此处搞明白，必须得返回引用，不能为了快而模糊不清，敷衍了事！////////////////////////////////////
//////////////////此处搞明白，必须得返回引用，不能为了快而模糊不清，敷衍了事！////////////////////////////////////
//////////////////此处搞明白，必须得返回引用，不能为了快而模糊不清，敷衍了事！////////////////////////////////////
//////////////////此处搞明白，必须得返回引用，不能为了快而模糊不清，敷衍了事！////////////////////////////////////
//////////////////此处搞明白，必须得返回引用，不能为了快而模糊不清，敷衍了事！////////////////////////////////////
//////////////////此函数原本返回应用，所以得重写SinglyList的拷贝构造函数，为深拷贝///////////////////////////////
//明天任务：
//1.返回引用，由于是对当前对象进行直接处理，(除子表结点外的结点，并未处理，待修正。)
//2.返回对象，如果要返回对象，需重载=赋值运算符的函数形参为对象，而不是当前的引用
//3.返回指针，需记得释放空间
//查看三者之间的区别。
 */

template <class T>
SinglyList<T>& SinglyList<T>::sub(int i,int n)                       //返回从第i个结点开始，长度为n的子表
{
  //函数外调用此函数后，需记得delete subList释放空间
  SinglyList<T> *subList = new SinglyList<T>();//创建空的子表
  Node<T> *p = subList->head;
  int j = 0,k=i+n;//匹配要截取的子表结点
  Node<T> *rear = this->head;
  while(rear->next != NULL)
    {
      if(j >= i  &&  j < k)
	{
	  p->next = new Node<T>(rear->next->data,p->next);
	  p = p->next;
	}
      rear = rear->next;
      j++;
      if(j >= k)
	break;
    }
  return *subList;
}
/*
template <class T>
SinglyList<T> SinglyList<T>::sub(int i,int n)                       //返回从第i个结点开始，长度为n的子表
{//注意此函数并未对除子表外的其他结点进行处理
  int j = 0,k=i+n;//匹配要截取的子表结点
  Node<T> *rear = this->head;
  while(rear->next != NULL)
    {
      if(j == i)//获取子表首个结点
	this->head->next = rear->next;
      if(j == k)//使子表末尾结点指针域指向NULL
	{
	  rear->next = NULL;
	  break;
	}
      rear = rear->next;
      j++;
    }
  return *this;
}
*/
/*
template <class T>
SinglyList<T>* SinglyList<T>::sub(int i,int n)                       //返回从第i个结点开始，长度为n的子表
{//注意：
//函数外调用此函数后，需记得delete subList释放空间
  SinglyList<T> *subList = new SinglyList<T>();//创建空的子表
  Node<T> *p = subList->head;
  int j = 0,k=i+n;//匹配要截取的子表结点
  Node<T> *rear = this->head;
  while(rear->next != NULL)
    {
      if(j >= i  &&  j < k)
	{
	  p->next = new Node<T>(rear->next->data,p->next);
	  p = p->next;
	}
      rear = rear->next;
      j++;
      if(j >= k)
	break;
    }
  return subList;
}
*/

template <class T>
bool SinglyList<T>::contain(SinglyList<T> &list)                   //判断*this单链表是否包含list所有结点
{
  /*步骤：*/
  /*1.单链表排序*/
  Node<T> *cur_head = this->head,*l_head = list.head,*end = NULL;//排序单链表的头结点和尾结点
  quick_sort(cur_head->next,end);//排序当前单链表
  quick_sort(l_head->next,end);//排序list单链表
  /*2.单链表去重*/
  Node<T> *p = this->head->next,*p1=list.head->next;
  while(p != NULL && p->next != NULL)
    {
      if(p->data == p->next->data)
  	{
  	  Node<T> *temp = p->next;
  	  p->next = p->next->next;
  	  delete temp;
  	}
      else
  	{
  	  p = p->next;
  	}
    }
  
  while(p1 != NULL && p1->next != NULL)
    {
      if(p1->data == p1->next->data)
  	{
  	  Node<T> *temp = p1->next;
  	  p1->next = p1->next->next;
  	  delete temp;
  	}
      else
	{
	  p1 = p1->next;
	}
    }

  /* 3.比较是否包含 */
  p = this->head->next,p1 = list.head->next;
  while(p != NULL && p1 != NULL)
    {
      if(p->data == p1->data)
  	p1 = p1->next;
      p = p->next;
    }
  return p1 == NULL;
}
template <class T>
void  SinglyList<T>::insert(int i,SinglyList<T> &list)               //复制list所有结点插入到*this第i个结点前
{
  /*1.获取第i-1个结点*/
  /*2.将list追加到this第i个结点前*/
  /*3.将list头结点的指针域指向NULL*/
  Node<T> *_i = this->head;
  int j = 0;
  while(_i->next != NULL && j < i-1)/*i-1获取i结点的前一个结点*/
    {
      _i = _i->next;
      j++;
    }
  //当前_i即为当前单链表的第i-1个结点
  //获取list的最后一个结点
  
  list.last()->next = _i->next;
  _i->next = list.head->next;
  
  list.head->next = NULL;
  
}
template <class T>
void  SinglyList<T>::append(SinglyList<T> &list)                   //将list中所有结点复制添加到*this最后
{
  Node<T> *_last = this->last();
  _last->next = list.head->next;
  list.head->next = NULL;
}
template <class T>
SinglyList<T> SinglyList<T>::operator+(SinglyList<T> &list)    //返回*this与list合并连接后的单链表
{
  *this+=list;
  return *this;
}
template <class T>
void SinglyList<T>::remove(int i,int n)                               //删除从第i个结点开始，长度为n的子表
{//注意：第i个结点，i>=0,并且 i< *this单链表的长度
  Node<T> *_i = this->head;
  int j = 0;
  while(_i->next != NULL)
    {
      if(j >= i && j < i+n)
	{
	  Node<T> *temp = _i->next;
	  _i->next = temp->next;//此处注意是将_i的指针域指向要删除结点的下一个结点，要和while中表达式相对应
	  delete temp;
	  j++;
	}
      else
	{
	  _i = _i->next;
	  j++;
	}
    }
  
  /* for(int j = 0; j < n; j++) */
  /*   remove(i); */
}
template <class T>
SinglyList<T>& SinglyList<T>::operator*(SinglyList<T> &list)     //返回*this与list的所有共同元素，交集
{
  /*步骤：*/
  /* 1.排序 */
  Node<T> *cur = this->head->next,*_l = list.head->next,*end = NULL;
  quick_sort(cur,end);
  quick_sort(_l,end);
  /* 2. 去重*/
  while(cur != NULL && cur->next != NULL)
    {
      if(cur->data == cur->next->data)
	{
	  Node<T> *temp = cur->next;
	  cur->next = temp->next;
	  delete temp;
	}
      else
	cur = cur->next;
    }
  while(_l != NULL && _l->next != NULL)
    {
      if(_l->data == _l->next->data)
	{
	  Node<T> *temp = _l->next;
	  _l->next = temp->next;
	  delete temp;
	}
      else
	_l = _l->next;
    }
  /* 3.查找共同元素 */
  SinglyList<T> *_temp = new SinglyList<T>();//用于存储共同元素
  Node<T> *_i = _temp->head;
  cur = this->head->next,_l = list.head->next;
  while(cur != NULL && _l != NULL)
    {
      if(cur->data == _l->data)
	{
	  _i->next = new Node<T>(cur->data,_i->next);
	  _i = _i->next;
	  cur = cur->next;
	  _l = _l->next;
	}
      else if(cur->data < _l->data)
	cur = cur->next;
      else if(_l->data < cur->data)
	_l = _l->next;
    }
  /* cout<<*this; */
  /* cout<<list; */
  /* cout<<*_temp; */
  this->removeAll();//清空当前单链表
  this->head->next = _temp->head->next;//将存储共同元素的单链表追加到当前单链表
  _temp->head->next = NULL; //使临时存储共同元素的单链表头结点的指针域指向NULL
  delete _temp;//释放临时空间
  return *this;
}
template <class T>
void SinglyList<T>::operator-=(SinglyList<T> &list)              //删除那些也包含在list中的元素，差集(即把this中属于list中的元素删掉)
{
  //步骤：
  /* 一.找到共同元素 */
  /*步骤：*/
  /* 1.排序 */
  Node<T> *cur = this->head->next,*_l = list.head->next,*end = NULL;
  quick_sort(cur,end);
  quick_sort(_l,end);
  /* 2. 去重*/
  while(cur != NULL && cur->next != NULL)
    {
      if(cur->data == cur->next->data)
	{
	  Node<T> *temp = cur->next;
	  cur->next = temp->next;
	  delete temp;
	}
      else
	cur = cur->next;
    }
  while(_l != NULL && _l->next != NULL)
    {
      if(_l->data == _l->next->data)
	{
	  Node<T> *temp = _l->next;
	  _l->next = temp->next;
	  delete temp;
	}
      else
	_l = _l->next;
    }
  /* 3.查找共同元素 */
  SinglyList<T> *_temp = new SinglyList<T>();//用于存储共同元素
  Node<T> *_i = _temp->head;
  cur = this->head->next,_l = list.head->next;
  while(cur != NULL && _l != NULL)
    {
      if(cur->data == _l->data)
	{
	  _i->next = new Node<T>(cur->data,_i->next);
	  _i = _i->next;
	  cur = cur->next;
	  _l = _l->next;
	}
      else if(cur->data < _l->data)
	cur = cur->next;
      else if(_l->data < cur->data)
	_l = _l->next;
    }
  /* cout<<*this<<list; */
  /* 二.删除共同元素 */
  cur = this->head;
  _i = _temp->head;
  while(cur->next != NULL && _i->next != NULL)
    {
      if(cur->next->data == _i->next->data)
	{
	  Node<T> *temp = cur->next;
	  cur->next = temp->next;
	  _i = _i->next;
	  delete temp;
	}
      else if(cur->next->data < _i->next->data)
	cur = cur->next;
      else if(_i->next->data < cur->next->data)
	_i = _i->next;
    }
  //  cout<<*this;
  delete _temp;//释放空间
}
template <class T>
SinglyList<T> SinglyList<T>::operator-(SinglyList<T> &list)     //返回*this与list的差集
{
  *this-=list;
  return *this;
}
template <class T>
void SinglyList<T>::retainAll(SinglyList<T> &list)                  //仅保留那些也包含在list中的元素
{
  *this*list;
}
template <class T>
SinglyList<T>* SinglyList<T>::search(SinglyList<T> &list)          //判断*this是否包含与list匹配的子表
{
  *this*list;
  return this;
}
template <class T>
void SinglyList<T>::removeAll(SinglyList<T> list)                 //删除*this中所有与list匹配的子表
{
  *this-list;
}
template <class T>
void SinglyList<T>::replaceAll(SinglyList<T> listkey,SinglyList<T> listx)//将所有与listkey匹配子表替换为listx
{
  this->removeAll(listkey);
  this->append(listx);
}

template <class T>
void SinglyList<T>::random()                                            //将单链表元素随即排列
{
  // cout<<*this;
  T temp;
  Node<T> *_list = this->head->next;
 
  //time_t time(time_t *time);  time(0)用来获得1970年1月1日0时0分0秒到当前时间的秒数 
  srand((int)time(0));//Srand是种下随机种子数，每次种下的种子不一样，用Rand得到的随机数就不一样  
  
  while(_list != NULL && _list->next != NULL)
    {
      int flag = RANDOM(2);
      // cout<<flag<<endl;
      if(flag > 0)
  	{
  	  temp = _list->data;
  	  _list->data = _list->next->data;
  	  _list->next->data = temp;
  	}
      _list = _list->next;
    }
  // cout<<*this;
}
template <typename T>
bool SinglyList<T>::eq(T a, T b)
{
  return a==b;
}
template <>//模板特例化成员
double SinglyList<int>::average(SinglyList<int> &list)//计算整数单链表的平均值
{
  Node<int> *p = list.head;
  int count = 0;
  double sum = 0;//此处用double，不用int，否则返回值成int
  while(p->next != NULL)
    {
      p = p->next;
      sum += p->data;
      count++;
    }
  return sum / count;
}
template <>
double SinglyList<int>::averageExceptMaxMin(SinglyList<int> &list)//去掉最高分和最低分求平均值
{
  Node<int> *p = list.head;
  int count = 0;
  double sum = 0;
  int min = p->next->data;
  int max = min;
  while(p->next != NULL)
    {
      p = p->next;
      sum += p->data;
      count++;
      if(p->data < min)
	min = p->data;
      if(max < p->data)
	max = p->data;
    }
  return (sum-max-min) / (count-2);
}
