class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        for(i;i<nums.size();i++)
        {
            if(nums[i]==target)return i;
            else if(nums[i]>target){nums.insert(nums.begin()+i,target);return i;}
        }
       return i;

    }
};
