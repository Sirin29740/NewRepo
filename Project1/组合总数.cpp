class Solution {
public:
vector<vector<int>> result; //用于存答案
vector<int> path; //存路径
    //1：确定递归函数参数
    /*candidates:可选数的集合  target:目标和  start:下层开始下标
 因为要求在一个组合中一个数被选次数不同才是不同的组合，
所以下层循环要从i开始，例如第一个例子2367  第一次i=0
 每层都是2367可选 有223 = 7  下次如果i=1 第一层3
 如果没有start下层是2367能选 会有322 = 7 答案重复
所以要有start限制下层可选的数的集合，测试案例的输出也都是
非递减的说明下层的数是>=上层的数*/
    void backtracking(const vector<int>& candidates, int target, int start)
    {
        //2:终止条件
        if(target < 0)return; //相当于当前累加和 > target return
        if(target == 0)
        {
            result.push_back(path);
            return;
        }

        //3:单层搜索逻辑
        //因为同一个数字可以无限制重复被选取，所以每层可选取的集合都一样
        //剪枝因为给candidates从小到大排序了 如果这层的和+下层的和已经超过目标值了就不进如循环了 就是（剩余要减去的）target - (下层要减去的)candidates[i] >= 0  
        for(int i = start; i < candidates.size() && target - candidates[i] >= 0 ; i++)
        {
            path.push_back(candidates[i]); //处理
            backtracking(candidates, target - candidates[i], i); //递归
            path.pop_back(); //回溯
        } 
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); //从小到大排序
        backtracking(candidates, target, 0);
        return result;
    }
};
