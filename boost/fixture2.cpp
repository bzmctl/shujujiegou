#define BOOST_TEST_MODULE fixture_02
#include <boost/test/included/unit_test.hpp>

struct F {
  F() : i( 0 ) { BOOST_TEST_MESSAGE( "setup fixture" ); }
  ~F()         { BOOST_TEST_MESSAGE( "teardown fixture" ); }

  int i;
};

BOOST_FIXTURE_TEST_SUITE(s, F)

  BOOST_AUTO_TEST_CASE(test_case1)
  {
    BOOST_TEST_MESSAGE("running test_case1");
    BOOST_TEST(i == 0);
  }

  BOOST_AUTO_TEST_CASE(test_case2)
  {
    BOOST_TEST_MESSAGE("running test_case2");
    BOOST_TEST(i == 0);
  }

BOOST_AUTO_TEST_SUITE_END()
