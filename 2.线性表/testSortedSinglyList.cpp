#define BOOST_TEST_MODULE sortedsinglyList
#include <boost/test/included/unit_test.hpp>
#include "SortedSinglyList.h"
#include "TermX.h"

struct F {
  F()
  { 
    // cout<<list<<endl;
    // cout<<list1<<endl;
    // cout<<list3<<endl;
    list = new SortedSinglyList<TermX>();
    TermX values[] ={TermX(2,5),TermX(3,3),TermX(1,2)};
    list1 = new SortedSinglyList<TermX>(values,3);
    //由单链表构造有序单链表
    SinglyList<TermX> slist(values,3);//存储在栈中
    list3 = new SortedSinglyList<TermX>(slist,false);
   
  }
  ~F()
  { 
    if(list != NULL)
      {
	delete list;
	list = NULL;
      }
    if(list1 != NULL)
      {
	delete list1;
	list1 = NULL;
      }
    if(list3 != NULL)
      {
    	delete list3;
    	list3 = NULL;
      }
  }
  SortedSinglyList<TermX> *list = NULL,*list1 = NULL,*list3 = NULL;
};

BOOST_FIXTURE_TEST_SUITE(s, F)

BOOST_AUTO_TEST_CASE(test_gouzao)
{
  cout<<"list="<<list;
  cout<<"list1="<<list1;
  cout<<"list3="<<list3;
}
BOOST_AUTO_TEST_CASE(test_insertUnrepeatable)
{
  TermX t(5,6);
  list3->insertUnrepeatable(t);
  cout<<"list3="<<list3;
}
BOOST_AUTO_TEST_CASE(test_removeFirst)
{
  TermX t(5,6);
  list3->removeFirst(t);
  cout<<"list3="<<list3;
}
BOOST_AUTO_TEST_SUITE_END()
