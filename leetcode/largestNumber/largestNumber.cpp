class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int lenNums=nums.size();
        if(lenNums==0)
        {
            return "";
        }
        vector<string> numsStr(lenNums);
        for(int i=0; i<lenNums; ++i)
        {
            numsStr[i]=to_string(nums[i]);
        }
        sort(numsStr.begin(), numsStr.end(), largerThan);
        string res;
        for(int i=0; i<lenNums; ++i)
        {
            res+=numsStr[i];
        }
        if(res[0]=='0')
        {
            return "0";
        }
        return res;
    }
    static bool largerThan(string &s1, string &s2)
    {
        return ((s1+s2)>(s2+s1));
    }
};