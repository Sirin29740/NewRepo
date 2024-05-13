#include<iostream>
using namespace std;
int Finddata(int arr[], int n, int x)
{
    int i = 0;
    while (arr[i] != x&&i<n)
    {
        i++;
    }
    if (i != n)
    {               
        return i;
    }
    else
    {           
        return -1;
    }

}
int Finddata(char str[], char ch)
{
    int i = 0;
    while (str[i] != ch&&i<69)
    {
        i++;
    }
    if (i !=69)
    {        
        return i;
    }
    else
    {        
        return -1;
    }
}




int main()

{

    int fid, arr[] = { -11,3,5,13,27,8,23,45,2,3,-14,0,43,20,2,30,5,45,0,42,38,67 };

    char ch, str[] = "The university seeks to integrate social service into its schooling.";

    int N = sizeof(arr) / sizeof(int);

    cin >> fid;//fid为要查找的整数

    int i = Finddata(arr, N, fid);
    if (i!=-1)cout << "Found:" << i << endl;
    else cout << "Not Found!" << endl;
    //省略若干条语句

        cin >> ch; //ch为要查找的字符

    i = Finddata(str, ch);
    if (i!=-1)cout << "Found:" << i << endl;
    else cout << "Not Found!" << endl;
     //省略若干条语句

        return 0;

}


