class Solution {
public:
    int maxProduct1(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        int len=nums.size();
        if(len==1)
        {
            return nums[0];
        }
        int maxV=1,
            minV=1,
            maxTemp=INT_MIN;
        for(int i=0; i<len; i++)
        {
            if(nums[i]<0)
            {
                swap(maxV, minV);
            }
            maxV=max(maxV*nums[i], nums[i]);
            minV=min(minV*nums[i], nums[i]);
            maxTemp=max(maxTemp, maxV);
        }
        return maxTemp;
    }
	
	int maxProduct2(vector<int>& nums) {
        if(nums.empty())
        {
            return 0;
        }
        int len=nums.size();
        if(len==1)
        {
            return nums[0];
        }
        int maxTemp=INT_MIN;
        int p=1;
        for(int i=0; i<len; i++)
        {
            p=p*nums[i];
            maxTemp=max(p, maxTemp);
            if(nums[i]==0)
            {
                p=1;
            }
        }
        p=1;
        for(int i=len-1; i>=0; i--)
        {
            p=p*nums[i];
            maxTemp=max(p, maxTemp);
            if(nums[i]==0)
            {
                p=1;
            }
        }
        return maxTemp;
    }
};
