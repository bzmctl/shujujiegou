#define BOOST_TEST_MODULE singlyList
#include <boost/test/included/unit_test.hpp>
#include "SinglyList.h"
#include "Computer.h"

struct F {
  F()
  { BOOST_TEST_MESSAGE( "setup fixture" );
    Computer c[] = {Computer(1,2),Computer(1,4),Computer(1,8)};
    list = new SinglyList<Computer>(c,3);
  }
  ~F()
  { BOOST_TEST_MESSAGE( "teardown fixture" ); 
    delete list;
  }
  
  SinglyList<Computer> *list;
};

BOOST_FIXTURE_TEST_SUITE(s, F)

BOOST_AUTO_TEST_CASE(test_case1)
{
  SinglyList<Computer> *l = list->sub(0,2);
  Computer c1(1,2),c2(1,4);
  BOOST_TEST_MESSAGE("running test_case1");
  BOOST_CHECK(l->head->next->data == c1);
  BOOST_CHECK(l->head->next->next->data == c2);
  BOOST_CHECK(l->head->next->next->next == NULL);
}

BOOST_AUTO_TEST_CASE(test_case2)
{
  BOOST_TEST_MESSAGE("running test_case2");
  BOOST_TEST(1==1);
}

BOOST_AUTO_TEST_SUITE_END()
