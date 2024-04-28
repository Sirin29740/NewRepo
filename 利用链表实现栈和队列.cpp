//利用链表实现栈和队列
//
//队列具有先进先出的特点，所有新来的元素都放在队列尾部，出队列的元素从队列头部出去。下面是队列的示意图：
//
//
//blob.png
//
//栈具有后进先出的特点。所有入栈的元素都放在栈顶，出栈时栈顶元素先出。下面是栈的示意图：
//
//blob.png
//
//这两种结构具有很多相似的地方：都存放了一系列的元素，元素的操作都在两头进行，元素个数都是动态可变的。我们可以设计一个基类，完成它们共同的功能，然后分别派生出队列类和栈类。本实验要求以上一个实验实现的链表类作为基类并设计它的两个派生类。
//
//要求：
//
//(1) 在上一个实验实现的链表类的基础上派生队列类和栈类，要求队列类可以进行元素入队列和出队列操作，栈类可以进行入栈和出栈操作。
//
//(2) 在队列类中实现一个输出队列内容的函数printQueue，在栈类中实现一个输出栈中内容的函数printStack，


#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person() {}
    Person(int ID, string name);
    void showMessage();
    int getId();

private:
    int mId;
    string mName;
};

Person::Person(int ID, string name) {
    this->mId = ID;
    this->mName = name;
}

int Person::getId() {
    return mId;
}

void Person::showMessage() {
    cout << this->mId << " " << this->mName << endl;
}

class Node {
public:
    Node();
    Node(Person val);

    friend class LinkList; // Making LinkList a friend class

    void showMessage();

private:
    Person data;
    Node* next;
};

Node::Node() : next(nullptr) {}

Node::Node(Person val) : data(val), next(nullptr) {}

void Node::showMessage() {
    data.showMessage();
}

class LinkList {
public:
    LinkList();
    void addNodeAtTail(Person val);
    void print();
    void deleteNode(int id);
    int getHead(Person& val);
    void addNodeAtHead(const Person& val);

protected:
    Node* head;
};

LinkList::LinkList() : head(nullptr) {}

void LinkList::addNodeAtTail(Person val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkList::print() {
    Node* temp = head;
    while (temp) {
        temp->showMessage();
        temp = temp->next;
    }
}

void LinkList::deleteNode(int id) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr && temp->data.getId() != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Node with ID " << id << " not found." << endl;
        return;
    }

    if (prev == nullptr) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    delete temp;
}

int LinkList::getHead(Person& val) {
    if (!head) {
        cout << "Error: List is empty." << endl;
        return 0;
    }

    val = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;

    return 1;
}

void LinkList::addNodeAtHead(const Person& val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

class Queue : public LinkList {
public:
    void enterQueue(const Person& val);
    int outQueue(Person& val);
    void printQueue();
};

void Queue::enterQueue(const Person& val) {
    addNodeAtTail(val);
}

int Queue::outQueue(Person& val) {
    return getHead(val);
}

void Queue::printQueue() {
    print();
}

class Stack : public LinkList {
public:
    void push(const Person& val);
    int pop(Person& val);
    void printStack();
};

void Stack::push(const Person& val) {
    addNodeAtHead(val);
}

int Stack::pop(Person& val) {
    return getHead(val);
}

void Stack::printStack() {
    print();
}

int main() {
    string name;
    Queue* q1 = new Queue;
    Stack* s1 = new Stack;
    cout << "请输入学生姓名：" << endl;
    Person val;
    for (int i = 2018003; i >= 2018001; i--) {
        cin >> name;
        val = Person(i, name);
        s1->push(val);
    }
    for (int i = 2018004; i <= 2018006; i++) {
        cin >> name;
        val = Person(i, name);
        q1->enterQueue(val);
    }
    cout << "学生信息为：" << endl;
    q1->printQueue();
    s1->printStack();
    cout << "outqueue:" << endl;
    for (int i = 0; i < 2; i++) {
        q1->outQueue(val);
        val.showMessage();
    }
    cout << "pop:" << endl;
    for (int i = 0; i < 2; i++) {
        s1->pop(val);
        val.showMessage();
    }
    cout << "after deletes:" << endl;
    q1->printQueue();
    s1->printStack();
    delete q1;
    delete s1;
    return 0;
}
