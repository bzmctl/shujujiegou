#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>

int add(int i,int j){return i+j;};

BOOST_AUTO_TEST_SUITE(minimal_test)

BOOST_AUTO_TEST_CASE(my_test)
{
  BOOST_CHECK(add(2,2) ==5 );
  BOOST_REQUIRE(add(2,2) == 4);
  if(add(2,2) != 4)
    BOOST_ERROR("boost_error oops!");
  if(add(2,2) != 4)
    BOOST_FAIL("boost_fail oops!");
  if(add(2,2) != 4)//此种方式，后面代码不会执行
    throw "throw oops!";
  BOOST_CHECK_MESSAGE(add(2,2) ==4,"add(..) result:"<<add(2,2));
  BOOST_CHECK_EQUAL(add(2,2),5);
}

BOOST_AUTO_TEST_SUITE_END( )
//REQUIRE，FAIL，throw 方式，后续代码不会执行
