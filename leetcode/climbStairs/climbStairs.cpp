class Solution {
public:
    int climbStairs(int n) {
       if(n<2)
       {
           return n;
       } 
       int prePre=1;
       int pre=2;
       int result=2;
       for(int i=3; i<=n; i++)
       {
           result=prePre+pre;
           prePre=pre;
           pre=result;
       }
       return result;
    }
};