class Solution {
public:
    vector<string> wordBreak1(string s, vector<string>& wordDict) {
        if(!canBreak(s, wordDict))
        {
            return {};
        }
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> sentences;
        vector<string> words;
        int len=s.size();
        int wordMax=INT_MIN,
            wordMin=INT_MAX;
        for(string &word:wordDict)
        {
            wordMax=max(wordMax, (int)word.size());
            wordMin=min(wordMin, (int)word.size());
        }
        backTrace(s, len, 0, dict, wordMax, wordMin, sentences, words);
        return sentences;
    }
    void backTrace(string &s, int &len, int start, unordered_set<string> &dict, int &wordMax, int &wordMin, vector<string> &sentences, vector<string> &words)
    {
        if(start==len)
        {
            string sentence;
            for(string word:words)
            {
                sentence+=(word+" ");
            }
            sentences.push_back(sentence.substr(0, sentence.size()-1));
            return;
        }
        for(int i=wordMin; i<=wordMax && start+i<=len; ++i)
        {
            if(dict.count(s.substr(start, i)))
            {
                words.push_back(s.substr(start, i));
                backTrace(s, len, start+i, dict, wordMax, wordMin, sentences, words);
                words.pop_back();
            }
        }
    }

    bool canBreak(string &s, vector<string> &wordDict)
    {
        int len=s.size()+1;
        bool mark[len]{false};
        mark[0]=true;
        for(int i=0; i<len; ++i)
        {
            if(mark[i])
            {
                for(string &word:wordDict)
                {
                    int wordSize=word.size();
                    if(i+wordSize<len && s.substr(i, wordSize)==word)
                    {
                        mark[i+wordSize]=true;
                    }
                }
            }
        }
        return mark[len-1];
    }
	
	vector<string> wordBreak2(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> ump;
        return getSentences(wordDict, s, ump);
    }
    vector<string> getSentences(vector<string> &wordDict, string s, unordered_map<string, vector<string>> &ump)
    {
        if(s.empty())
        {
            return {""};
        }
        if(ump.count(s))
        {
            return ump[s];
        }

        vector<string> res;
        int len=s.size();
        for(string word:wordDict)
        {
            int wordSize=word.size();
            if(wordSize<=len && s.substr(0, wordSize)==word)
            {
                vector<string> subRes=getSentences(wordDict, s.substr(wordSize), ump);
                for(auto s:subRes)
                {
                    res.push_back(word+(s.empty()?"":" "+s));
                }
            }
        }
        ump[s]=res;
        return res;
    }
};