class Solution {
public:
    bool isValid(string s) {
int n=s.length();
if(n%2==1)return false;
       unordered_map<char,char> pairs{
        {')','('},{']','['},{'}','{'}
       };
       stack<char> sta;
       for(int i=0;i<n;i++)
       {
        if(!pairs.count(s[i]))sta.push(s[i]);
        else {
            if(sta.empty()||sta.top()!=pairs[s[i]])return false;
            else sta.pop();
        }
       }
       return sta.empty();
    }
};
