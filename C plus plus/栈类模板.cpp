#include<iostream>
using namespace std;

template<typename T>
class stack {
    T* top, * bottom;
    int size;
public:
    stack(int sz) { top = bottom = new T[size = sz]; }
    ~stack() { delete[] bottom; }
    void push(T i);
    T pop() {
        if (top > bottom) return *--top;
        else return 0;
    }
    bool empty();
    bool isfull();
    int get_size() { return size; }
};

template<typename T>
void stack<T>::push(T i) {
    if (!isfull()) {
        *top++ = i;
    }
    else {
        cout << "Stack is full." << endl;
    }
}

template<typename T>
bool stack<T>::empty() {
    return top == bottom;
}

template<typename T>
bool stack<T>::isfull() {
    return top - bottom == size;
}

class Complex {
public:
    Complex(double r = 0.0, double i = 0.0) { real = r; imag = i; }
    double getreal() { return real; }
    double getimag() { return imag; }
    friend istream& operator>>(istream& is, Complex& c);
    friend ostream& operator<<(ostream& os, const Complex& c);
private:
    double real;
    double imag;
};

istream& operator>>(istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

int main() {
    stack<char> S1(4);
    char ch;
    cout << "Characters:" << endl;
    for (int i = 0; i < 4; i++) {
        cin >> ch;
        S1.push(ch);
    }
    cout << "Popped characters:" << endl;
    while (!S1.empty())
        cout << S1.pop() << endl;

    stack<Complex> S2(4);
    Complex c1;
    cout << "Complex numbers:" << endl;
    for (int i = 0; i < 4; i++) {
        cin >> c1;
        S2.push(c1);
    }
    cout << "Popped complex numbers:" << endl;
    while (!S2.empty())
        cout << S2.pop() << endl;

    return 0;
}