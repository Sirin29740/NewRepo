// 泰波那契序列 Tn 定义如下： 

// T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

// 给你整数 n，请返回第 n 个泰波那契数 Tn 的值。

 
class Solution {
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        else if(n<=2)return 1;
        int a=0,b=0,c=1,d=1;
        for(int i=3;i<=n;i++)
        {
            a=b+c+d;
            b=c;
            c=d;
            d=a;
        }
        return a;
    }
};
