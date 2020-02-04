class Solution {
public:
    bool containsDuplicate1(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
        {
            return false;
        }
        sort(nums.begin(), nums.end());
        for(int i=1; i<len; i++)
        {
            if(nums[i]==nums[i-1])
            {
                return true;
            }
        }
        return false;
    }
	bool containsDuplicate2(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
        {
            return false;
        }
        map<int, int> m;
        for(int i=0; i<len; i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]>1)
            {
                return true;
            }
        }
        return false;
    }
};