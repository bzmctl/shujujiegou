#include "SeqList.h"

#include "Student.h"  //学生信息统计

//约瑟夫环
void josephus(int number,int start,int distance)
{
  SeqList<char> list;
  int i = 0;
  for(int i = 0; i < number; i++)
    list.insert('A'+i);                          //在顺序表后添加元素，O(1)
  cout<<"Josephus环("<<number<<","<<start<<","<<distance<<")"<<list;
  i = start;
  while( list.count() > 1)
    {
      i = (i+distance-1)%list.count();
      cout<<"删除"<<list.remove(i)<<","<<list;
    }
  cout<<"被赦免者是"<<list[0]<<endl;
}

void groupCount(SeqList<Student> &list,int grade[],int n,int result[])
{
  for(int i = 0; i < list.count(); i++)
    {
      Student stu = list[i];
      for(int j=0;j<n-1;j++)
	{
	  if(stu.score>=grade[j] && stu.score<grade[j+1])
	    {	   
	      result[j]++;
	      break;
	    }
	}
    }
}
void tjxx()
{
  Student group[]={{"111",56},{"22",71},{"33",69},{"44",98},{"55",89},{"66",85},{"77",90}};
  SeqList<Student> list(group,7);
  int grade[]={0,60,70,80,90,100};
  const int N=5;
  int result[N]={0};
  const char* str[]={"不及格","及格","中等","良好","优秀"};
  groupCount(list,grade,6,result);
  cout<<"学生集合"<<list;
  cout<<"共"<<list.count()<<"人,成绩统计：";
  for(int i=0;i<N;i++)
    cout<<str[i]<<result[i]<<"人,";
  cout<<endl;
  Student key = {"66",0};
  cout<<"查找"<<key<<"结果："<<list[list.search(key)]<<endl;
}
int
main()
{
      josephus(26,13,6);
  tjxx();
  return 0;
}
