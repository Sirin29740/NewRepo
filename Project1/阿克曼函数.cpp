#include<iostream>
using namespace std;

int Ackerman(int m ,int n )
{
	if (m == 0)return n + 1;
	else if (n == 0)return Ackerman(m - 1, 1);
	else return Ackerman(m - 1, Ackerman(m, n - 1));
}


int main()
{
	int m, n;
	cout << "请输入m:";
	cin >> m;
	cout << endl;
	cout << "请输入n:";
	cin >> n;
	cout << endl;
	cout<<"结果为："<<Ackerman(m, n)<<endl;
	system("pause");
	return 0;
}