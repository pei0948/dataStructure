class Solution {
public:
    int findDuplicate1(vector<int>& nums) {
        int slow=0, fast=0;
        while(slow!=fast || fast==0)
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        int start=0;
        while(start!=slow)
        {
            start=nums[start];
            slow=nums[slow];
        }
        return slow;
    }
	
	int findDuplicate2(vector<int>& nums) {
        int low=1, high=nums.size()-1;
        int cnt=0, mid;
        while(low<high)
        {
            mid=((low+high)>>1);
            cnt=0;
            for(auto &num:nums)
            {
                if(num<=mid)
                {
                    cnt++;
                }
            }
            if(cnt<=mid)
            {
                low=mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return low;
        
    }
};