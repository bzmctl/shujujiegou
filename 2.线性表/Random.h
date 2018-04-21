
class Random
{
 public:
  Random(int n,int size,bool diff);//
  int next();
  void append(int n);
};
class SortedRandom:public Random
{

};
