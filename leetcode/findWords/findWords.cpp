class Solution {
public:
    class Trier
        {
            public:
                Trier *next[26]={nullptr};
                int whichWord=-1;
                void insert(string &word, int &which)
                {
                    Trier *curr=this;
                    int idx;
                    for(char &c : word)
                    {
                        idx=c-'a';
                        if(!curr->next[idx])
                        {
                            curr->next[idx]=new Trier();
                        }
                        curr=curr->next[idx];
                    }
                    curr->whichWord=which;
                }
        };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int r=board.size();
        if(r<1)
        {
            return {};
        }
        int c=board[0].size();
        Trier *prefixTree=new Trier();
        int which=0;
        for(string &word:words)
        {
            prefixTree->insert(word, which);
            ++which;
        }
        vector<bool> sameWord(which, false);
        for(int i=0; i<r; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                vector<vector<bool>> status(r, vector<bool>(c, true));
                getSameWord(board, r, c, i, j, prefixTree, sameWord, status);
            }
        }
        vector<string> res;
        for(int i=0; i<which; ++i)
        {
            if(sameWord[i])
            {
                res.push_back(words[i]);
            }
        }
        return res;
    }

    void getSameWord(vector<vector<char>> &board, int &r, int &c, int m, int n, Trier *curr, vector<bool> &sameWord, vector<vector<bool>> &status)
    {
        if(m<0 || m>=r || n<0 || n>=c || !status[m][n])
        {
            return;
        }
        curr=curr->next[board[m][n]-'a'];
        if(!curr)
        {
            return;
        }
        status[m][n]=false;
        if(curr->whichWord>-1)
        {
            sameWord[curr->whichWord]=true;
        }
        getSameWord(board, r, c, m-1, n, curr, sameWord, status);
        getSameWord(board, r, c, m+1, n, curr, sameWord, status);
        getSameWord(board, r, c, m, n-1, curr, sameWord, status);
        getSameWord(board, r, c, m, n+1, curr, sameWord, status);
        status[m][n]=true;
    }
};