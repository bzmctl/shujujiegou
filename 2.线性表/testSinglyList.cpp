#define BOOST_TEST_MODULE singlyList
#include <boost/test/included/unit_test.hpp>
#include "SinglyList.h"
#include "Computer.h"

struct F {
  F()
  { 
    BOOST_TEST_MESSAGE( "setup fixture" );
    Computer 
      first(1,2),
      last(1,32),
      last1(1,16),
      last2(1,128),
      c[] = {Computer(1,2),Computer(1,16),Computer(1,8)},      
      c1[] = {Computer(1,8),Computer(1,16),Computer(1,2),Computer(1,32)},
      c2[] = {Computer(1,64)},
      c3[] = {Computer(1,1),Computer(1,128)};
      int arr[] = {1,2,3,4,5,6,7,8,9,10,11,102};

      this->first = first;
      this->last = last;
      this->last1 = last1;
      this->last2 = last2;
      list = new SinglyList<Computer>(c,3);
      list1 = new SinglyList<Computer>(c1,4);
      list2 = new SinglyList<Computer>(c2,1);
      list3 = new SinglyList<Computer>(c3,2);
      i_list = new SinglyList<int>(arr,12);
  }
  ~F()
  { 
    BOOST_TEST_MESSAGE( "teardown fixture" ); 
    delete list;
    delete list1;
    delete list2;
    delete list3;
    delete i_list;
  }

  Computer first,last,last1,last2;
  SinglyList<Computer> *list,*list1,*list2,*list3;
  SinglyList<int> *i_list;
};

BOOST_FIXTURE_TEST_SUITE(s, F)

BOOST_AUTO_TEST_CASE(test_average)
{
  double res = i_list->average(*i_list);
  BOOST_CHECK_EQUAL(res,14);
  double res1 = i_list->averageExceptMaxMin(*i_list);
  BOOST_CHECK_EQUAL(res1,6.5);
}

BOOST_AUTO_TEST_CASE(test_sub)
{
  SinglyList<Computer> *l;
  l = &(list->sub(0,2));
  Computer c1(1,2),c2(1,16);
  BOOST_CHECK(l->head->next->data == c1);
  BOOST_CHECK(l->head->next->next->data == c2);
  BOOST_CHECK(l->head->next->next->next == NULL);
  delete l;
}

BOOST_AUTO_TEST_CASE(test_contain)
{
  BOOST_TEST(list1->contain(*list));
}

BOOST_AUTO_TEST_CASE(test_contain1)
{
  BOOST_TEST(!(list1->contain(*list2)));
}

BOOST_AUTO_TEST_CASE(test_insert_lianjie)
{//测试insert(i,SinglyList<T> &list),将list插入到*this第i个结点之前
  list->insert(4,*list1);
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,last),"测试失败打印此消息！");
}

BOOST_AUTO_TEST_CASE(test_append)
{
  list->append(*list1);
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,last));
}

BOOST_AUTO_TEST_CASE(test_jiahao)
{//SinglyList<T> SinglyList<T>::operator+(SinglyList<T> &list)//返回*this与list合并连接后的单链表
  *list+*list1;
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,last));
}

BOOST_AUTO_TEST_CASE(test_remove)
{//void SinglyList<T>::remove(int i,int n)//删除从第i个结点开始，长度为n的子表
  list1->remove(0,3);
  BOOST_TEST(list1->eq(list1->first()->data,last));
  BOOST_TEST(list1->eq(list1->last()->data,last));
  list->remove(1,2);
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,first));
}

BOOST_AUTO_TEST_CASE(test_jiaoji)
{//SinglyList<T>& SinglyList<T>::operator*(SinglyList<T> &list)//返回*this与list的所有共同元素，交集
  (*list)*(*list1);
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,last1));
}

BOOST_AUTO_TEST_CASE(test_chaji)
{//void SinglyList<T>::operator-=(SinglyList<T> &list)//删除那些也包含在list中的元素，差集(即把this中属于list中的元素删掉)
  *list1-=*list;
  BOOST_TEST(list1->eq(list1->first()->data,last));
  BOOST_TEST(list1->eq(list1->last()->data,last));
}

BOOST_AUTO_TEST_CASE(test_cha)
{//SinglyList<T> SinglyList<T>::operator-(SinglyList<T> &list)//返回*this与list的差集
  *list1-*list;
  BOOST_TEST(list1->eq(list1->first()->data,last));
  BOOST_TEST(list1->eq(list1->last()->data,last));
}

BOOST_AUTO_TEST_CASE(test_retainAll)
{//void SinglyList<T>::retainAll(SinglyList<T> &list)//仅保留那些也包含在list中的元素
  list->retainAll(*list1);
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,last1));
}
//SinglyList<T>* SinglyList<T>::search(SinglyList<T> &list)//判断*this是否包含与list匹配的子表
BOOST_AUTO_TEST_CASE(test_search_zibiao)
{
  list1->search(*list);
  BOOST_TEST(list1->eq(list1->first()->data,first));
  BOOST_TEST(list1->eq(list1->last()->data,last1));
}
//void SinglyList<T>::removeAll(SinglyList<T> list)//删除*this中所有与list匹配的子表
BOOST_AUTO_TEST_CASE(test_removeAll_list)
{
  list1->removeAll(*list);
  BOOST_TEST(list1->eq(list1->first()->data,last));
  BOOST_TEST(list1->eq(list1->last()->data,last));
}
//void SinglyList<T>::replaceAll(SinglyList<T> listkey,SinglyList<T> listx)//将所有与listkey匹配子表替换为listx
BOOST_AUTO_TEST_CASE(test_replaceAll_listkey_to_listx)
{
  list1->replaceAll(*list,*list3);
  BOOST_TEST(list1->eq(list1->first()->data,last));
  BOOST_TEST(list1->eq(list1->last()->data,last2));
}

BOOST_AUTO_TEST_CASE(test_random)
{
  cout<<*list1;
  list1->random();
  cout<<*list1;
}
BOOST_AUTO_TEST_SUITE_END()
