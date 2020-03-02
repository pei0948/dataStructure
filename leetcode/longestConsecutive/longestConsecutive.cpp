class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
        {
            return len;
        }
        int res=INT_MIN;
        int lenNum=1, tempNum;
        unordered_set<int> us(nums.begin(), nums.end());
        for(int num:nums)
        {
            if(us.count(num-1))
            {
                continue;
            }
            else
            {
                lenNum=1;
                tempNum=num+1;
                while(us.count(tempNum))
                {
                    ++lenNum;
                    ++tempNum;
                }
                if(lenNum>res)
                {
                    res=lenNum;
                }
            }
        }
        return res;
    }
};