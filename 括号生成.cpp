class Solution {
public:
    void backtrace(vector<string>& ans, string& path, int left_count, int right_count){
        if(left_count == 0 && right_count == 0){
            ans.push_back(path);
            return;
        }
        if((left_count != 0 || right_count != 0) && left_count <= right_count){
            //先进行left
            if(left_count != 0){
                path.push_back('(');
                left_count--;
                backtrace(ans, path, left_count, right_count);
                path.pop_back();
                left_count++;
            }
            //再进行right
            if(right_count != 0){
                path.push_back(')');
                right_count--;
                backtrace(ans, path, left_count, right_count);
                path.pop_back();
                right_count++;
            }
            // //上面的回溯都完毕了，该阶段到此为止了
            // return;
        }
    }

    vector<string> generateParenthesis(int n) {
        int left_count = n;
        int right_count = n;
        vector<string> ans;
        string path;
        backtrace(ans, path, left_count, right_count);

        return ans;
    }
};
