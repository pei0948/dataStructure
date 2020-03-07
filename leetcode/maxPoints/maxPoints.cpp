class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int len=points.size();
        if(len<3)
        {
            return len;
        }
        int res=INT_MIN;
        for(int i=0; i<len; ++i)
        {
            for(int j=i+1; j<len; ++j)
            {
                if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
                {
                    continue;
                }
                long long dx=(long long)(points[j][0]-points[i][0]);
                long long dy=(long long)(points[j][1]-points[i][1]);
                int cnt=0;
                for(int k=0; k<len; ++k)
                {                
                    if(dx*(points[k][1]-points[i][1])==dy*(points[k][0]-points[i][0]))
                    {
                        ++cnt;
                    }
                }

                res=max(res, cnt);
                if(res>len/2)
                {
                    return res;
                }
            }
        }
        return ((res==INT_MIN)?len:res);
    }
};