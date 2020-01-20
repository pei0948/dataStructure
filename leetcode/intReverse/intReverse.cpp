class Solution {
public:
    int reverse(int x) {
        bool signN=false;
        long long xTemp=x;
        long long s=0;
        if(x<0)
        {
            xTemp=-xTemp;
            signN=true;
        }
        else if(x==0)
        {
            return x;
        }

        int low=getLow(xTemp);
        xTemp=xTemp/10;
        s=s*10+low;
		while(xTemp!=0)
        {
            low=getLow(xTemp);
            s=s*10+low;
            xTemp=xTemp/10;
        }
        if(signN)
        {
            s=-s;
        }
        if(s>2147483647 || s<-2147483648)
        {
            return 0;
        }
        return s;
    }
    int getLow(long long x)
    {
        return (int)(x%10);
    }
};