class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        int numRvs=x%10;
        x=x/10;
        if(x==0)
        {
            return true;
        }
        if(numRvs==0)
        {
            return false;
        }
        int numRmd=numRvs;
        int numErr=numRvs-x;
        while(numErr<0)
        {
            numRmd=x%10;
            numRvs=numRvs*10+numRmd;
            x=x/10;
            numErr=numRvs-x;
        }
        return (numErr==0 || (numErr>0 && ((numRvs/10-x)==0)));
    }
};