#define _CRT_SECURE_NO_WARNINGS 1 


#include<iostream>
#include<cstring>
using namespace std;
template<typename T, int N>
void Add(T x[], T y[], T z[])
{
    for (int i = 0; i < N; i++)
    {
        z[i] = x[i] + y[i];
    }
}
template<typename T>
void Add(T c[], T d[], T str[])
{
    strcat(c, d);
    strcpy(str, c);
}
int  main()
{
    const  int  N = 5;
    int  x[N] = { 2,-4,6,8,0 }, y[N], z[N] = { 0 };
    char  c[] = "Hello,", d[100];

    for (int i(0); i < N; i++)
        cin >> *(y + i);

    while (cin.get() != '\n');
    cin.getline(d, 100);

    Add<int, N>(x, y, z);
    for (int i(0); i < N; i++)
        cout << z[i] << "  ";
    cout << endl;

    char* pc = new  char[strlen(c) + strlen(d) + 1];
    Add(c, d, pc);
    cout << pc << endl;
    delete[]pc;
    system("pause");
}
