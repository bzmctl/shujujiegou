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
// #include "Computer.h"
// #include "SinglyList.h"
// int
// main()
// {
//   Computer c[]={Computer(1,2),Computer(2,16),Computer(1,6),Computer(1,4),Computer(1,8),Computer(2,8)},
//     c1(1,2),c2(1,2),c3(1,8),
//        c4[]={Computer(1,2),Computer(1,4),Computer(1,8),Computer(2,8)},
//        c5[]={Computer(2,8),Computer(2,4),Computer(1,8)};
//        SinglyList<Computer> list(c,6);
//        SinglyList<Computer> list1(c4,4);
//        cout<<list;
//        // list1.reverse(list);
//        cout<<list1;
//        list.insert(7,list1);
//        cout<<list;
//   return 0;
// }

//
#include <random>
#include <iostream>
int main()
{
  std::default_random_engine generator(time(0));
  std::uniform_int_distribution<int> distribution(1,100);
  int dice_roll;
  for(int i = 0; i < 16; i++)
    {
      dice_roll = distribution(generator);
      std::cout<<dice_roll<<" ";
    }
  std::cout<<"\n";
  return 0;
}
// #include <iostream>
// #include <stdlib.h>
// int main()
// {
//   int i = 20;
//   while(i > 0)
//     {//伪随机数，每次生成的随机数都一样
//       int num = rand();
//       int result = num % 2;
//       std::cout<<num<<" ";
//       i--;
//     }
//   std::cout<<std::endl;
//   return 0;
// }
/* localtime example */
// #include <stdio.h>      /* puts, printf */
// #include <time.h>       /* time_t, struct tm, time, localtime */

// int main ()
// {
//   time_t rawtime;
//   struct tm * timeinfo;

//   time (&rawtime);
//   timeinfo = localtime (&rawtime);
//   printf ("Current local time and date: %s", asctime(timeinfo));

//   return 0;
// }





// #include <stdlib.h>//rand  
// #include<time.h>//time  
// #include "iostream"//cout  

// using namespace std;  

// #define random(x) (rand() % x)  
// //得到一个随机数对x取余 即得到 0 至 x - 1的随机数  
// //rand()函数本身是返回 0 到 RAND_MAX  RAND_MAX = 32767   
// int main(int argc, char* argv[])  
// {  
//   srand((int)time(0));  
//   //Srand是种下随机种子数，每次种下的种子不一样，用Rand得到的随机数就不一样  
//   //time_t time(time_t *time);  time(0)用来获得1970年1月1日0时0分0秒到当前时间的秒数  
//   for(int i = 0; i < 10; i++)     
//     cout << random(100) << endl;  
//   return 0;  
// }  
