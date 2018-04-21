#define BOOST_TEST_MODULE sortedcirsinglylist
#include <boost/test/included/unit_test.hpp>
#include "CirSinglyList.h"
#include "SortedCirSinglyList.h"
#include "Computer.h"
struct F
{
  F()
    {
      cout<<"------------------------------------------------\n";
      Computer c[] = {Computer(1,1),Computer(1,16),Computer(2,4),Computer(1,8)},
	c1[] = {Computer(4,8),Computer(4,16)};
      list = new SortedCirSinglyList<Computer>();  //构造空的排序循环单链表
      list1 = new SortedCirSinglyList<Computer>(c,4);
      list2 = new SortedCirSinglyList<Computer>(c1,2);
    }
  ~F()
    {
      delete list;
      delete list1;
      delete list2;
      cout<<"=================================================\n";
    }
  CirSinglyList<Computer> *list,*list1,*list2;
};

BOOST_FIXTURE_TEST_SUITE(s,F)
BOOST_AUTO_TEST_CASE(test_1)
{
  BOOST_CHECK(list->empty());
  BOOST_CHECK(list->count() == 0);
}
BOOST_AUTO_TEST_CASE(test_2)
{
  *list1+=*list2;
  cout<<*list1;
}
BOOST_AUTO_TEST_CASE(test_3)
{
  // list2 = list1;
  cout<<*list2;
}
BOOST_AUTO_TEST_SUITE_END()
