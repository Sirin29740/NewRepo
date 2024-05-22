#include<iostream>
using  namespace  std;
template  <class  ElemType>
class  MyLinkList;    //����������
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
    friend  class  MyLinkList<ElemType>;          //��Ԫ˵��
private:
    ElemType    data;//ֵ
    Node<ElemType>* next;//ָ����һ���ڵ��ָ��
};
template  <class  ElemType>
class  MyLinkList {
private:
    unsigned  int  listlength;
    Node<ElemType>* pTemp;//��ʱ�ڵ�
    Node<ElemType>* pTail;//ͷ���
    Node<ElemType>* pHead;//β�ڵ�
public:
    MyLinkList();//��ʼ��
    void  addAtTail(ElemType    x);//��β���Ԫ��
    void  traversal();//��������������ӡ
    //�ú�����ͬѧ���
    void  Delete(ElemType  x);//ɾ����һ��ֵΪx�Ľڵ�
    void  insertHead(ElemType    x);//�������ͷ������ڵ�
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
    pTemp = new  Node<ElemType>(x);//����һ���µĽڵ�
    if (pTail == NULL)//���û��β�ڵ�������Ϊ��,pTemp��Ϊͷ���,����β�ڵ�
    {
        pHead = pTemp;
        pTail = pTemp;
    }
    else//�������ǿ�
    {
        pTail->next = pTemp;//pTemp��Ϊβ�ڵ����һ���ڵ�
        pTail = pTemp;//pTemp�����β�ڵ�,��β�ڵ㸳ֵΪpTemp
    }
    ++listlength;//Ԫ�ظ���+1
}
template  <class  ElemType>
void  MyLinkList<ElemType>::traversal()
{
    pTemp = pHead;//����ʱ�ڵ�ָ��ͷ���
    while (pTemp != NULL)//�����������
    {
        cout << pTemp->data << "   ";      //""�������ո�
        pTemp = pTemp->next;
    }
    cout << endl;
}
//�ú�������Ϊɾ��ֵΪx�ĵ�һ����㣬��ͬѧ��ɣ��ɲο�֮ǰ�ĸĴ���ҵ
template <class ElemType>
void MyLinkList<ElemType>::Delete(ElemType x)
{
    bool found = false;
    Node<ElemType>* prev = nullptr;
    pTemp = pHead;

    // Ѱ��Ҫɾ���Ľڵ�
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

    if (!found) // û���ҵ�Ҫɾ���Ľڵ�
        return;

    if (prev == nullptr) // Ҫɾ���Ľڵ���ͷ�ڵ�
    {
        pHead = pHead->next;
        if (pHead == nullptr) // �������ֻ��һ���ڵ�
            pTail = nullptr;
    }
    else
    {
        prev->next = pTemp->next;
        if (prev->next == nullptr) // ���ɾ������β�ڵ�
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
//����==���������,ע��ɾ������ID��ͬ�Ľ��
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