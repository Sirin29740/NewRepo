class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>0;i--)
        {
            if(nums[i-1]<nums[i]){
            for(int j=n-1;j>i-1;j--)
            {
                if(nums[j]>nums[i-1])
                {
                    int a=nums[j];
                    nums[j]=nums[i-1];
                    nums[i-1]=a;
                    sort(nums.begin()+i,nums.end());
                    return;
                }
            }
            }
        }
        sort(nums.begin(),nums.end());
        return;
    }
};
