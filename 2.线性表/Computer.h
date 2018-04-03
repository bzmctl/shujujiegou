#include <iostream>
using namespace std;
class Computer{
  int cpu;
  double mem;
 public:
  Computer();
  Computer(int c,double m);
  friend ostream& operator <<(ostream&,Computer &c);
  bool operator==(Computer &c);
  bool operator!=(Computer &c);
  void operator=(Computer &c);
  bool operator>=(Computer &c);
  bool operator<=(Computer &c);
  bool operator>(Computer &c);
  bool operator<(Computer &c);
};
ostream& operator<<(ostream& out,Computer &c)
{
  out<<"cpu:"<<c.cpu<<",mem:"<<c.mem;
  return out;
}
Computer::Computer()
{
  cpu=0;
  mem=0.0;
}
Computer::Computer(int c,double m)
{
  cpu = c;
  mem = m;
}
bool Computer::operator==(Computer &c)
{
  return (this->cpu==c.cpu) && !(this->mem>c.mem) && !(this->mem<c.mem);
}
bool Computer::operator!=(Computer &c)
{
  return !(*this==c);
}
void Computer::operator=(Computer &c)
{
  this->cpu = c.cpu;
  this->mem = c.mem;
}
bool Computer::operator>=(Computer &c)
{
  return this->cpu == c.cpu && this->mem >= c.mem || this->cpu > c.cpu;
}
bool Computer::operator<=(Computer &c)
{
  return this->cpu == c.cpu && this->mem <= c.mem || this->cpu < c.cpu;
}
bool Computer::operator>(Computer &c)
{
  return this->cpu == c.cpu && this->mem > c.mem || this->cpu > c.cpu;
}
bool Computer::operator<(Computer &c)
{
  return this->cpu == c.cpu && this->mem < c.mem || this->cpu < c.cpu;;
}
