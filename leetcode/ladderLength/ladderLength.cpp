class Solution {
public:
    vector<int> smallestPath;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len=wordList.size();
        if(len<1)
        {
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        vector<bool> mark(len, false);
        int layer=1, qLen;
        string curr;
        while(!q.empty())
        {
            qLen=q.size();
            ++layer;
            while(qLen>0)
            {
                curr=q.front();
                q.pop();
                --qLen;
                for(int i=0; i<len; ++i)
                {
                    if(mark[i])
                    {
                        continue;
                    }
                    if(validTrans(curr, wordList[i]))
                    {
                        if(wordList[i]==endWord)
                        {
                            return layer;
                        }
                        else
                        {
                            q.push(wordList[i]);
                            mark[i]=true;
                        }
                    }
                }
            }
            
        }
        return 0;
    }

    bool validTrans(string &str1, string &str2)
    {
        if(str1==str2)
        {
            return false;
        }
        int len=str1.size(), cnt=0;
        for(int i=0; i<len; ++i)
        {
            if(str1[i]!=str2[i])
            {
                ++cnt;
            }
        }
        return (cnt==1);
    }
	
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len=wordList.size();
        if(len<1)
        {
            return 0;
        }
        unordered_set<string> wordDict(wordList.begin(), wordList.end());//去除重复单词
        if(wordDict.find(endWord)==wordDict.end())
        {
            return 0;
        }
        unordered_set<string> beginSet({beginWord});
        unordered_set<string> endSet({endWord});
        int layer=1;

        while(!beginSet.empty())
        {
            for(auto s:beginSet)
            {
                wordDict.erase(s);
            }
            unordered_set<string> temp;
            ++layer;
            for(auto s:beginSet)
            {
                string str;
                int len=s.size();
                for(int i=0; i<len; ++i)
                {
                    str=s;
                    for(char c='a'; c<='z'; ++c)
                    {
                        if(c==str[i])
                        {
                            continue;
                        }
                        str[i]=c;
                        if(wordDict.find(str)==wordDict.end())
                        {
                            continue;
                        }
                        if(endSet.find(str)!=endSet.end())
                        {
                            return layer;//轮换对beginSet赋值，轮询endSet时，layer也在自增
                        }
                        temp.insert(str);
                    }
                }

            }

            if(temp.size()>endSet.size())
            {
                beginSet=endSet;
                endSet=temp;
            }
            else
            {
                beginSet=temp;
            }

        }
        return 0;
    }
};
