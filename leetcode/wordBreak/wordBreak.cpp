class Solution {
public:
    bool wordBreak1(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int len=s.size()+1;
        vector<bool> canBreak(len, false);
        canBreak[0]=true;
        int maxSize=INT_MIN,
            minSize=INT_MAX;
        for(auto &word:wordDict)
        {
            maxSize=max(maxSize, (int)word.size());
            minSize=min(minSize, (int)word.size());
        }

        for(int i=minSize; i<len; ++i)
        {
            int upBound=i-minSize,
                downBound=i-maxSize;
            for(int j=max(downBound, 0); j<=upBound; ++j)
            {
                if(canBreak[j] && dict.count(s.substr(j, i-j)))
                {
                    canBreak[i]=true;
                    break;
                }
            }
        }
        return canBreak[len-1];
    }
	
	bool wordBreak2(string s, vector<string>& wordDict) {
        int len=s.size()+1;
        vector<bool> canBreak(len, false);
        canBreak[0]=true;
        for(int i=0; i<len; ++i)
        {
            if(canBreak[i])
            {
                for(auto &word:wordDict)
                {
                    int wordSize=word.size();
                    if(wordSize+i>=len)
                    {
                        continue;
                    }
                    if(s.substr(i, wordSize)==word)
                    {
                        canBreak[i+wordSize]=true;
                    }
                }
            }
        }
        return canBreak[len-1];
    }
};