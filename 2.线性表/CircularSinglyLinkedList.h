template <class T>
class CircularSinglyLinkedList:public SortedSinglyList<T>
{
 public:
  CircularSinglyLinkedList(SinglyList<T> &list,bool asc);
  //创建循环单链表
  void ccsll();
  void print();
};
template <class T>
CircularSinglyLinkedList<T>::CircularSinglyLinkedList(SinglyList<T> &list,bool asc):SortedSinglyList<T>(list,asc){}
template <class T>
void CircularSinglyLinkedList<T>::ccsll()
{
    Node<T>* front = this->head;
    while(front->next !=NULL)
      front = front->next;
    front->next = this->head;
}

template <class T>
void CircularSinglyLinkedList<T>::print()
{
  cout<<"(";
  Node<T>* p = this->head;
  while(p->next != this->head)
    {
      p = p->next;
      cout<<p->data;
      if(p->next != NULL)
	cout<<",";
    }
  cout<<")\n";
}
