#include  <iostream>
#include  <string>
using  namespace  std;
class  Node
{
public:
    Node(int  id, string  name);              //定义编号和姓名
    void  showMessage();                            //输出数据
    friend class LinkList;
    //把Linklist作为自己的友元类
protected:
    int  mId;                                                    //编号
    string  mName;                                        //姓名
    Node* next;                                              //指针指向下一个
};
Node::Node(int  id, string  name)                                      //接受编号和姓名
{
    this->mId = id;
    this->mName = name;
    this->next = NULL;
}

void  Node::showMessage()                                                    //输出数据  
{
    cout << this->mId << "  " << this->mName << endl;
}
class  LinkList
{
public:
    LinkList()
    {
        head = NULL;
    }
    void addNodeAtHead(int i, string name);
    void addNodeAtTail(int i, string name);
    void print();
    void insertNode(int i, string name);
    void deleteNode(int ID);
protected:
    Node* head;                                                                  //指针指向头
};
void LinkList::addNodeAtHead(int i, string name)
{
    Node* p = new Node(i, name);
    if (head == NULL)head = p;
    else
    {
        p->next = head;
        head = p;
    }
}
void LinkList::addNodeAtTail(int i, string name)
{
    Node* p = new Node(i, name);
    if (head == NULL)head = p;
    else
    {
        Node* q = head;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}
void LinkList::print()
{
    Node* p = head;
    while (p->next != NULL)
    {
        cout << p->mId << " " << p->mName << endl;
        p = p->next;
    }
    cout << p->mId << " " << p->mName << endl;
}
void LinkList::insertNode(int i, string name)
{
    Node* q = new Node(i, name);
    if (head == NULL)
    {
        head = q;
    }
    else
    {
        Node* p = head;
        Node* o = head;
        while (p != NULL && p->mId < i)
        {
            o = p;
            p = p->next;
        }
        o->next = q;
        q->next = p;
    }

}
void LinkList::deleteNode(int ID)
{
    if (head == NULL)
    {
        cout << "链表为空,不能删除" << endl;
    }
    else if (head->mId == ID)
    {
        head = head->next;
    }
    else
    {
        Node* p = head;
        Node* q = head;
        while (p != NULL && p->mId != ID)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;

    }

}
int  main()
{
    int  ID;
    LinkList  list1;
    string  name;
    cout << "请输入学生姓名：" << endl;
    for (int i = 2018003; i >= 2018001; i--)            //依次输入名字
    {
        cin >> name;
        list1.addNodeAtHead(i, name);
    }
    for (int i = 2018004; i <= 2018006; i++)            //依次输入名字
    {
        cin >> name;
        list1.addNodeAtTail(i, name);
    }

    cout << "学生信息为：" << endl;
    list1.print();
    cout << "请输入要删除的学生学号：" << endl;
    cin >> ID;
    cout << "学生信息为：" << endl;
    list1.deleteNode(ID);
    list1.print();
    cout << "请输入要插入的学生学号和姓名：" << endl;
    cin >> ID >> name;
    cout << "学生信息为：" << endl;
    list1.insertNode(ID, name);
    list1.print();
    system("pause");
    return  0;
}



