#include<stdio.h> 
#define n 10 
void yiwei()
{
  int a[n]={1,1},i,j;  //定义变量i,j,a[n],并且为a[0],a[1]赋初值
  printf("%5d\n%5d%5d\n",1,a[0],a[1]); //输出第一层和第二层
  for(i=1;i<n;i++) //输出剩下层
  {
    a[i+1]=a[i];//每层的第一个值与上一层的第一个值相等
    for(j=i;j>0;j--)
      a[j]=a[j-1]+a[j];//每个数等于它上方两数之和
    for(j=0;j<i+2;j++)
      printf("%5d",a[j]);//输出该层
    printf("\n");
  }
}

void erwei()
{
  int a[30][30]={0},i,j,n=10; 
  for(i=0;i<=n-1;i++) 
    a[i][0]=1; 
  for(i=1;i<=n-1;i++) 
    for(j=1;j<=i;j++) 
      a[i][j]=a[i-1][j-1]+a[i-1][j]; 
  for(i=0;i<=n-1;i++)
  { 
    for(j=0;j<=i;j++) 
      printf("%5d",a[i][j]); 
    printf("\n"); 
  }
}

int main() 
{ 
  return 0; 
} 