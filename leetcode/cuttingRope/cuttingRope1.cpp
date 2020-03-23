class Solution {
public:
    int cuttingRope1(int n) {
        if(n<4)
        {
            return n-1;
        }
        vector<int> product(n+1, 0);
        product[1]=1;
        product[2]=2;
        product[3]=3;
        int maxProd;
        for(int i=4; i<=n; ++i)
        {
            maxProd=INT_MIN;
            for(int j=1; j<=i/2; ++j)
            {
                maxProd=max(maxProd, product[j]*product[i-j]);
            }
            product[i]=maxProd;
        }
        return product[n];
    }

int cuttingRope2(int n) {
        if(n<4)
        {
            return n-1;
        }
        int rem=n%3,
            times=n/3;
        int product;
        switch(rem)
        {
            case 0:
                product=pow(3, times);
                break;
            case 1:
                product=pow(3, times-1)*4;
                break;
            case 2:
                product=pow(3, times)*2;
                break;
                
        }
        return product;
    }

};