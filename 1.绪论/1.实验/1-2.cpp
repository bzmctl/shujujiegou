/*实现对以下数组的操作，并给出算法的时间复杂度和空间复杂度*/
template <class T>
class Arr{
  // T *arr;
public:
  int index(T values[],int n,T key);         //在values数组前n个元素中查找key，顺序查找
  T max(T values[],int n);                   //返回数组元素最大值
  T min(T values[],int n);                   //返回数组元素最小值
  void min(T values[],int n,T &min1,T & min2);//返回数组元素中最小值和次最小值
  bool isSorted(T values[],int n);           //判断values数组元素是否已排序(升序或降序)
  void reverse(T values[],int n);            //将数组元素置逆(前后位值颠倒)
  void insert(T values[],int n,T key);       //将key插入到values排序数组前n个元素
  void sort(T values[],int n);   //插入排序
};
template <class T>
int Arr<T>::index(T values[],int n,T key)
{
  for(int i = 0; i < n; i++)
    if(values[i] == key)
      return i;
  return -1;
}
template <class T>
T Arr<T>::max(T values[],int n)
{
  for(int i = 1; i < n; i++)
    {
      if(values[0] < values[i])
	{
	  values[0] ^= values[i];
	  values[i] ^= values[0];
	  values[0] ^= values[i];
	}
    }
  return values[0];
}
template <class T>
T Arr<T>::min(T values[],int n)
{
  T tmp = values[0];
  for(int i = 1; i < n; i++)
    if(tmp > values[i])
      tmp = values[i];
  return tmp;
}
template <class T>
void Arr<T>::min(T values[],int n,T &min1,T & min2)
{
  min1 = 1000;
  min2 = 1001;
  for(int i = 0; i < n; i++){
    if(min1 >= values[i])
      min1 = values[i];
    else if(min2 > values[i])
      min2 = values[i];
  }
}
template <class T>
bool Arr<T>::isSorted(T values[],int n)
{
  int asc = 0,desc = 0;
  for(int i = 1; i < n; i++)
    if(values[i-1] < values[i])
      asc++;
    else
      desc++;
  if(asc == n-1 || desc == n-1)
    return true;
  return false;
}
template <class T>
void Arr<T>::reverse(T values[],int n)
{
  int i,j;
  for(i = 0,j = n-1; i < j; i++,j--)
    {
      values[i] ^= values[j];
      values[j] ^= values[i];
      values[i] ^= values[j];
    }
}
template <class T>
void Arr<T>::insert(T values[],int n,T key)
{
  //  for(int i = 0; i < n; i++)
    //values[i]
}
template <class T>
void Arr<T>::sort(T values[],int n)
{
  int i,j,key;
  for(i = 1; i < n; i++)
    {
      key = values[i];
      for(j = i-1;j >= 0; j--)
	{
	  if(values[j] > key)//升序排列
	    values[j+1]=values[j];//将大于key的数往后移
	  else
	    break;//切记此分支不能遗漏，如果内层改用while循环，循环条件(j>=0&&values[j]>key)已经规避values[j]<=key的情况。
	}
      values[j+1] = key;//将key插入它应该待的顺序位值上
    }
}

int
main()
{
  int index,max,min,min1,min2,arr[]={3,7,9,1,8,4,6,5,2,0};
  bool b;
  Arr<int> *p = new Arr<int>;
  p->sort(arr,10);
  b = p->isSorted(arr,10);
  ////////////////////////
  index = p->index(arr,10,3);
  max = p->max(arr,10);
  min = p->min(arr,10);
  p->min(arr,10,min1,min2);
  b = p->isSorted(arr,10);
  p->reverse(arr,10);
  return 0;
}
