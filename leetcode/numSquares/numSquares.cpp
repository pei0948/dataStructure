class Solution {
public:
    vector<int> res;
    int numSquares1(int n) {
        vector<int> dp(n+1, 0);
        for(int i=1; i<=n; ++i)
        {
            dp[i]=i;
            for(int j=1; j*j<=i; ++j)
            {
                dp[i]=min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
	
    int numSquares2(int n) {
        while(!(n%4))
        {
            n/=4;
        }
        if(n%8==7)
        {
            return 4;
        }
        int a, b;
        for(a=0; a*a<n; ++a)
        {
            b=pow(n-a*a, 0.5);
            if(a*a+b*b==n)
            {
                return !!a+!!b;
            }
        }
        return 3;
    }
};