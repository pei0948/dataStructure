class Solution {
public:
    int r, c;
    int numIslands(vector<vector<char>>& grid) {
        r=grid.size();
        if(r<1)
        {
            return 0;
        }
        c=grid[0].size();
        if(c<1)
        {
            return 0;
        }

        int cnt=0;
        for(int i=0; i<r; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                if(grid[i][j]=='1')
                {
                    infect(grid, i, j);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
    void infect(vector<vector<char>> &grid, int i, int j)
    {
        if(i<0 || i>=r
            || j<0 || j>=c
            || grid[i][j]!='1')
        {
            return;
        }
        grid[i][j]='2';
        infect(grid, i-1, j);
        infect(grid, i+1, j);
        infect(grid, i, j-1);
        infect(grid, i, j+1);
    }
};