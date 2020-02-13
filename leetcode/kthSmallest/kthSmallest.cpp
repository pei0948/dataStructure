class Solution {
public:
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        if(matrix.empty())
        {
            return 0;
        }
        int n=matrix.size();
        priority_queue<int> num;
        for(int i=0; i<n; i++)
        {
            int j=0;
            for(; j<n; j++)
            {
                if(num.size()<k)
                {
                    num.push(matrix[i][j]);
                }
                else
                {
                    if(matrix[i][j]<num.top())
                    {
                        num.push(matrix[i][j]);
                        num.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(j==0)
            {
                break;
            }
        }
        return num.top();
    }
	int kthSmallest2(vector<vector<int>>& matrix, int k) {
        if(matrix.size()==0 || matrix[0].size()==0)
        {
            return -1;
        }
        int left=matrix[0][0], right=matrix.back().back(), mid;
        int cnt=0;
        while(left<right)
        {
            mid=(left+right)/2;
            cnt=getCount(matrix, mid);
            if(cnt<k)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        return left;
    }
    int getCount(vector<vector<int>> &matrix, int target)
    {
        int n=matrix.size();
        int i=n-1, j=0;
        int cnt=0;
        while(i>=0 && j<n)
        {
            if(matrix[i][j]>target)
            {
                i--;
            }
            else
            {
                cnt=cnt+i+1;
                j++;
            }
        }
        return cnt;
    }
};