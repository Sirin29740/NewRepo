class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())return "";
        int len=strs[0].length();
        int wide=strs.size();
        for(int i=0;i<len;i++)
        {
            char c=strs[0][i];
            for(int j=1;j<wide;j++)
            {
                if(strs[j][i]!=c||i==strs[j].length())return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};
