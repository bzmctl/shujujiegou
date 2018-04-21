/*从指定位置的插入排序*/
/*参数说明：arr要排序的数组，cur从数组指定位置接着排序的位置，n数组元素个数*/
template <typename T>
void mysort(T *arr,int cur,int n)   
{  
  T tmp;
  int i,j;
  for(i = cur;i<n;i++)  
    {  
      tmp = arr[i];
      j = i-1;
      while(j >= 0 && tmp < arr[j])
	{
	  arr[j+1] = arr[j];
	  j--;   
	}  
      arr[j+1] = tmp;
    }  
}  
/*单链表快速排序*/
/*1.交换两个数*/
template <typename T>
void swap(T *a,T *b)
{
  T temp = *a;
  *a = *b;
  *b = temp;
}
/*2.阶段排序*/
/*单链表快速排序的阶段排序，返回下次排序的基准结点*/
/*参数说面：pBegin单链表的首个结点，pEnd单链表末尾结点*/
template <typename T>
Node<T>* step(Node<T> *pBegin,Node<T> *pEnd)
{
  if(pBegin == NULL || pBegin == pEnd)
    return pBegin;
  T key = pBegin->data; //以pBegin作为基准元素
  Node<T> *p = pBegin,*q = pBegin;
  while(q != pEnd)//使单链表p结点左边的结点元素都比基准小，右边结点元素都比基准大
    {
      if(q->data < key)
	{
	  p = p->next;
	  swap(&p->data,&q->data);
	}
      q = q->next;
    }
  swap(&pBegin->data,&p->data);//交换基准结点数据与最后一个比基准结点数据的小结点的数据
  return p;
}
/*3.排序*/
template <typename T>
void quick_sort(Node<T> *pBegin,Node<T> *pEnd)
{
  if(pBegin == NULL || pBegin == pEnd)
    return ;
  //if(pBegin != pEnd)
  //  {
  Node<T> *mark = step(pBegin,pEnd);
  quick_sort(pBegin,mark);
  quick_sort(mark->next,pEnd);
      // }
}

/*数组快速排序*/
template <typename T>
void quickSort(T arr[],int _left,int _right){
  int left = _left;
  int right = _right;
  T temp;
  if(left <= right){   //待排序的元素至少有两个的情况
    temp = arr[left];  //待排序的第一个元素作为基准元素
    while(left != right){   //从左右两边交替扫描，直到left = right
      
      while(right > left && arr[right] >= temp)
	right --;        //从右往左扫描，找到第一个比基准元素小的元素
      arr[left] = arr[right];  //找到这种元素arr[right]后与arr[left]交换
      
      while(left < right && arr[left] <= temp)
	left ++;         //从左往右扫描，找到第一个比基准元素大的元素
      arr[right] = arr[left];  //找到这种元素arr[left]后，与arr[right]交换
      
    }
    arr[right] = temp;    //基准元素归位
    quickSort(arr,_left,left-1);  //对基准元素左边的元素进行递归排序
    quickSort(arr, right+1,_right);  //对基准元素右边的进行递归排序
  }
}
