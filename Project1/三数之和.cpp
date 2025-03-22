class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len=nums.size();
        sort(nums.begin(),nums.end() );
        vector<vector<int>> ans;
        for(int i=0;i<len;i++)
        {
            if(i>0&&nums[i]==nums[i-1])continue;
            int third=len-1;
            int second=i+1;
            for(second;second<third;second++ )
                {
                if(second>i+1&&nums[second]==nums[second-1])continue;
                while(second<third&&nums[second]+nums[third]+nums[i]>0)
                { third--; }
                if(second==third)break;
               if(nums[i]+nums[second]+nums[third]==0)
                   {ans.push_back({nums[i],nums[second],nums[third]});}
                }
        }
            return ans;
    }
};
