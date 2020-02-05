class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        if(r==0)
        {
            return false;
        }
        int c=matrix[0].size();
        if(c==0)
        {
            return false;
        }
        int i=0, j=c-1;
        while(i<r && j>=0)
        {
            if(target>matrix[i][j])
            {
                i++;
            }
            else if(target<matrix[i][j])
            {
                j--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};