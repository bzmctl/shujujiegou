/*一元多项式的链式存储结构*/
#include "SortedSinglyList.h"                           //排序单链表
#include <string>
template <class T>
class Polynomial:public SortedSinglyList<T>          //多项式排序单链表，继承排序单链表
{
 public:
  Polynomial(){};                                                    //构造函数，自动执行基类无参构造函数
  Polynomial(T terms[],int n):SortedSinglyList(terms,n){};  //构造函数，由项数组提供各项值
                                                                                          //声明调用基类构造函数 
  Polynomial(char* polystr);                                    //由字符串构造多项式
  void print();                                                         //输出多项式
  void operator+=(Polynomial<T> &poly);   //*this与多项式poly相加
  Polynomial<T> operator+(Polynomial<T> &poly);            //返回*this与poly相加后的多项式
};
Polynomial<T>::Polynomial(char * polystr)
{
  
}
void Polynomial<T>::print()
{
  
}
void Polynomial<T>::operator+=(Polynomial<T> &poly)
{

}
Polynomial<T> Polynomial<T>::operator+(Polynomial<T> &poly)
{

}
