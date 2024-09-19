class Solution {
public:
    string convert(string s, int numRows) {
        int num=numRows*2-2;
        int len=s.length();
        string ans;
        int m=0;
        if(numRows==1||numRows>=len)return s;
        for(int i=0;i<numRows;i++)
        {
          for(int j=0;i+j<len;j+=num)
            {
                ans+=s[i+j];
                if(i>0&&i<numRows-1&&num-i+j<len)
                {
                    
                    ans += s[num-i+j];
                }
            }
        }
        return ans;
    }
};
