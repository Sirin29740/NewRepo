class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len=nums.size();
        vector<vector<int>> ans;
        if(len<4)return ans;
        sort(nums.begin(),nums.end());
        int a=0;
        for(a;a<len-3;a++)
        {
            if(a!=0&&nums[a]==nums[a-1])continue;
            int b=a+1;


            for(b;b<len-2;b++)
            {
                if(b!=a+1&&nums[b]==nums[b-1])continue;



                int d=len-1,c=b+1;
                while(c<d)
                {
                   
                    if((long)nums[a]+nums[b]+nums[c]+nums[d]==target){ 
                    ans.push_back({nums[a],nums[b],nums[c],nums[d]});
                    while(c<d&&nums[c]==nums[c+1])c++;
                    while(c<d&&nums[d]==nums[d-1])d--;
                    c++;d--;}
                    else if((long)nums[a]+nums[b]+nums[c]+nums[d]>target)d--;
                    else if((long)nums[a]+nums[b]+nums[c]+nums[d]<target)c++;
                }
            }
        }
        return ans;
    }
};
// 具体实现时，还可以进行一些剪枝操作：

// 在确定第一个数之后，如果 nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target，说明此时剩下的三个数无论取什么值，四数之和一定大于 target，因此退出第一重循环；
// 在确定第一个数之后，如果 nums[i]+nums[n−3]+nums[n−2]+nums[n−1]<target，说明此时剩下的三个数无论取什么值，四数之和一定小于 target，因此第一重循环直接进入下一轮，枚举 nums[i+1]；
// 在确定前两个数之后，如果 nums[i]+nums[j]+nums[j+1]+nums[j+2]>target，说明此时剩下的两个数无论取什么值，四数之和一定大于 target，因此退出第二重循环；
// 在确定前两个数之后，如果 nums[i]+nums[j]+nums[n−2]+nums[n−1]<target，说明此时剩下的两个数无论取什么值，四数之和一定小于 target，因此第二重循环直接进入下一轮，枚举 nums[j+1]。

