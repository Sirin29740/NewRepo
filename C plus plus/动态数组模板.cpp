#include <iostream>
#include <iomanip>
using namespace std;

template <typename ElemType>
class myArrayList {
private:
    int mSize;
    int mLen;
    ElemType* mpArr;
public:
    myArrayList(int n);
    myArrayList(ElemType* a, int n);
    void show();
    ElemType getMax();
    void sort();
    myArrayList(myArrayList<ElemType>& other);
};

template <typename ElemType>
myArrayList<ElemType>::myArrayList(int n) {
    this->mSize = n;
    this->mLen = n; // 初始化 mLen
    this->mpArr = new ElemType[mSize];
}

template <typename ElemType>
myArrayList<ElemType>::myArrayList(ElemType* a, int n) {
    this->mSize = n;
    this->mLen = n; // 初始化 mLen
    this->mpArr = new ElemType[mSize];
    for (int i = 0; i < mSize; i++) {
        this->mpArr[i] = a[i];
    }
}

template <typename ElemType>
void myArrayList<ElemType>::sort() {
    for (int i = 0; i < mLen - 1; i++) { // 修正内层循环起始位置
        for (int j = i + 1; j < mLen; j++) { // 使用 j 替换 i
            if (mpArr[i] > mpArr[j]) {
                ElemType temp = mpArr[i];
                mpArr[i] = mpArr[j];
                mpArr[j] = temp;
            }
        }
    }
}

template <typename ElemType>
void myArrayList<ElemType>::show() {
    for (int i = 0; i < mLen; i++)
        cout << mpArr[i] << "      ";
    cout << endl;
}

template <typename ElemType>
ElemType myArrayList<ElemType>::getMax() {
    ElemType max = mpArr[0];
    for (int i = 1; i < mLen; i++)
        if (max < mpArr[i])
            max = mpArr[i];
    return max;
}

template <typename ElemType>
myArrayList<ElemType>::myArrayList(myArrayList<ElemType>& other) {
    this->mLen = other.mLen;
    this->mSize = other.mSize;
    this->mpArr = new ElemType[this->mLen];
    for (int i = 0; i < this->mLen; i++)
        this->mpArr[i] = other.mpArr[i];
}

class Student {
private:
    int mId;
    float height;
    int score;
public:
    Student(int id = 0, float h = 0, int s = 0) : height(h), mId(id), score(s) {}
    friend ostream& operator<<(ostream& out, const Student s) {
        out << "ID:" << s.mId << "  " << "Height:" << s.height << "  "<< "Score:"<<s.score << endl; // 使用 out 输出
        return out;
    }
    bool operator<( Student other)  {
        
        return this->score < other.score;
    }
    bool operator>(Student other) {

        return this->score > other.score;
    }
};

int main() {
    int a[] = { 1, 2, 3, 5, 7, 9, 12, 8 };
    double b[] = { 1, 2.5, 3.6, 5, 7, 9, 12.8, 8 };
    myArrayList<int> list1(a, 8);
    list1.sort();
    list1.show();
    cout << "max=" << list1.getMax() << endl;
    myArrayList<double> list2(b, 8);
    list2.sort();
    list2.show();
    cout << "max=" << list2.getMax() << endl;
    Student s[3] = { Student(1, 175, 80), Student(2, 178, 90), Student(3, 195, 83) }, s1;
    myArrayList<Student> list3(s, 3);
    list3.sort();
    list3.show();
    cout << "max=" << list3.getMax() << endl;
    return 0;
}
