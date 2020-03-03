class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int cLen=coins.size();
        if(cLen==0)
        {
            return -1;
        }
        int resLen=amount+1;
        vector<int> res(resLen, INT_MAX);
        res[0]=0;
        
        for(int i=1; i<resLen; ++i)
        {
            for(int j=0; j<cLen; ++j)
            {
                if(coins[j]<i)
                {
                    if(res[i-coins[j]]!=INT_MAX)
                    {
                        res[i]=min(res[i], res[i-coins[j]]+1);
                    }
                }
                else if(coins[j]==i)
                {
                    res[i] = 1;
                }

            }
        }
        return (res[amount]==INT_MAX?-1:res[amount]);
    }
	
	int minCnt=INT_MAX;
    int coinChange(vector<int>& coins, int amount) {
        int cLen=coins.size();
        if(cLen==0)
        {
            return -1;
        }
        sort(coins.begin(), coins.end());
        dfs(coins, amount, 0, cLen-1);
        return (minCnt==INT_MAX?-1:minCnt);
    }
    void dfs(vector<int> &coins, int amount, int cnt, int index)
    {
        if(index<0 || cnt+amount/coins[index]>=minCnt)//发现该面值比上一个面值消耗更多数量钱币时，便不再往下寻找
        {
            return;
        }
        if(!(amount%coins[index]))
        {
            minCnt=min(minCnt, cnt+amount/coins[index]);
            return;
        }
        for(int i=amount/coins[index]; i>=0; --i)
        {
            dfs(coins, amount-i*coins[index], cnt+i, index-1);
        }
    }
};
