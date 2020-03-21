class Solution {
public:
    int fib(int n) {
        if(n<2)
        {
            return n;
        }
        int prePre=0,
            pre=1,
            val;
        for(int i=2; i<=n; ++i)
        {
            val=prePre+pre;
            val%=1000000007;
            prePre=pre;
            pre=val;
        }
        return val;
    }
};