#include<iostream>
using namespace std;
void maxsum(int a[], int n, int& maxi, int& maxj, int& sum) {
	for (int i = 0; i < n; i++)
	{
		int thissum = 0;
		for (int j = i; j < n; j++)
		{
			thissum += a[j];
			if (thissum > sum)
			{
				sum = thissum;
				maxi = i;
				maxj = j;
			}
		}
	}
}
int main()
{
	int a[6] = { -2,11,-4,13,-5,-2 };
	int sum = 0, maxi, maxj;
	maxsum(a, 6, maxi, maxj, sum);
	cout << maxi << " " << maxj << " " << sum;
	system("pause");
	return 0;
}

