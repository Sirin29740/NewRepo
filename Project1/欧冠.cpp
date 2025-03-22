#include<iostream>
#include<algorithm>
using namespace std;
int acount = 0;
bool isValidPair(char a, char b)//第二题
{
	if ((a == 'B' && b == 'C') || (a == 'C' && b == 'B')) return false;
	if ((a == 'D' && b == 'E') || (a == 'E' && b == 'D')) return false;
	return true;
}
void genepair(char s[], int start, int n)
{
	if (start == n-1)
	{
		for (int i = 0; i < n; i += 2)
		{
			cout << s[i] << "-" << s[i + 1] << " ";
		}
		cout << endl;
		acount++;
		return;
	}
	for (int i = start+1; i <= n; i++)
	{
		if(isValidPair(s[start+1],s[i]))
		{
			swap(s[start+1], s[i]);
			genepair(s, start + 2, n);
			swap(s[start+1], s[i]);
		}
	}
}
int main()
{
	char s[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	int n = sizeof(s) / sizeof(s[0]);
	genepair(s, 0, 7);
	cout << "number:" << acount << endl;
	system("pause");
	return 0;
}

