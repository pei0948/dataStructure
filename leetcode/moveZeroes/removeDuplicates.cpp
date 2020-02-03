class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
        {
            return len;
        }
        int k=0;
        for(int i=1; i<len; i++)
        {
            if(nums[i]!=nums[k])
            {
                k++;
                if(k!=i)
                {
                    nums[k]=nums[i];
                }
            }
        }
        return (k+1);
    }
};