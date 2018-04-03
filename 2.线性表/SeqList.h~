#include <iostream>
#include <stdexcept>                                //包含C++STL(标准类库)异常类
#include <random>
#include <algorithm>
using namespace std;

template <class T> class SeqList;
template <class T> ostream& operator<<(ostream &out,SeqList<T> &list);

template <class T>                                        //顺序表类，T指定元素类型
class SeqList
{

 protected:                                                     //保护成员，子类可见
  T *element;                                                   //动态数组存储顺序表的数据元素
  int length;                                                     //顺序表的数组容量
  int n;                                                             //顺序表的元素个数(长度)

private:                                                           //私有成员，只在本类可见 
  void init(T values[],int n);                              //初始化顺序表


 public:                                                            //公有成员，所有类可见
  SeqList(int length=32);                                 //构造空表，length指定(默认)容量
  SeqList(int length,T x);                                  //构造顺序表，length个元素值为x
  SeqList(T values[],int n);                               //构造顺序表，由values数组提供元素
  ~SeqList();                                                   //析构函数

  bool empty();                                                //顺序表是否为空
  int count();                                                   //顺序表元素个数
  T& operator[](int i);                                       //重载下标运算符[]
  friend ostream& operator<<<>(ostream&,SeqList<T>&);  //输出顺序表所有元素
  void printPrevious();                                      //反序输出，从后到前
  void insert(int i,T x);                                      //插入x作为第i个元素
  virtual void insert(T x);                                  //在顺序表最后插入x;虚函数
  T remove(int i);                                             //删除第i个元素，返回被删除元素
  void removeAll();                                           //删除顺序表所有元素
  virtual int search(T key,int start=0);              //从start开始查找key元素，返回元素序号
  virtual void removeFirst(T key);                     //删除首次出现关键字为key的元素;虚函数
 
  SeqList(SeqList<T> &list);                            //拷贝构造函数
  SeqList<T>& operator=(SeqList<T> &list);  //重载=赋值运算符，深拷贝
  bool operator==(SeqList<T>&);                   //比较两个顺序表对象的值是否相等
  bool operator!=(SeqList<T>&);                     //比较两个顺序表是否不等 
  void operator+=(SeqList<T>&);                   //在*this当前顺序表之后合并连接list
  SeqList<T> operator+(SeqList<T>&);          //返回*this与list合并连接的对象

  /*试验内容：*/
  /*2-1 SeqList顺序表类增加以下成员函数：*/
  /*1.基于查找(从前向后次序)的删除和替换操作*/
  void removeAll(T key);                                 //删除所有关键字为key的元素;要求元素一次移动到位
  void replaceFirst(T key,T x);                        //将首次出现的关键字为key的元素替换为x
  void replaceAll(T key,T x);                           //将所有关键字为key的元素替换为x
  /*2.查找(从后向前次序)及删除和替换操作*/
  int searchLast(T key,int start);                     //从start开始顺序查找最后出现的关键字为key的元素
  void removeLast(T key);                              //删除最后出现关键字为key的元素
  void replaceLast(T key,T x);                         //将最后出现的关键字为key的元素替换为x
  /*3.SeqList类增加以下对子表进行操作的成员函数，要求元素一次移动到位 */
  SeqList<T>& sub(int i,int n);                         //返回从第i个结点开始，长度为n的子表
  bool contain(SeqList<T> &list);                   //判断*this单链表是否包含list所有结点
  void insert(int i,SeqList<T> &list);               //复制list所有结点插入到*this第i个结点前
  void append(SeqList<T> &list);                   //将list中所有结点复制添加到*this最后
  // SeqList<T> operator+(SeqList<T> &list);    //返回*this与list合并连接后的单链表
  void remove(int i,int n);                               //删除从第i个结点开始，长度为n的子表
  SeqList<T>& operator*(SeqList<T> &list);     //返回*this与list的所有共同元素，交集
  void operator-=(SeqList<T> &list);              //删除那些也包含在list中的元素，差集
  SeqList<T> operator-(SeqList<T> &list);     //返回*this与list的差集
  void retainAll(SeqList<T> &list);                  //仅保留那些也包含在list中的元素
  SeqList<T>* search(SeqList<T> &list);          //判断*this是否包含与list匹配的子表
  void removeAll(SeqList<T> list);                 //删除*this中所有与list匹配的子表
  void replaceAll(SeqList<T> listkey,SeqList<T> listx);//将所有与listkey匹配子表替换为listx
  void random();                                            //将线性表元素随即排列
};

template <class T>
void SeqList<T>::init(T values[],int n)
{
  this->length = n * 2;
  this->element = new T[this->length];
  this->n = n;
  for(int i = 0; i < n; i++)
    this->element[i] = values[i];                       //执行T的=赋值，T的默认=赋值必须
}
template <class T>
SeqList<T>::SeqList(int length)
{
  cout<<"SeqList(int length)"<<endl;
  this->element = new T[length];
  this->length = length;
  this->n = 0;
}
template <class T>
SeqList<T>::SeqList(int length,T x)
{
  this->element = new T[length];
  this->length = this->n = length;
  for(int i = 0; i < n; i++)
    this->element[i] = x;
}
template <class T>
SeqList<T>::SeqList(T values[],int n)
{
  cout<<"~SeqList(T values[],int n)"<<endl;
  this->init(values,n);
}
template <class T>
SeqList<T>::~SeqList()
{
  cout<<"~SeqList()"<<endl;
  delete []this->element;
}
template <class T>
bool SeqList<T>::empty()
{
  return this->n==0;
}
template <class T>
int SeqList<T>::count()
{
  return this->n;
}
template <class T>
T& SeqList<T>::operator[](int i)
{
  if(i >= 0 && i < this->n)
    return this->element[i];
  throw out_of_range("参数i指定元素序号超出范围!");  //抛出C++STL范围越界异常
}
template <class T>
ostream& operator<<(ostream &out,SeqList<T> &list)
{
  out<<"(";
  if(list.n > 0)
    out<<list.element[0];
  for(int i = 1; i < list.n; i++)
    out<<list.element[i];
  out<<")\n";
  return out;
}
template <class T>
void SeqList<T>::printPrevious()
{
  for(int i = this->n-1; i >=0; i--)
    cout<<this->element[i];
  cout<<"\n";
}
template <class T>
void SeqList<T>::insert(int i,T x)
{                                                                   //进行容错控制
  if(i < 0)i=0;
  if(i >this->n)i=this->n;
  T *tmp = this->element;
  if(this->n==this->length)
    {
      this->length *=2;
      this->element = new T[length];
      for(int j = 0; j < i; j++)
	this->element[j] = tmp[j];
    }
  for(int j = this->n-1; j >= i; j--)
    this->element[j+1] = tmp[j];
  if(this->element != tmp)
    delete tmp;
  this->element[i] = x;                                                      //T要重载=运算符
  this->n++;
}
template <class T>
void SeqList<T>::insert(T x)                //O(1)                   //在顺序表最后插入x;虚函数
{
  this->insert(this->n,x);
}
template <class T>
T SeqList<T>::remove(int i)                                              //删除第i个元素，返回被删除元素
{
  if(this->n > 0 && i >= 0 && i < this->n)
    {
      T old = this->element[i];
      for(int j = i; j < this->n-1; j++)
	this->element[j] = this->element[j+1];
      this->n--;
      return old;
    }
  throw out_of_range("参数i指定元素序号超出范围！");
}
template <class T>
void SeqList<T>::removeAll()
{
  this->n = 0;        
}
template <class T>
int SeqList<T>::search(T key,int start)
{
  for(int i = start; i < this->n; i++)
    if(this->element[i] == key)                       //T需要重载==
      return i;
  return -1;
}
template <class T>
void SeqList<T>::removeFirst(T key)
{
  this->remove(this->search(key));
}
template <class T>
SeqList<T>::SeqList(SeqList<T> &list)             
{
  cout<<"SeqList<T>::SeqList(SeqList<T> &list)"<<endl;
  this->init(list.element,list.n);
}
template <class T>
SeqList<T>& SeqList<T>::operator=(SeqList<T> &list)
{
  if(this->length > list.n)
    {
      this->n = list.n;
      for(int i =0; i < list.n; i++)
	this->element[i] = list.element[i];
      return *this;
    }
  //当前对象数组容量较小时，扩充数组容量
  this->~SeqList();
  this->init(list.element,list.n);
  return *this;
}
template <class T>
bool SeqList<T>::operator==(SeqList<T>&list)
{
  //比较指针，二者是否是同一个实例，或者顺序表的浅拷贝，二者引用同一个数组
  if(this == &list || this->element == list.element)
    return true;
  if(this->n != list.n)
    return false;
  for(int i = 0; i < list.n; i++)
    if(this->element[i] != list.element[i])
      return false;
  return true;
}
template <class T>
bool SeqList<T>::operator!=(SeqList<T> &list)  //比较两个顺序表是否不等 
{
  return !(*this==list);
}
/*
template <class T>
void SeqList<T>::operator+=(SeqList<T> &list)//在*this当前顺序表之后合并连接list
{
  T *tmp = this->element;
  int n = this->n;
  if(this->length <= this->n + list.n)
    {
        this->length += list.length;
	this->element = new T[this->length];
	for(int i = 0; i < this->n; i++)
	  this->element[i] = tmp[i];
	this->n += list.n;
	for(int i = 0; i < list.n; i++)
	  this->element[i+n] = list.element[i];
    }
  else
    {
      for(int i = 0; i < list.n; i++)
	this->element[i+this->n] = list.element[i];
      this->n +=list.n;
    }
  if(tmp != this->element)
    delete tmp;
}
*/
///*
template <class T>
void SeqList<T>::operator+=(SeqList<T> &list)
{
  for(int i = 0; i < list.n; i++)
    this->insert(list[i]);                                      //虚函数与滞后联编
}
//*/
template <class T>
SeqList<T> SeqList<T>::operator+(SeqList<T>&list)//返回*this与list合并连接的对象
{
  *this += list;
  return *this;
}
template <class T>
void SeqList<T>::removeAll(T key)//O(n)
{
  int src=0,dst=0,count=0;
  for(int i = 0; i < this->n; i++)
    {
      if(this->element[i] != key)
	{
	  this->element[dst] = this->element[src];
	  dst++;
	  count++;
	}
      src++;
    }
  this->n = count;
}
template <class T>
void SeqList<T>::replaceFirst(T key,T x)
{
  for(int i = 0; i < this->n; i++)
    if(this->element[i] == key)
      {
	this->element[i] = x;
	break;
      }
}
template <class T>
void SeqList<T>::replaceAll(T key,T x)
{
  for(int i = 0; i < this->n; i++)
    if(this->element[i] == key)
      this->element[i] = x;
}
template <class T>
int SeqList<T>::searchLast(T key,int start)                     //从start开始顺序查找最后出现的关键字为key的元素
{
  for(int i=this->n-1; i >=start; i--)
    if(this->element[i] == key)
      return i;
  return -1;
}
template <class T>
void SeqList<T>::removeLast(T key)                              //删除最后出现关键字为key的元素
{
  int i = searchLast(key,0);
  if(i == -1);
  else
    {
      for(int j = i; j < this->n-1; j++)
	this->element[j] = this->element[j+1];
      this->n--;
    }
}
template <class T>
void SeqList<T>::replaceLast(T key,T x)                         //将最后出现的关键字为key的元素替换为x
{
  int i = searchLast(key,0);
  if(i == -1);
  else
    this->element[i] = x;
}
  /*3.SeqList类增加以下对子表进行操作的成员函数，要求元素一次移动到位 */
template <class T>
SeqList<T>& SeqList<T>::sub(int i,int n)                         //返回从第i个结点开始，长度为n的子表
{
  for(int j = 0; j < n; j++)
    this->element[j] = this->element[i+j];
  this->n = n;
  return *this;
}
template <class T>
bool SeqList<T>::contain(SeqList<T> &list)                   //判断*this单链表是否包含list所有结点
{
  int count = 0;
  for(int i = 0; i < list.n; i++)
    for(int j = 0; j < this->n; j++)
      if(list.element[i] == this->element[i])
	{
	  count++;
	  break;
	}
  return count == list.n;
}
template <class T>
void SeqList<T>::insert(int i,SeqList<T> &list)               //复制list所有结点插入到*this第i个结点前
{
  int n = this->n + list.n;
  T *tmp = this->element;
  if(n >= this->length)
    {
      this->element = new T[n];
      for(int j = 0; j < i; j++)
	this->element[j] = tmp[j];
      for(int j = i; j < this->n; j++)
	this->element[j+list.n] = tmp[j];
    }
  else
    {
      for(int j = i; j < this->n; j++)
	this->element[j+list.n] = this->element[j];
    }
  for(int j = 0; j < list.n; j++)
    this->element[j+i] = list.element[j];
  if(this->element != tmp)
    delete []tmp;
  this->n = n;
}
template <class T>
void SeqList<T>::append(SeqList<T> &list)                   //将list中所有结点复制添加到*this最后
{
  T *tmp = this->element;
  int n = this->n + list.n;
  if(this->length <= n)
    {
      this->element = new T[n];
      for(int i = 0; i < this->n; i++)
	this->element[i] = tmp[i];
    }
  for(int i = 0; i < list.n; i++)
    this->element[this->n+i] = list.element[i];
  if(tmp != this->element)
    delete []tmp;
  this->n = n;
}
/*
template <class T>
SeqList<T> SeqList<T>::operator+(SeqList<T> &list)    //返回*this与list合并连接后的单链表
{

}*/
template <class T>
void SeqList<T>::remove(int i,int n)     //O(n)                          //删除从第i个结点开始，长度为n的子表
{
  for(int j = i; j < i+n; j++)
    this->element[j] = this->element[j+n];
  this->n -= n;
}

template <class T>
SeqList<T>& SeqList<T>::operator*(SeqList<T> &list)     //返回*this与list的所有共同元素，交集 O(n^2)
{
  SeqList<T> *temp = new SeqList<T>(*this);
  temp->n = 0;//设置顺序表元素为0个
  T *first1 = this->element,
    *last1 = this->element + this->n,
    *first2 = list.element,
    *last2 = list.element + list.n, 
    *result = temp->element;
  sort(first1,last1);
  sort(first2,last2);
  while (first1!=last1 && first2!=last2)
    {
      if (*first1<*first2) ++first1;
      else if (*first2<*first1) ++first2;
      else {
	*result = *first1;
	temp->n++;
	++result; ++first1; ++first2;
      }
    }
  return *temp;
  /*
  int count = 0;
  for(int i = 0; i < this->n; i++)
    for(int j = 0; j < list.n; j++)
      if(this->element[i] == list.element[j])
	{
	  this->element[count++] = this->element[i];
	  break;
	}
  this->n = count;
  //去重
  
  return *this;
  */
}
template <class T>
void SeqList<T>::operator-=(SeqList<T> &list)              //删除那些也包含在list中的元素，差集
{
  for(int i = 0; i < list.n; i++)
    removeAll(list.element[i]);
}
template <class T>
SeqList<T> SeqList<T>::operator-(SeqList<T> &list)     //返回*this与list的差集
{
  *this-=list;
  return *this;
}
template <class T>
void SeqList<T>::retainAll(SeqList<T> &list)                  //仅保留那些也包含在list中的元素
{
  *this*list;
}
template <class T>
SeqList<T>* SeqList<T>::search(SeqList<T> &list)          //判断*this是否包含与list匹配的子表
{
  return &(*this*list);
}
template <class T>
void SeqList<T>::removeAll(SeqList<T> list)                 //删除*this中所有与list匹配的子表
{
  *this-list;
}
template <class T>
void SeqList<T>::replaceAll(SeqList<T> listkey,SeqList<T> listx)//将所有与listkey匹配子表替换为listx
{
  removeAll(listkey);
  *this+listx;
}
template <class T>
void SeqList<T>::random()                                            //将线性表元素随即排列
{
  static default_random_engine e(time(0));
  static uniform_int_distribution<unsigned> u(0, this->n-1);
  T tmp;
  for(int i = 0; i < this->n; i++)
    {
      int ranNum = u(e);
      tmp = this->element[i];
      this->element[i] = this->element[ranNum];
      this->element[ranNum] = tmp;
    }
}
