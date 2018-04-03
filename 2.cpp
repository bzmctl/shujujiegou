#include <iostream>
#include <stdlib.h>
typedef int (*Pfunc)(int,int);
int add(int a,int b){return a + b;}
int minus(int a,int b){return a - b;}
int multi(int a,int b){return a * b;}
int divide(int a, int b){return a /b;}
int process(int a,int b,Pfunc func){return func(a,b);}
int main()
{
  int a=10,b=2;
  int res1 = process(a,b,add);
  int res2 = process(a,b,minus);
  int res3 = process(a,b,multi);
  int res4 = process(a,b,divide);
  std::cout<<res1<<","<<res2<<","<<res3<<","<<res4<<"\n";
  exit(0);
}
