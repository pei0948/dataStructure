class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int lowBound=0;
        int len=nums.size();
        int upBound=len-1;
        
        while(lowBound<upBound && nums[lowBound]<=nums[lowBound+1])
        {
            lowBound++;
        }
        if(lowBound==upBound)
        {
            return 0;
        }
        while(nums[upBound]>=nums[upBound-1])
        {
            upBound--;
        }

        int lowestV=nums[lowBound],
            largestV=nums[upBound];
        for(int i=lowBound; i <= upBound; i++)
        {
            if(nums[i]<lowestV)
            {
                lowestV=nums[i];
            }
            if(nums[i]>largestV)
            {
                largestV=nums[i];
            }
        }
        while(lowBound>=0 && nums[lowBound]>lowestV)
        {
            lowBound--;
        }
        while(upBound<=len-1 && nums[upBound]<largestV)
        {
            upBound++;
        }
        return (upBound-lowBound-1);
    }
};