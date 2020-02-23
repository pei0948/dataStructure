class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.empty())
        {
            return res;
        }
        int len=nums.size()-k;
        int maxV=getMaxV(nums, 0, k);
        res.push_back(maxV);
        for(int i=1; i<=len; i++)
        {
            if(maxV==nums[i-1])
            {
                maxV=getMaxV(nums, i, k);
            }
            else if(nums[i+k-1]>maxV)
            {
                maxV=nums[i+k-1];
            }
            res.push_back(maxV);
        }
        return res;
    }
    int getMaxV(vector<int> &nums, int low, int k)
    {
        int maxV=nums[low];
        int len=low+k;
        for(int i=low+1; i<len; i++)
        {
            if(nums[i]>maxV)
            {
                maxV=nums[i];
            }
        }
        return maxV;
    }
};