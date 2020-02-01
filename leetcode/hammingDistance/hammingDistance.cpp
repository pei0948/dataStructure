class Solution {
public:
    int hammingDistance(int x, int y) {
        int distan=0;
        while(x || y)
        {
            if(x==0)
            {
                while(y)
                {
                    if(y & 1)
                    {
                        distan++;
                    }
                    y>>=1;
                }
            }
            else if(y==0)
            {
                while(x)
                {
                    if(x & 1)
                    {
                        distan++;
                    }
                    x>>=1;
                }
            }
            else
            {
                if((x & 1)!=(y & 1))
                {
                    distan++;
                }
                x>>=1;
                y>>=1;
            }
        }
        return distan;
    }
};