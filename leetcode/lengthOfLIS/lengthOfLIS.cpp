class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
        {
            return len;
        }
        vector<int> dp(len, 1);
        for(int i=1; i<len; ++i)
        {
            for(int j=0; j<i; ++j)
            {
                if(nums[i]>nums[j] && dp[i]<dp[j]+1)//dp[i]=max(dp[i], dp[j]+1)
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        int res=1;
        for(int cnt : dp)
        {
            if(cnt>res)
            {
                res=cnt;
            }
        }
        return res;
    }
	
	int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
        {
            return len;
        }
        vector<int> res;
        res.push_back(nums[0]);
        int low, high, mid;
        for(int i=1; i<len; ++i)
        {
            if(nums[i]>res.back())
            {
                res.push_back(nums[i]);
            }
            else
            {
                low=0;
                high=res.size()-1;
                while(low<high)
                {
                    mid=((low+high)>>1);
                    if(res[mid]>nums[i])
                    {
                        high=mid;
                    }
                    else if(res[mid]<nums[i])
                    {
                        low=mid+1;
                    }
                    else
                    {
                        break;
                    }
                }
                if(low==high)
                {
                    res[low]=nums[i];
                }  
            }
        }
        return res.size();
    }
};