//动态规划，优解
class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        else if(n==1)return 1;
        int a=0,b=0,c=1;
        for(int i=2;i<=n;i++)
        {
            a=b+c;
            b=c;
            c=a;
        }
        return a;
    }
};
//递归，废解
class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        else if(n==1)return 1;
        else return fib(n-1)+fib(n-2);
    }
};
