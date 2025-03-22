class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int len=s.size();
    int p=0;
    int q=0;
    unordered_set<char>ooc;
    for(int i=0;i<len;i++)
    {
        while(q<len&&!ooc.count(s[q]))
        {
            ooc.insert(s[q]);q++;
           
        }
        ooc.erase(s[i]);
        p=max(p,q-i);
        
    }
    return p;
    }
};
