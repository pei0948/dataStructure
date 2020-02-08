class Solution {
public:
    vector<int> productExceptSelf1(vector<int>& nums) {
        vector<int> result;
        int len=nums.size();
        if(len<2)
        {
            return result;
        }
        result.resize(len, 0);
        result[len-1]=1;
        for(int i=len-2; i>=0; i--)
        {
            result[i]=result[i+1]*nums[i+1];
        }
        int productL=1;
        for(int i=1; i<len; i++)
        {
            productL=productL*nums[i-1];
            result[i]=result[i]*productL;
        }
        return result;
    }
	
	vector<int> productExceptSelf2(vector<int>& nums) {
        vector<int> result;
        int len=nums.size();
        if(len<2)
        {
            return result;
        }
        result.resize(len, 1);
        int productL=1,
            productR=1;
        for(int i=0; i<len; i++)
        {
            result[i]=result[i]*productL;
            productL=productL*nums[i];

            result[len-1-i]=result[len-1-i]*productR;
            productR=productR*nums[len-1-i];
        }
        return result;
    }
};