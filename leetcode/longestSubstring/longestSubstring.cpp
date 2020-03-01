class Solution {
public:
    int longestSubstring(string s, int k) {
        if(k<=1)
        {
            return s.size();
        }
        return getLongestSubstring(s, k);
    }
    int getLongestSubstring(string &s, int k)
    {
        if(s.empty() || s.size()<k)
        {
            return 0;
        }
        vector<int> cnt(26, 0);
        int len=s.size();
        for(char &c:s)
        {
            ++cnt[c-97];
        }
        int i=0;
        while(i<len && cnt[s[i]-97]>=k)
        {
            ++i;
        }
        if(i>=len)
        {
            return len;
        }
        int l=getLongestSubstring(s.substr(0, i), k);
        while(i<len && cnt[s[i]-97]<k)
        {
            ++i;
        }
        int r=getLongestSubstring(s.substr(i), k);
        return max(l, r);
    }
};