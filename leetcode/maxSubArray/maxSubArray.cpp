class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        if(len==0)
        {
            return 0;
        }
        else if(len==1)
        {
            return nums[0];
        }
        int sum=nums[0];
        int max=nums[0];
        for(int i=1; i<len; i++)
        {
            if(sum<0)
            {
                sum=0;
            }
            sum=sum+nums[i];
            if(sum>max)
            {
                max=sum;
            }
        }
        return max;
    }
};