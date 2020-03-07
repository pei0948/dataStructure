class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res=0;
        int cnt=0;
        while(n)
        {
            res<<=1;
            res^=(n&1);
            n>>=1;
            ++cnt;
        }
        if(cnt!=0)
        {
            res<<=(32-cnt);
        }
        return res; 
    }
};