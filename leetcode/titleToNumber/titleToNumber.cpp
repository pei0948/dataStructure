class Solution {
public:
    int titleToNumber(string s) {
        int len=s.size(), 
            result=0;
        for(int i=0; i<len; i++)
        {
            result=result*26-64+s[i];
        }
        return result;
    }
};