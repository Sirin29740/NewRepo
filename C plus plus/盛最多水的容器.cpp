class Solution {
public:
    int maxArea(vector<int>& height) {
        int len=height.size();
        int aaa=0;
        int i=0,j=len-1;
       while(i<j)
       {
        int score=min(height[i],height[j])*(j-i);
        aaa=max(score,aaa);
        if(height[i]<=height[j])i++;
        else j--;
       }
        return aaa;
    }
};
