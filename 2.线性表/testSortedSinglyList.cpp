#define BOOST_TEST_MODULE sortedsinglyList
#include <boost/test/included/unit_test.hpp>
#include "SortedSinglyList.h"
#include "TermX.h"

struct F {
  F()
  { 
    list = new SortedSinglyList<TermX>();
  }
  ~F()
  { 
    delete list;
  }

  SortedSinglyList<TermX> *list;
};

BOOST_FIXTURE_TEST_SUITE(s, F)

BOOST_AUTO_TEST_CASE(test_gouzao)
{
  cout<<list;
}
BOOST_AUTO_TEST_SUITE_END()
