#include <algorithm>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> *indexS=NULL;
        vector<int> numsTemp=nums;
        int len=nums.size();
        if(len<=1)
        {
            return *indexS;
        }
        sort(numsTemp.begin(), numsTemp.end());
        for(int j=len-1; j>0; j--)
        {
            int downIndex=getDownIndex(numsTemp, target, j);
            if(downIndex>=0)
            {
                if(numsTemp[downIndex]+numsTemp[j]==target)
                {
                    indexS=new vector<int>();
                    for(int i=0; i<len; i++)
                    {
                        if(nums[i]==numsTemp[downIndex])
                        {
                            indexS->push_back(i);
                        }
                        else if(nums[i]==numsTemp[j])
                        {
                            indexS->push_back(i);
                        }
                    }

                    return *indexS;
                }
            }
            else
            {
                return *indexS;
            }
        }
        return *indexS;
    }

    int getDownIndex(vector<int> &nums, int v, int supIndex)
    {
        for(int i=0; i<supIndex; i++)
        {
            if((nums[i]+nums[supIndex])>=v)
            {
                return i;
            }
        }
        return -1;
    }
};