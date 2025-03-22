#include<iostream>
using  namespace  std;
template  <class  ElemType>
class  MyLinkList;    //链表类声明
template  <class  ElemType>
class  Node {
public:
    Node()
    {
        next = NULL;
    }

    Node(ElemType  val)
    {
        data = val;
        next = NULL;
    }
    friend  class  MyLinkList<ElemType>;          //友元说明
private:
    ElemType    data;//值
    Node<ElemType>* next;//指向下一个节点的指针
};
template  <class  ElemType>
class  MyLinkList {
private:
    unsigned  int  listlength;
    Node<ElemType>* pTemp;//临时节点
    Node<ElemType>* pTail;//头结点
    Node<ElemType>* pHead;//尾节点
public:
    MyLinkList();//初始化
    void  addAtTail(ElemType    x);//表尾添加元素
    void  traversal();//遍历整个链表并打印
    //该函数请同学完成
    void  Delete(ElemType  x);//删除第一个值为x的节点
    void  insertHead(ElemType    x);//在链表的头部插入节点
};
template  <class  ElemType>
MyLinkList<ElemType>::MyLinkList()
{
    pTemp = NULL;
    pTail = NULL;
    pHead = NULL;
    listlength = 0;
}
template  <class  ElemType>
void  MyLinkList<ElemType>::addAtTail(ElemType    x)
{
    pTemp = new  Node<ElemType>(x);//申请一个新的节点
    if (pTail == NULL)//如果没有尾节点则链表为空,pTemp既为头结点,又是尾节点
    {
        pHead = pTemp;
        pTail = pTemp;
    }
    else//如果链表非空
    {
        pTail->next = pTemp;//pTemp既为尾节点的下一个节点
        pTail = pTemp;//pTemp变成了尾节点,把尾节点赋值为pTemp
    }
    ++listlength;//元素个数+1
}
template  <class  ElemType>
void  MyLinkList<ElemType>::traversal()
{
    pTemp = pHead;//用临时节点指向头结点
    while (pTemp != NULL)//遍历链表并输出
    {
        cout << pTemp->data << "   ";      //""内三个空格
        pTemp = pTemp->next;
    }
    cout << endl;
}
//该函数功能为删除值为x的第一个结点，请同学完成，可参考之前的改错作业
template <class ElemType>
void MyLinkList<ElemType>::Delete(ElemType x)
{
    bool found = false;
    Node<ElemType>* prev = nullptr;
    pTemp = pHead;

    // 寻找要删除的节点
    while (pTemp != nullptr && !found)
    {
        if (pTemp->data == x)
            found = true;
        else
        {
            prev = pTemp;
            pTemp = pTemp->next;
        }
    }

    if (!found) // 没有找到要删除的节点
        return;

    if (prev == nullptr) // 要删除的节点是头节点
    {
        pHead = pHead->next;
        if (pHead == nullptr) // 如果链表只有一个节点
            pTail = nullptr;
    }
    else
    {
        prev->next = pTemp->next;
        if (prev->next == nullptr) // 如果删除的是尾节点
            pTail = prev;
    }

    delete pTemp;
    --listlength;
}

template  <class  ElemType>
void  MyLinkList<ElemType>::insertHead(ElemType    x)
{
    pTemp = new  Node<ElemType>(x);
    if (pTail == NULL)
        pTail = pTemp;
    pTemp->next = pHead;
    pHead = pTemp;
}
class  Student
{
public:
    Student(int  id = 0, int  height = 0)
    {
        this->ID = id;
        this->Height = height;
    }
    bool    operator  ==(Student& a2);
    friend  ostream& operator  <<(ostream& out, const  Student& s)
    {
        out << "ID:" << s.ID << "  Height:" << s.Height;
        return  out;
    }
private:
    int  ID;
    int  Height;
};
//重载==运算符函数,注意删除的是ID相同的结点
bool Student::operator==(Student& a2)
{
    return ID == a2.ID;
}

int  main()
{
    MyLinkList<int>  list1;
    for (int i = 0; i < 10; i++)
        list1.insertHead(i);
    list1.insertHead(9);
    list1.insertHead(9);
    list1.insertHead(9);
    list1.traversal();
    list1.Delete(9);
    list1.traversal();
    MyLinkList<Student>  list2;
    list2.insertHead(Student(1, 174));
    list2.addAtTail(Student(2, 176));
    list2.addAtTail(Student(3, 173));
    list2.traversal();
    list2.Delete(Student(1, 174));
    list2.traversal();
    return  0;
}