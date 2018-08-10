/*一元多项式的项类*/
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class TermX                                      //项类，一元多项式的一项
{
 public:
  double coef;                                   //系数
  int xexp;                                        //x变量指数，可为正，0
  TermX(double coef=0,int xexp=0);//构造一项，指定默认值
  TermX(const char* termstr);                    //以"系数x^指数"形式字符串构造一项

  friend ostream& operator<<(ostream& out,const TermX& term);  //重载<<输出流运算符
  bool operator==(TermX& term);    //按x指数比较两项是否相等
  bool operator!=(TermX& term);
  bool operator<(TermX& term);      //按x指数比较两项大小
  bool operator<=(TermX& term);
  bool operator>(TermX& term);
  bool operator>=(TermX& term);
  void operator+=(TermX& term);   //重载+=，约定两元素相加规则
  bool removeable();                       //约定删除元素条件
 private:
  bool eq(double num);//判断num是否等于0
};
inline TermX::TermX(double coef,int xexp)
{
  this->coef = coef;
  this->xexp = xexp;
}
inline TermX::TermX(const char *termstr)
{
  string str(termstr);//构造字符串
  int pos = str.find('x');//获取字符x的位置
  int len = str.size();//字符串长度
  
  //string left = str.substr(0,pos);//获取coef的字符串类型
  //string right = str.substr(pos+2,len-pos-1);//获取xexp的字符串类型

  istringstream str_coef(str.substr(0,pos));
  str_coef >> this->coef;
  istringstream str_xexp(str.substr(pos+2,len-pos-1));
  str_xexp >> this->xexp;
}
ostream& operator<<(ostream & out,const TermX& term)
{
  if(term.xexp > 0)
    {
      if(term.coef == 1)
	out<<"x^"<<term.xexp;
      else if(term.coef == -1)
	out<<"-x^"<<term.xexp;
      else
	out<<term.coef<<"x^"<<term.xexp;	
    }
  else if(term.xexp == 0)
    out<<term.coef;
  else if(term.xexp ==1)
    out<<term.coef<<"x";
  return out;
}
inline bool TermX::operator==(TermX &term)
{
  return this->xexp == term.xexp;
}
inline bool TermX::operator!=(TermX &term)
{
  return this->xexp != term.xexp;
}
inline bool TermX::operator<(TermX &term)
{
  return this->xexp < term.xexp;
}
inline bool TermX::operator<=(TermX &term)
{
  return this->xexp <= term.xexp;
}
inline bool TermX::operator>(TermX& term)
{
  return this->xexp > term.xexp;
}
inline bool TermX::operator>=(TermX& term)
{
  return this->xexp >= term.xexp;
}
inline void TermX::operator+=(TermX &term)
{
  this->coef += term.coef;
}
inline bool TermX::removeable()
{
  return eq(this->coef);
}
inline bool TermX::eq(double num)
{
  double N = 0.000001;
  return -N < num && num < N;
}
