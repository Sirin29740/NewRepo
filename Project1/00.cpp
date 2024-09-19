class Solution {
public:
    int myAtoi(string s) {
        int len=s.length();
        int result=0;
        int iszheng=1;
        int i=0;
        while(i<len)
        {
            if(s[i]==' ')i++;
        }
        if(s[i]=='-'){iszheng=-1;i++;}
        else if(s[i]=='+'){i++;}
        while(i<len)
        {
            if(s[i]>'9'||s[i]<'0')break;
            if(result>INT_MAX/10){break;}
            result=result*10+(s[i]-'0');
            i++;
        }
        
        return result*iszheng;
    }
};
