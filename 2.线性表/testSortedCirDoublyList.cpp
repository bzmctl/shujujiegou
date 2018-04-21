#define BOOST_TEST_MODULE sortedcirdoublylist
#include <boost/test/included/unit_test.hpp>
#include "SortedCirDoublyList.h"
#include "Computer.h"
struct F
{
  F()
  {
    Computer c[] = {Computer(1,8),Computer(1,1),Computer(2,4),Computer(1,4),Computer(4,8)};
    list = new SortedCirDoublyList<Computer>(c,5);
  }
  ~F()
  {
    delete list;
  }
  SortedCirDoublyList<Computer> *list;
  
};
BOOST_FIXTURE_TEST_SUITE(s,F)
BOOST_AUTO_TEST_CASE(test)
{
  cout<<*list;
}
BOOST_AUTO_TEST_SUITE_END()
