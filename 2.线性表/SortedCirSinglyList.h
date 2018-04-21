template <typename T>
class SortedCirSinglyList:public CirSinglyList<T>
{
 public:
  SortedCirSinglyList();                                        //构造空排序循环单链表
  SortedCirSinglyList(T values[],int n);                        //构造排序循环单链表，由values数组提供元素
  ~SortedCirSinglyList();                                       //析构函数
  // bool empty();                                           //判断排序循环单链表是否为空
  // int count();                                            //返回排序循环单链表长度
  // T& get(int i);                                          //返回第i(i>=0)个元素的引用
  void set(int i,T x);                            //设置第i（i>=0）个元素的值为x
  // template <typename K> friend ostream& operator<<(ostream&,SortedCirSinglyList<K>&);    //输出排序循环单链表所有元素
  //  Node<T>* insert(int i,T x);                             //插入x作为第i个结点，返回插入结点的地址
  //  virtual Node<T>* insert(T x);                           //在排序循环单链表最后插入x，虚函数
  // T remove(int i);                                        //删除第i(i>=0)个结点，返回被删除元素
  // void removeAll();                                       //清空排序循环单链表
  // Node<T>* search(T key);                                 //顺序查找首先出现关键字为key的元素，返回结点地址；若未找到返回NULL。T必须重载==运算，约定比较两个元素(==)的规则
  //  virtual Node<T>* iurt(T x);               //尾插入不重复元素,返回插入结点地址(virtual的作用:当子类有新的不同实现时，调用子类实现的方法)
  //virtual void removeFirst(T key);                        //删除首次出现的元素值为key的结点
  // bool operator==(SortedCirSinglyList<T> &list);                //比较两条排序循环单链表是否相等
  //bool operator!=(SortedCirSinglyList<T> &list);                //比较两条排序循环单链表是否不相等
  //SortedCirSinglyList(SortedCirSinglyList<T> &list);                  //拷贝构造函数，深拷贝
  //SortedCirSinglyList<T>& operator=(SortedCirSinglyList<T> &list);    //重载=赋值运算符，深拷贝
  void operator+=(SortedCirSinglyList<T> &list);        //将list链接在当前链表之后;虚函数
  // void removeAll(T key);                                  //删除所有关键字为key的元素;要求元素一次移动到位
  // void replaceFirst(T key,T x);                           //将首次出现的关键字为key的元素替换为x
  //void replaceAll(T key,T x);                              //将所有关键字为key的元素替换为x
  // Node<T>* first();                                       //返回排序循环单链表第0个元素结点(非头结点)
  // Node<T>* next(Node<T> *p);                              //返回p的后继结点
  //Node<T>* previous(Node<T> *p);                           //返回p的前驱结点
  // Node<T>* last();                                        //返回排序循环单链表最后一个结点
  // bool isSorted(bool asc=true);                           //判断是否已排序，asc指定升序或降序
  // T max(SortedCirSinglyList<T> &list);                          //返回list排序循环单链表最大值，T必须重载>
  // void reverse(SortedCirSinglyList<T> &list);                   //将排序循环单链表逆转
  // SortedCirSinglyList<T>& sub(int i,int n);                     //返回从第i个结点开始，长度为n的子表
  bool contain(SortedCirSinglyList<T> &list);                   //判断*this排序循环单链表是否包含list所有结点
  void insert(int i,SortedCirSinglyList<T> &list);              //复制list所有结点插入到*this第i个结点前
  void append(SortedCirSinglyList<T> &list);                    //将list中所有结点复制添加到*this最后
  SortedCirSinglyList<T> operator+(SortedCirSinglyList<T> &list);     //返回*this与list合并连接后的排序循环单链表
  //void remove(int i,int n);                               //删除从第i个结点开始，长度为n的子表
  SortedCirSinglyList<T>& operator*(SortedCirSinglyList<T> &list);    //返回*this与list的所有共同元素，交集
  void operator-=(SortedCirSinglyList<T> &list);                //删除那些也包含在list中的元素，差集
  SortedCirSinglyList<T> operator-(SortedCirSinglyList<T> &list);     //返回*this与list的差集
  void retainAll(SortedCirSinglyList<T> &list);                 //仅保留那些也包含在list中的元素
  SortedCirSinglyList<T>* search(SortedCirSinglyList<T> &list);       //判断*this是否包含与list匹配的子表
  void removeAll(SortedCirSinglyList<T> list);                  //删除*this中所有与list匹配的子表
  void replaceAll(SortedCirSinglyList<T> listkey,SortedCirSinglyList<T> listx);//将所有与listkey匹配子表替换为listx
  //void random();                                        //将排序循环单链表元素随即排列
  //  bool eq(T a, T b);                                      //测试函数
  // double average(CirSinglyList<T> &list);                 //计算整数循环单链表的平均值
  //  double averageExceptMaxMin(CirSinglyList<T> &list);     //去掉最高分和最低分求平均值
};
template <typename T>
SortedCirSinglyList<T>::SortedCirSinglyList()
{
  cout<<"SortedCirSinglyList()被调用！\n";
}
template <typename T>
SortedCirSinglyList<T>::SortedCirSinglyList(T values[],int n)
{
  quickSort(values,0,n-1);  //values 排序
  cout<<"带参构造方法被执行！\n";
  Node<T> * rear = this->head; 
  for(int i = 0; i < n; i++)   
    {
      rear->next = new Node<T>(values[i],rear->next);  //创建结点链入rear结点之后
      rear = rear->next;//去掉这句，则构造的是反序排序循环单链表
    }
}
template <typename T>
SortedCirSinglyList<T>::~SortedCirSinglyList()
{
  cout<<"~SortedCirSinglyList()被调用！\n";
}
template <typename T>
void SortedCirSinglyList<T>::set(int i, T x)
{
  throw runtime_error("不允许设置排序循环单链表的值！");
}
template <typename T>
void SortedCirSinglyList<T>::operator+=(SortedCirSinglyList<T> &list)
{
  SortedCirSinglyList<T> *_l = new SortedCirSinglyList<T>();
  Node<T> *p = this->head,*q = list.head,*temp = _l->head;
  if(q->next == q)
    return ;
  while(p->next != this->head && q->next != list.head)
    {
      if(p->next->data <= q->next->data)
	{
	  temp->next = p->next;  //temp指针域指向小的结点
	  temp = p->next;  //temp指针后移
	  p = p->next;  //p指针后移
	}
      else
	{
	  temp->next = q->next;
	  temp = q->next;
	  q = q->next;
	}
    }
  if(p->next != this->head)
    {
      temp->next = p->next;
      this->last()->next = _l->head;
    }
  else if(q->next != list.head)
    {
      temp->next = q->next;
      list.last()->next = _l->head;
    }
  
  if(this->head != this->head->next)
    this->removeAll();
  *this = *_l;//将临时链表赋值给this
  delete _l;
}
template <typename T>
bool SortedCirSinglyList<T>::contain(SortedCirSinglyList<T> &list)
{
  throw runtime_error("不允许设置排序循环单链表的值！");
}
template <typename T>
void SortedCirSinglyList<T>::insert(int i,SortedCirSinglyList<T> &list)
{
  throw runtime_error("不允许插入操作！");
}
template <typename T>
void SortedCirSinglyList<T>::append(SortedCirSinglyList<T> &list)
{
  throw runtime_error("不允许追加操作");
}
template <typename T>
SortedCirSinglyList<T> SortedCirSinglyList<T>::operator+(SortedCirSinglyList<T> &list)
{
  throw runtime_error("不允许+操作！");
}
template <typename T>
SortedCirSinglyList<T>& SortedCirSinglyList<T>::operator*(SortedCirSinglyList<T> &list)
{
  throw runtime_error("不允许*操作！");
}
template <typename T>
void SortedCirSinglyList<T>::operator-=(SortedCirSinglyList<T> &list)
{
  throw runtime_error("不允许-=操作！");
}
template <typename T>
SortedCirSinglyList<T> SortedCirSinglyList<T>::operator-(SortedCirSinglyList<T> &list)
{
  throw runtime_error("不允许-操作！");
}
template <typename T>
void SortedCirSinglyList<T>::retainAll(SortedCirSinglyList<T> &list)
{
  throw runtime_error("同*操作，不允许！");
}
template <typename T>
SortedCirSinglyList<T>* SortedCirSinglyList<T>::search(SortedCirSinglyList<T> &list)
{
  throw runtime_error("同*操作，不允许！");
}
template <typename T>
void SortedCirSinglyList<T>::removeAll(SortedCirSinglyList<T> list)
{
  throw runtime_error("同-操作，不允许！");
}
template <typename T>  
void SortedCirSinglyList<T>::replaceAll(SortedCirSinglyList<T> listkey,SortedCirSinglyList<T> listx)
{
  throw runtime_error("同-，追加操作，不允许！");
}
