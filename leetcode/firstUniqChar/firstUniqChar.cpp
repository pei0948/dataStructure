class Solution {
public:
    int firstUniqChar(string s) {
        if(s=="")
        {
            return -1;
        }
        int len=s.size();
        int cnt[26]={0};
        for(int i=0; i<len; ++i)
        {
            s[i]-=97;
            ++cnt[s[i]];
        }
        for(int i=0; i<len; ++i)
        {
            if(cnt[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};