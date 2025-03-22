class Solution {
public:
    int strStr(string haystack, string needle) {
        int j=0;
        if(haystack.length()>=needle.length())
        {for(j;j<haystack.length()-needle.length()+1;j++)
        {
            if(haystack.substr(j,needle.length())==needle)return j;
        }
        }
        return -1;

    }
};
