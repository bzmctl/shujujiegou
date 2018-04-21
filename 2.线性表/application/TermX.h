/*一元多项式的项类*/
class TermX                                      //项类，一元多项式的一项
{
 public:
  double coef;                                   //系数
  int xexp;                                        //x变量指数，可为正，0
  TermX(double coef=0,int xexp=0);//构造一项，指定默认值
  TermX(char* termstr);                    //以"系数x^指数"形式字符串构造一项

  friend ostream& operator<<(ostream& out,const TermX& term);  //重载<<输出流运算符
  bool operator==(TermX& term);    //按x指数比较两项是否相等
  bool operator!=(TermX& term);
  bool operator<(TermX& term);      //按x指数比较两项大小
  bool operator<=(TermX& term);
  bool operator>(TermX& term);
  bool operator>=(TermX& term);
  void operator+=(TermX& term);   //重载+=，约定两元素相加规则
  bool removeable();                       //约定删除元素条件
};
