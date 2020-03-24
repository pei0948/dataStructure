class Solution {
public:
    int hammingWeight1(uint32_t n) //复数情况不适用
	{
        int cnt=0;
        while(n)
        {
            if(n&1)
            {
                ++cnt;
            }
            n>>=1;
        }
        return cnt;
    }
	int hammingWeight2(uint32_t n) //也适用于复数
	{
        int cnt=0;
        while(n)
        {
            ++cnt;
            n=(n-1)&n;
        }
        return cnt;
    }
};