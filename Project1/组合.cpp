// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。你可以按任何顺序 返回答案。
// 示例 1：
// 输入：n = 4, k = 2
// 输出：
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void dfs(int start,int n,int k)
    {
        if(k==0)
        {
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<=n;i++)
        {
            temp.push_back(i);
            dfs(i+1,n,k-1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return ans;
    }
};
