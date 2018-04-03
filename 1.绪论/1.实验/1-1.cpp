/*用递归算法求最大公约数*/
int getN(int m,int n)
{
  if(n != 0)
    return getN(n,m%n);
  return m;
}
/*求n个数中的最大公约数*/
int getN(int * arr,int num)
{
  int tmp=0;
  for(int i=2;i<num;i++)
    tmp = getN(getN(arr[i-2],arr[i-1]),arr[i]);
  return tmp;
}
int
main()
{
  //int a=getN(12,9);

  int arr[] ={12,15,24,132,9,21,6,9,18,3000};
  int b = getN(arr,10);
  return 0;
}
