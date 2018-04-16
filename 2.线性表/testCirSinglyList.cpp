#define BOOST_TEST_MODULE cirSinglyList
#include <boost/test/included/unit_test.hpp>
#include "CirSinglyList.h"
#include "Computer.h"

struct F {
  F()
  { 
    // BOOST_TEST_MESSAGE( "setup fixture" );
    Computer 
      first(1,2),
      last(1,32),
      last1(1,16),
      last2(1,128),
      c[] = {Computer(1,2),Computer(1,16),Computer(1,8)},      
      c1[] = {Computer(1,8),Computer(1,16),Computer(1,2),Computer(1,32)},
      c2[] = {Computer(1,64)},
      c3[] = {Computer(1,1),Computer(1,128)},
      c4[] = {Computer(1,2),Computer(1,2),Computer(1,2),Computer(1,4)},
      c5[] = {Computer(1,2),Computer(1,2),Computer(1,2),Computer(1,4)};
      int arr[] = {1,2,3,4,5,6,7,8,9,10,11,102};

      this->first = first;
      this->last = last;
      this->last1 = last1;
      this->last2 = last2;
      null_list = new CirSinglyList<int>();//执行循环单链表无参构造方法，构造空的循环单链表null_list
      list = new CirSinglyList<Computer>(c,3);//由数组c的元素构造循环单链表list
      list1 = new CirSinglyList<Computer>(c1,4);
      list2 = new CirSinglyList<Computer>(c2,1);
      list3 = new CirSinglyList<Computer>(c3,2);
      list4 = new CirSinglyList<Computer>(c4,4);
      list5 = new CirSinglyList<Computer>(c5,4);
      i_list = new CirSinglyList<int>(arr,12);
      
  }
  ~F()
  { 
    //BOOST_TEST_MESSAGE( "teardown fixture" ); 
    delete null_list;
    delete list;
    delete list1;
    delete list2;
    delete list3;
    delete list4;
    delete list5;
    delete i_list;
   
  }

  Computer first,last,last1,last2;
  CirSinglyList<Computer> *list,*list1,*list2,*list3,*list4,*list5;
  CirSinglyList<int> *i_list,*null_list;
};

BOOST_FIXTURE_TEST_SUITE(s, F)

BOOST_AUTO_TEST_CASE(test1_empty_count_get_set)//测试4种函数
{
  BOOST_TEST(null_list->empty());
  BOOST_TEST(list->count()==3);
  BOOST_TEST(list1->count()==4);
  BOOST_TEST(list2->count()==1);
  BOOST_TEST(list3->count()==2);
  BOOST_TEST(list->eq(list->get(0),first));
  list->set(2,first);
  BOOST_TEST(list->eq(list->get(2),first));
}
BOOST_AUTO_TEST_CASE(test2_insert_it_intser_t_remove_i_removeAll_search_T)
{
  list->insert(3,last);
  BOOST_WARN(list->count()==4);
  
  list->insert(last1);
  BOOST_WARN(list->count()==5);
  
  BOOST_WARN(list->eq(list->search(last1)->data,last1));
  Node<Computer> *temp = NULL;
  BOOST_WARN(list->search(last2)==temp);
  
  list->removeAll();
  BOOST_WARN(list->count()==0);
}
BOOST_AUTO_TEST_CASE(test3_iurt_removeFirst)
{
  BOOST_CHECK_THROW(list->iurt(first),out_of_range);//插入重复元素失败，抛出out_of_range异常
  BOOST_CHECK(list->count()!=4);
  list->iurt(last2);
  BOOST_CHECK(list->count()==4);
  list->removeFirst(first);
  BOOST_CHECK(list->count()==3);
  list->removeFirst(last1);
  BOOST_CHECK(list->count()==2);
}
BOOST_AUTO_TEST_CASE(test4_dengdeng)
{
  BOOST_CHECK(!(*list==*list1));
  BOOST_CHECK(*list!=*list1);
}
BOOST_AUTO_TEST_CASE(test5_deepcopyconstruct)
{
  CirSinglyList<Computer> _l(*list);
  BOOST_CHECK(*list==_l);
  *list = *list1;
  BOOST_CHECK(*list == *list1);
}
BOOST_AUTO_TEST_CASE(test6_removeAll_T_replaceFirst_T_T_replaceAll_T_T)
{
  list4->removeAll(first);
  BOOST_CHECK(list4->count() == 1);
  list->replaceFirst(first,last);
  BOOST_CHECK(list->eq(list->get(0),last));
  list5->replaceAll(first,last);
  BOOST_CHECK(list5->eq(list5->get(0),last));
}
BOOST_AUTO_TEST_CASE(test7_first_next_p_previous_p_last)
{
  BOOST_CHECK(list->eq(list->first()->data,first));
  BOOST_CHECK(list->eq(list->last()->data,list1->get(0)));
  Node<Computer> *p = new Node<Computer>(first);
  Node<Computer> *p1 = new Node<Computer>(last);
  BOOST_CHECK(list1->eq(list1->next(p1)->data,list1->head->data));
  BOOST_CHECK(list->eq(list->previous(p)->data,list->head->data));
  
}
BOOST_AUTO_TEST_CASE(test8_isSorted_max_reverse)
{
  BOOST_CHECK(list3->isSorted(true));
  BOOST_CHECK(list->eq(list->max(*list1),last));
  list1->reverse(*list1);
  BOOST_CHECK(list1->eq(list1->get(0),last));
}

BOOST_AUTO_TEST_CASE(test9_sub)
{
  CirSinglyList<Computer> *l;
  l = &(list->sub(0,2));
  Computer c1(1,2),c2(1,16);
  BOOST_CHECK(l->head->next->data == c1);
  BOOST_CHECK(l->head->next->next->data == c2);
  BOOST_CHECK(l->head->next->next->next == l->head);
  delete l;
}

BOOST_AUTO_TEST_CASE(test10_contain)
{
  BOOST_TEST(list1->contain(*list));
  BOOST_TEST(!(list1->contain(*list2)));
}

BOOST_AUTO_TEST_CASE(test11_insert_lianjie)
{//测试insert(i,CirSinglyList<T> &list),将list插入到*this第i个结点之前
  list->insert(4,*list1);
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,last),"测试失败打印此消息！");
}

BOOST_AUTO_TEST_CASE(test12_append)
{
  list->append(*list1);
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,last));
}

BOOST_AUTO_TEST_CASE(test13_jiahao)
{//CirSinglyList<T> CirSinglyList<T>::operator+(CirSinglyList<T> &list)//返回*this与list合并连接后的单链表
  *list+*list1;
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,last));
}

BOOST_AUTO_TEST_CASE(test14_remove)
{//void CirSinglyList<T>::remove(int i,int n)//删除从第i个结点开始，长度为n的子表
  list1->remove(0,3);
  BOOST_TEST(list1->eq(list1->first()->data,last));
  BOOST_TEST(list1->eq(list1->last()->data,last));
  list->remove(1,2);
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,first));
}

BOOST_AUTO_TEST_CASE(test15_jiaoji)
{//CirSinglyList<T>& CirSinglyList<T>::operator*(CirSinglyList<T> &list)//返回*this与list的所有共同元素，交集
  (*list)*(*list1);
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,last1));
}

BOOST_AUTO_TEST_CASE(test16_chaji)
{//void CirSinglyList<T>::operator-=(CirSinglyList<T> &list)//删除那些也包含在list中的元素，差集(即把this中属于list中的元素删掉)
  *list1-=*list;
  BOOST_TEST(list1->eq(list1->first()->data,last));
  BOOST_TEST(list1->eq(list1->last()->data,last));
}

BOOST_AUTO_TEST_CASE(test17_cha)
{//CirSinglyList<T> CirSinglyList<T>::operator-(CirSinglyList<T> &list)//返回*this与list的差集
  *list1-*list;
  BOOST_TEST(list1->eq(list1->first()->data,last));
  BOOST_TEST(list1->eq(list1->last()->data,last));
}

BOOST_AUTO_TEST_CASE(test18_retainAll)
{//void CirSinglyList<T>::retainAll(CirSinglyList<T> &list)//仅保留那些也包含在list中的元素
  list->retainAll(*list1);
  BOOST_TEST(list->eq(list->first()->data,first));
  BOOST_TEST(list->eq(list->last()->data,last1));
}

//CirSinglyList<T>* CirSinglyList<T>::search(CirSinglyList<T> &list)//判断*this是否包含与list匹配的子表
BOOST_AUTO_TEST_CASE(test19_search_zibiao)
{
  list1->search(*list);
  BOOST_TEST(list1->eq(list1->first()->data,first));
  BOOST_TEST(list1->eq(list1->last()->data,last1));
}

//void CirSinglyList<T>::removeAll(CirSinglyList<T> list)//删除*this中所有与list匹配的子表
BOOST_AUTO_TEST_CASE(test20_removeAll_list)
{
  list1->removeAll(*list);
  BOOST_TEST(list1->eq(list1->first()->data,last));
  BOOST_TEST(list1->eq(list1->last()->data,last));
}
//void CirSinglyList<T>::replaceAll(CirSinglyList<T> listkey,CirSinglyList<T> listx)//将所有与listkey匹配子表替换为listx
BOOST_AUTO_TEST_CASE(test21_replaceAll_listkey_to_listx)
{
  list1->replaceAll(*list,*list3);
  BOOST_TEST(list1->eq(list1->first()->data,last));
  BOOST_TEST(list1->eq(list1->last()->data,last2));
}

BOOST_AUTO_TEST_CASE(test22_random)
{
  list1->random();
  BOOST_CHECK(!list1->eq(list1->get(0),list1->get(1)) || 
	      !list1->eq(list1->get(1),list1->get(2)) || 
	      !list1->eq(list1->get(2),list1->get(3))
	      );
}

BOOST_AUTO_TEST_CASE(test23_average)
{
  double res = i_list->average(*i_list);
  BOOST_CHECK_EQUAL(res,14);
  double res1 = i_list->averageExceptMaxMin(*i_list);
  BOOST_CHECK_EQUAL(res1,6.5);
}

BOOST_AUTO_TEST_SUITE_END()
