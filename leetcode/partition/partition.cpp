class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palindrome;
        vector<string> path;
        int len=s.size();
        backTrace(s, len, 0, path, palindrome);
        return palindrome;
    }
    void backTrace(string &s, int &len, int start, vector<string> &path, vector<vector<string>> &palindrome)
    {
        if(start==len)
        {
            palindrome.push_back(path);
            return;
        }

        for(int i=start; i<len; ++i)
        {
            if(s[i]==s[start] && isPalindrome(s, start, i))
            {
                path.push_back(s.substr(start, i-start+1));
                backTrace(s, len, i+1, path, palindrome);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string &s, int low, int high)
    {
        while(low<high)
        {
            if(s[low]!=s[high])
            {
                return false;
            }
            ++low;
            --high;
        }
        return true;
    }
};