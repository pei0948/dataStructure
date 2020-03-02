class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==0)
        {
            return 0;
        }
        if(len==1)
        {
            return nums[0];
        }
        int res=INT_MIN, pre=0, prePre=0;
        for(int i=0; i<len; ++i)
        {
            res=max(prePre+nums[i], pre);//res=max(dp[i-2]+nums[i], dp[i-1]),判断是否打劫当前人家
            prePre=pre;
            pre=res;
        }
        return res;
    }
};