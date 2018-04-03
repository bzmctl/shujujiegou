//从指定位置的插入排序
template <typename T>
void mysort(T *arr,int cur,int n)   
{  
  T tmp;
  int i,j;
  for(i = cur;i<n;i++)  
    {  
      tmp = arr[i];
      j = i-1;
      while(j>=0&&tmp<arr[j])
	{
	  arr[j+1] = arr[j];
	  j--;   
	}  
      arr[j+1] = tmp;
    }  
}  
