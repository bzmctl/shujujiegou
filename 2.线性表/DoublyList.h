#include "DoubleNode.h"        //双链表节点类                          
#include <iostream>
using namespace std;

template <typename T>
class DoublyList
{
public:  
  Node<T> *head;                                               //头指针，指向双链表的头结点
  
  DoublyList();                                                //构造空双链表
  DoublyList(T values[],int n);                                //构造双链表，由values数组提供元素
  ~DoublyList();                                               //析构函数
  
  bool empty();                                                //判断双链表是否为空
  int count();                                                 //返回双链表长度
  T& get(int i);                                               //返回第i(i>=0)个元素的引用
  virtual void set(int i,T x);                                 //设置第i（i>=0）个元素的值为x
  template <typename K> friend ostream& operator<<(ostream&,DoublyList<K>&);    //输出双链表所有元素
  Node<T>* insert(int i,T x);                                  //插入x作为第i个结点，返回插入结点的地址
  virtual Node<T>* insert(T x);                                //在双链表最后插入x，虚函数
  T remove(int i);                                             //删除第i(i>=0)个结点，返回被删除元素
  void removeAll();                                            //清空双链表
  Node<T>* search(T key);                                      //顺序查找首先出现关键字为key的元素，返回结点地址；若未找到返回NULL。T必须重载==运算，约定比较两个元素(==)的规则
  virtual Node<T>* insertUnrepeatable(T x);                    //尾插入不重复元素,返回插入结点地址
  virtual void removeFirst(T key);                             //删除首次出现的元素值为key的结点
  bool operator==(DoublyList<T> &list);                        //比较两条双链表是否相等
  bool operator!=(DoublyList<T> &list);                        //比较两条双链表是否不相等
  DoublyList(DoublyList<T> &list);                             //拷贝构造函数，深拷贝
  DoublyList<T>& operator=(DoublyList<T> &list);               //重载=赋值运算符，深拷贝
  virtual void operator+=(DoublyList<T> &list);                //将list链接在当前链表之后;虚函数
  void removeAll(T key);                                       //删除所有关键字为key的元素;要求元素一次移动到位
  void replaceFirst(T key,T x);                                //将首次出现的关键字为key的元素替换为x
  void replaceAll(T key,T x);                                  //将所有关键字为key的元素替换为x
  Node<T>* first();                                            //返回双链表第0个元素结点(非头结点)
  Node<T>* next(Node<T> *p);                                   //返回p的后继结点
  Node<T>* previous(Node<T> *p);                               //返回p的前驱结点
  Node<T>* last();                                             //返回双链表最后一个结点
  bool isSorted(bool asc=true);                                //判断是否已排序，asc指定升序或降序
  T max(DoublyList<T> &list);                                  //返回list双链表最大值，T必须重载>
  void reverse(DoublyList<T> &list);                           //将双链表逆转  
  DoublyList<T>& sub(int i,int n);                             //返回从第i个结点开始，长度为n的子表
  bool contain(DoublyList<T> &list);                           //判断*this双链表是否包含list所有结点
  void insert(int i,DoublyList<T> &list);                      //复制list所有结点插入到*this第i个结点前
  void append(DoublyList<T> &list);                            //将list中所有结点复制添加到*this最后
  DoublyList<T> operator+(DoublyList<T> &list);                //返回*this与list合并连接后的双链表
  void remove(int i,int n);                                    //删除从第i个结点开始，长度为n的子表
  DoublyList<T>& operator*(DoublyList<T> &list);               //返回*this与list的所有共同元素，交集
  void operator-=(DoublyList<T> &list);                        //删除那些也包含在list中的元素，差集
  DoublyList<T> operator-(DoublyList<T> &list);                //返回*this与list的差集
  void retainAll(DoublyList<T> &list);                         //仅保留那些也包含在list中的元素
  DoublyList<T>* search(DoublyList<T> &list);                  //判断*this是否包含与list匹配的子表
  void removeAll(DoublyList<T> list);                          //删除*this中所有与list匹配的子表
  void replaceAll(DoublyList<T> listkey,DoublyList<T> listx);  //将所有与listkey匹配子表替换为listx
  void random();                                               //将双链表元素随即排列
};
