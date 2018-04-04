// #include "SeqList.h"
// int main()
// {
//   int a1[] = {5,3,2,4,1}, a2[] = {4,5,6,7,3,2,2};
  
//   SeqList<int> list5,list1(a1,5),list2(a2,6),list3(10);
//   delete &(list1*list2);
//   return 0;
// }
//#include "SortedSeq List.h"
// int
// main()
// {
//   int a[10000],b[10000],c[10000];
//   for(int i = 0; i < 10000; i++)
//     a[i]=i,b[i]=i,c[i]=i;
//   SeqList<int> list(a,10000);
//   SortedSeqList<int> list1(b,10000),list2(c,10000);
//   list1+list2;
//   cout<<list1;
//   return 0;
// }
// // #include <iostream>
// using namespace std;
// #include "mysort.h"
// int main()
// {
//   int arr[] = {2,1,4,3,6,5,9,7,8,0};
//   mysort(arr,0,10);
//   for(int i = 0 ; i < 10; i++)
//     cout<<arr[i]<<",";
//   cout<<endl;
//   return 0;
// }
/*SinglyList*/
#include "Computer.h"
#include "SinglyList.h"
int
main()
{
  Computer c[]={Computer(1,2),Computer(2,16),Computer(1,6),Computer(1,4),Computer(1,8),Computer(2,8)},
    c1(1,2),c2(1,32),c3(1,8),
       c4[]={Computer(1,2),Computer(1,4),Computer(1,8),Computer(2,8)},
       c5[]={Computer(2,8),Computer(2,4),Computer(1,8)};
       SinglyList<Computer> list(c,6);
       SinglyList<Computer> list1;
       cout<<list;
       list1.reverse(list);
       cout<<list;
  return 0;
}
