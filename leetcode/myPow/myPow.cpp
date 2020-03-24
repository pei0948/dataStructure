class Solution {
public:
    bool equal(double a, double b)
    {
        return fabs(a-b)<0.000001;
    }
    double myPow(double x, int n) {
        if(equal(x, 0.0) || equal(x, 1.0))
        {
            return x;
        }
        if(n==0)
        {
            return 1;
        }
        int exp=n;
        double res=1.0;
        while(exp)
        {
            if(exp&1)
            {
                res*=x;
            }
            x*=x;
            exp/=2;
        }
        return n>0?res:1/res;
    }
};