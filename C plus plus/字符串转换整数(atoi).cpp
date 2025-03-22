class Solution {
public:
    int myAtoi(string s) {
        int len=s.length();
        long long result=0;
        int iszheng=1;
        int i=0;
        while(i<len)
        {
            if(s[i]==' ')i++;
            else break;
        }
        if(s[i]=='-'){iszheng=-1;i++;}
        else if(s[i]=='+'){i++;}
        while(i<len)
        {
            if(s[i]>'9'||s[i]<'0')break;
           
            result=result*10+(s[i]-'0');
            long long v=result*iszheng;
           
            if(v>=INT_MAX){return INT_MAX;}
            if(v<=INT_MIN){return INT_MIN;}
            i++;
        }
        
        return result*iszheng;
    }
};
