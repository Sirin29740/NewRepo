class Solution {
public:
/*
思路：每个数字代表的数集是不一样的，第一层能选的数集
是digits第一个数字所以代表的字母集，每层的for循环的数
集是不一样的，所以要用一个索引表示当层循环的数集，
然后要把数字转换为字母，字母是就是可以选择的数集，
还要一个path记录路径一个result记录答案，一个参数记
录递归的深度(层数),   path也可写到参数里
*/

const string digital_mapping[10] =  //映射每个数字所代表字母集合
{
    "", //0
    "", //1
    "abc", //2
    "def", //3
    "ghi", //4
    "jkl", //5
    "mno", //6
    "pqrs", //7
    "tuv", //8
    "wxyz", //9
};
vector<string>result;   //记录答案
string path; //记录路径
    //1:确定函数参数
    void backtracking(string digits, int index)
    {
        //2：确定终止条件 处理结果 return
        if(index == digits.size())
        {
            result.push_back(path);
            return;
        }

        //3:选择本层集合中元素
        int digital_number = digits[index] - '0'; //取出digits中本层的数字
        string letters = digital_mapping[digital_number]; //从映射中取出字母集
        for(int i = 0; i < letters.size(); i++)
        {
            path.push_back(letters[i]); //处理
            backtracking(digits, index + 1); //递归
            path.pop_back(); //回溯
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty())return result;
        backtracking(digits, 0);
        return result;
    }
};
