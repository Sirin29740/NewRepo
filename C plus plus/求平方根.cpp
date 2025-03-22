class Solution {
public:
    int mySqrt(int x) {
        int i;
        if(x==0)i=0;
        else if(x<4)i=1;
        else
        {
      for(int j=2;j<x;j++)
      {
        if((long long)j*j>x){i=j-1;break;}
      }
        }
        return i;
    }
};
