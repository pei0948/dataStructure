class Solution {
public:
    int cuttingRope(int n) {
        if(n<4)
        {
            return n-1;
        }
        int rem=n%3,
            times=n/3;
        long long prod;
        switch(rem)
        {
            case 0:
                prod=getRem(1, times, 3);
                break;

            case 1:
                prod=getRem(getRem(1, times-1, 3), 2, 2);
                break;

            case 2:
                prod=getRem(getRem(1, times, 3), 1, 2);
                break;
        }
        return prod;
    }

    int getRem(long long prod, int times, int base)
    {
        for(int i=0; i<times; ++i)
        {
            prod=(prod*base)%1000000007;
        }
        return prod;
    }
};