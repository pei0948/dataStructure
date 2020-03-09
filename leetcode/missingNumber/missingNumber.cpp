class Solution {
public:
    int missingNumber1(vector<int>& nums) {
        int len=nums.size();
        int sum=0;
        for(int &num:nums)
        {
            sum+=num;
        }
        return ((len*(len+1)>>1)-sum);
    }
	
	int missingNumber2(vector<int>& nums) {
        int len=nums.size(), res=len;
        for(int i=0; i<len; ++i)
        {
            res^=nums[i];
            res^=i;
        }
        return res;
    }
};