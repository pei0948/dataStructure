class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len=numbers.size();
        if(len<1)
        {
            return -1;
        }
        int start=0,
            end=len-1,
            idxMid;
        while(start<end)
        {
            idxMid=((start+end)>>1);
            if(numbers[idxMid]<numbers[start])
            {
                end=idxMid;
            }
            else if(numbers[idxMid]>numbers[end])
            {
                start=idxMid+1;
            }
            else
            {
                --end;
            }
        }
        return numbers[start];
    }
};