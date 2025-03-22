#include<iostream>
using namespace std;
struct  node

{

    int  data;
    node* next;

    node(int  d, node* n = NULL) :data(d), next(n) {}

};

class  Joseph

{

private:

    node* head;

public:

    Joseph(int  n);

    ~Joseph();

    void  simulate();

};

void Joseph::simulate()
{
    if (head == NULL)
        cout << "No one!";
    else
    {
        node* p, * r;
        p = head;
        while (p->next != p)
        {
            for (int i = 1; i < 3; i++)
            {
                r = p;
                p = p->next;
            }
            cout << p->data << " ";
            r->next = p->next;
            p = p->next;
        }
        cout << endl;
        cout << p->data;
    }
}
Joseph::Joseph(int n)
{
    if (n == 0)
    {
        head = NULL;
        return;
    }
    else
    {

        node* r;
        head = new node(1);
        r = head;

        for (int i = 2; i <= n; i++)
        {
            r->next = new node(i);
            r = r->next;
        }r->next = head;
    }


}

Joseph::~Joseph()
{}


int  main()

{

    int  n;

    cin >> n;          //若输入5，表5人

    Joseph  jos(n);//生成有5个结点的链表，5个结点的data为1、2、3、4、5，表各人的序号

    jos.simulate();

    //输出两行。第一行输出被淘汰人的序号（序号间一个空格隔开）：3  1  5  2

    //第二行输出剩下人的序号：4
    system("pause");
    return  0;

}