class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len=nums.size();
        if(len<3)
        {
            return false;
        }
        int minV=INT_MAX,midV=INT_MAX;
        for(int i=0; i<len; i++)
        {
            if(nums[i]<=minV)
            {
                minV=nums[i];
            }
            else if(nums[i]<=midV)
            {
                midV=nums[i];
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};