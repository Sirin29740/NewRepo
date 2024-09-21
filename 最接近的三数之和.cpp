class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(),nums.end());
        int first=0;
        
       
        int ans=nums[0]+nums[1]+nums[2];

        for(first;first<len-2;first++)
        {       
            int second=first+1;
            int third=len-1;
                while(third>second)
                {
                int score=nums[first]+nums[second]+nums[third];
                if(abs(ans-target)>abs(score-target))ans=score;
                score<target?second++:third--;
                }
        }
        return ans;
    }
};
