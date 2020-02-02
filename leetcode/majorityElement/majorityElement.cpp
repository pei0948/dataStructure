class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len=nums.size();
        if(len==1)
        {
            return nums[0];
        }
        int cnt=1;
        int c=nums[0];
        for(int i=1; i<len; i++)
        {
           if(cnt==0)
           {
               c=nums[i];
               cnt=1;
           }
           else if(nums[i]!=c)
           {
               cnt--;
           }
           else
           {
               cnt++;
           }
        }
        return c;
    }
};