#include "SeqList.h"
#include <stdlib.h>
#define RANDOM(x) (rand() %x)  //rand()对x取模运算，得到0～x-1之间的整数
class Random
{
 public:
  Random(int n,int size,bool diff);//生成n个随即数，范围0～size-1，diff指定互异否
  ~Random();
  int next();//返回下一随即数
  void append(int n);//添加n个随机数
  SeqList<int> *arr;//用来存储生成的随机数
 private:
  int getRandom(int size)
  {
    //srand()用来种下随机数种子，每次种子不一样，则rand()生成的随即数也不一样，本次则以time(0)为种子
    srand((int)time(0));
    return RANDOM(size);
  }
};
Random::Random(int n,int size,bool diff)
{
  arr = new SeqList<int>();
  arr->insert(getRandom(size));
  if(diff)
    {
      int i = 1;
      while(i < n)
	{
	  int res = getRandom(size);
	  bool flag = true;
	  for(int j = 0; j < arr->count();j++)
	    if(res == (*arr)[j])
	      {
		flag = false;
		break;
	      }
	  if(flag)
	    {
	      arr->insert(res);
	      i++;
	    }
	}
    }
  else
    {
      for(int i = 1; i < n; i++)
	arr->insert(getRandom(size));
    }
}
Random::~Random()
{
  delete arr;
}
int Random::next()
{
  //没参照，谁的下一个
  //或者类似getRandom()
}
void Random::append(int n)
{
  for(int i = 0; i < n; i++)
    arr->insert(getRandom(n));
}
class SortedRandom:public Random
{
 public:
  SortedRandom();
};
