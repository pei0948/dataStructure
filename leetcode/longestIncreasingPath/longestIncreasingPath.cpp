class Solution {
public:
    vector<vector<int>> res;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r=matrix.size();
        if(r<1)
        {
            return 0;
        }
        int c=matrix[0].size();
        if(c<1)
        {
            return 0;
        }
        res.resize(r);
        for(int i=0; i<r; ++i)
        {
            res[i].resize(c, INT_MIN);
        }
        int maxPath=INT_MIN;
        for(int i=0; i<r; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                if(res[i][j]==INT_MIN)
                {
                    setRes(matrix, r, c, i, j);
                }
                maxPath=max(res[i][j], maxPath);
            }
        }
        return maxPath;
    }
    void setRes(vector<vector<int>> &matrix, int &r, int &c, int currR, int currC)
    {
        int up=INT_MIN,
            down=INT_MIN,
            left=INT_MIN,
            right=INT_MIN;

        if(currR-1>=0 && matrix[currR][currC]>matrix[currR-1][currC])
        {
            if(res[currR-1][currC]==INT_MIN)
            {
                setRes(matrix, r, c, currR-1, currC);
            }  
            up=res[currR-1][currC];
        }

        if(currR+1<r && matrix[currR][currC]>matrix[currR+1][currC])
        {
            if(res[currR+1][currC]==INT_MIN)
            {
                setRes(matrix, r, c, currR+1, currC);
            }
            down=res[currR+1][currC];
        }

        if(currC-1>=0 && matrix[currR][currC]>matrix[currR][currC-1])
        {
            if(res[currR][currC-1]==INT_MIN)
            {
                setRes(matrix, r, c, currR, currC-1);
            }
            left=res[currR][currC-1];
        }

        if(currC+1<c && matrix[currR][currC]>matrix[currR][currC+1])
        {
            if(res[currR][currC+1]==INT_MIN)
            {
                setRes(matrix, r, c, currR, currC+1);
            }
            right=res[currR][currC+1];
        }

        int maxPath=max(max(up, down), max(left, right));
        res[currR][currC]=(maxPath==INT_MIN?1:maxPath+1);
    }
};