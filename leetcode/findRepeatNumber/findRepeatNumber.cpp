class Solution {
public:
    int findRepeatNumber1(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
        {
            return -1;
        }
        int cnt[len]={0};
        for(int &num:nums)
        {
            ++cnt[num];
            if(cnt[num]>1)
            {
                return num;
            }
        }
        return -1;
    }
	
	int findRepeatNumber2(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
        {
            return -1;
        }
        for(int i=0; i<len; ++i)
        {
            while(i!=nums[i])
            {
                if(nums[i]==nums[nums[i]])
                {
                    return nums[i];
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        return -1;
    }
};