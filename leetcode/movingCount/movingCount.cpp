class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(m<0 || n<0 || k<0)
        {
            return 0;
        }
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        return getCnt(m, n, k, 0, 0, visited);
    }
    int getDigitSum(int num)
    {
        int sum=num%10;
        while((num/=10)>0)
        {
            sum+=(num%10);
        }
        return sum;
    }
    int getCnt(int &m, int &n, int &k, int r, int c, vector<vector<bool>> &visited)
    {
        if(r>=0 && r<m 
            && c>=0 && c<n
            && !visited[r][c]
            && getDigitSum(r)+getDigitSum(c)<=k)
        {
            visited[r][c]=true;
            int cnt=1
                    +getCnt(m, n, k, r, c-1, visited)
                    +getCnt(m, n, k, r, c+1, visited)
                    +getCnt(m, n, k, r-1, c, visited)
                    +getCnt(m, n, k, r+1, c, visited);
            return cnt;
        }
        else
        {
            return 0;
        }
    }
};