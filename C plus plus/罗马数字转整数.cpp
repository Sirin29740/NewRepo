class Solution {
public:
    unordered_map<char, int> roman{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
    };
    int romanToInt(string s) {
        int num = 0;
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            int value = roman[s[i]];
            if (i < len - 1 && value < roman[s[i + 1]])num -= value;
            else num += value;
        }
        return num;
    }
};