#include <iostream>
#include <stdlib.h>

class Test
{
public:
  static void fun1(){std::cout<<stat<<"\n";}
  void fun2(){std::cout<<"Test\n";}
  void fun3(int test){std::cout<<test<<"\n";}
  void fun4(){/*std::cout<<var<<"\n";*/}
private:
  static int stat;
  int var;
};

int Test::stat = 5;

int main()
{
  Test *pTest = NULL;
  pTest->fun1();
  pTest->fun2();
  pTest->fun3(10);
  pTest->fun4();
  exit(0);
}
