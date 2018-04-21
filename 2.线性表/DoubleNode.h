template <class T>
class DoubleNode
{
 public:
  T data;
  DoubleNode<T> *prev,*next;

  DoubleNode()
    {
      this->prev = this->next = NULL;
    }
  DoubleNode(T data,DoubleNode<T> *prev=NULL,DoubleNode<T> *next=NULL)
    {
      this->data = data;  //执行T的=赋值运算
      this->prev = prev;
      this->next = next;
    }
  //注意：DoubleNode构造函数有两个缺省参数，当只有一个参数时，意为后一个参数缺省
  //如：DoubleNode<T> *p = new DoubleNode<T>(x,front);  //front指向前驱结点，后继结点为空
};
