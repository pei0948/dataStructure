class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        if(row<1)
        {
            return false;
        }
        int col=board.front().size();
        if(col<1)
        {
            return false;
        }
        int len=word.size();
        if(len<1)
        {
            return false;
        }
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int r=0; r<row; ++r)
        {
            for(int c=0; c<col; ++c)
            {
                if(hasPath(board, row, col, r, c, word, len, 0, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool hasPath(vector<vector<char>> &board, int &row, int &col, int currR, int currC, string &word, int &len, int idx, vector<vector<bool>> &visited)
    {
        if(currR<0 || currR>=row 
            || currC<0 || currC>=col
            || visited[currR][currC]
            || board[currR][currC]!=word[idx])
        {
            return false;
        }
        visited[currR][currC]=true;
        ++idx;
        if(idx>=len)
        {
            return true;
        }
        bool path=false;
        path=hasPath(board, row, col, currR, currC-1, word, len, idx, visited)
            || hasPath(board, row, col, currR, currC+1, word, len, idx, visited)
            || hasPath(board, row, col, currR-1, currC, word, len, idx, visited)
            || hasPath(board, row, col, currR+1, currC, word, len, idx, visited);
        if(path)
        {
            return true;
        }
        visited[currR][currC]=false;
        --idx;
        return false;
    }
};