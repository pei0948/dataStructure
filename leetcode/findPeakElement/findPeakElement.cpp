class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,
            high=nums.size()-1;
        int mid;
        while(low+1<high)
        {
            mid=(low+high)>>1;
            if(nums[mid]<nums[mid+1])
            {
                low=mid;
            }
            else if(nums[mid]>nums[mid+1])
            {
                high=mid;
            }
        }
        return nums[low]>=nums[high]?low:high;
    }
};