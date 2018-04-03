class Complex{
private:
  double real,imag;  //复数的实部与虚部
public:
  Complex(){};
  Complex(double r,double i);  //指定复数的实部与虚部构造一个复数
  Complex add(Complex c);  //加法，返回当前复数与c相加之后的复数
  Complex sub(Complex c);  //减法，返回当前复数与c相减之后的复数
  
};
Complex::Complex(double r,double i)
{
  this->real = r;
  this->imag = i;
}
Complex Complex::add(Complex c)
{
  Complex c1(this->real+c.real,this->imag+c.imag);
  return c1;
}
Complex Complex::sub(Complex c)
{
  Complex c1(this->real-c.real,this->imag-c.imag);
  return c1;
}
int
main()
{
  Complex c(10.0,9.0),c1(8.0,7.0),c2;
  c2 = c.add(c1);
  c2 = c.sub(c1);
  return 0;
}
