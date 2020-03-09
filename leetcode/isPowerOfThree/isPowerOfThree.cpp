class Solution {
public:
    bool isPowerOfThree1(int n) {
        if(n<=0)
        {
            return false;
        }

        while(!(n%3))
        {
            n/=3;
        }
        return n==1;
    }
	bool isPowerOfThree2(int n) {
        return (n>0) && !(1162261467%n);
    }
};