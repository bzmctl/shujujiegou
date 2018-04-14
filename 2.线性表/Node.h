#include <stddef.h>
template <class T>
class Node{                        //单链表节点类，T指定节点的元素类型
 public:
  T data;                                      //数据域，保存数据元素
  Node<T> *next;                   //地址域（指针域），指向后继节点
  Node()                                      //构造节点，data域未初始化
    {
      this->next = NULL;           //指针赋值
    }

  Node(T data,Node<T> *next= NULL)  //构造节点，data指定数据元素，next指定后继节点地址，默认空值
    {
      this->data = data;           //执行T的赋值运算
      this->next = next;           //指针赋值
    }
};
