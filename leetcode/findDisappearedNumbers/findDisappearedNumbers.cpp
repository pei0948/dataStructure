class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len=nums.size();
        vector<int> result(len, 0);
        for(int i=0; i<len; i++)
        {
            result[i]=i+1;
        }
        for(int i=0; i<len; i++)
        {
            result[nums[i]-1]=0;
        }
        int index=0;
        for(vector<int>::iterator it=result.begin(); it!=result.end(); it++)
        {
            if(*it!=0)
            {
                result[index]=*it;
                index++;
            }
        }
        for(int i=result.size()-1; i>=index;i--)
        {
            result.pop_back();
        }
        return result;
    }
};