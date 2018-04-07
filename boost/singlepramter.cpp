/*单参数测试用例*/
/*有时候需要对一个测试用例使用不同的参数运行测试，前面提到的BOOST_AUTO_TEST_CASE不能满足需求，此时需要对测试用例进行手动注册（来自Boost文档）：*/
#include <boost/test/included/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>

using namespace boost::unit_test;

void free_test_function(int i)
{
  BOOST_CHECK(i < 4/*test assertion*/);
}

test_suite* init_unit_test_suite(int argc,char* argv[])
{
  int params[] = {1,2,3,4,5};
  framework::master_test_suite().add(BOOST_PARAM_TEST_CASE(&free_test_function,params,params+5));
  return 0;
}
/*示例代码将会分别以参数1、2、3、4、5运行测试free_test_function五次。
手动注册需要定义测试函数，此处为free_test_function，然后定义init_unit_test_suite函数，并在该函数中将测试用例加入到主测试套件中。
BOOST_PARAM_TEST_CASE有三个参数：第一个参数为测试函数指针，第二个与第三个为输入参数迭代器。*/
