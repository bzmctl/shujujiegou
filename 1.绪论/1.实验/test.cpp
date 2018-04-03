template <typename T>
void get(int a[],T &b)
{
  int i,j,k,m;
  i=sizeof(a);
  j=sizeof(b);
  k=sizeof(b[0]);
  m=j/k;
  m=0;
}
int
main()
{
  int a[5]={1,2,3,4,5};
  int b=sizeof(a);
  get(a,a);
  return 0;
}
