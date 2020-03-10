class Solution {
public:
    bool isAnagram(string s, string t) {
        int sLen=s.size(),
            tLen=t.size();
        if(sLen!=tLen)
        {
            return false;
        }
        int cnt[26]={0};
        for(int i=0; i<sLen; ++i)
        {
            ++cnt[s[i]-97];
            --cnt[t[i]-97];
        }
        for(int i=0; i<26; ++i)
        {
            if(cnt[i]!=0)
            {
                return false;
            }
        }
        return true;

    }
};