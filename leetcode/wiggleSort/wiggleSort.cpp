class Solution {
public:
    void wiggleSort1(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
        {
            return;
        }
        int mid=(len%2)?((len>>1)+1):(len>>1);
        quickSelect(nums, 0, len, mid);
        int pivot=nums[mid];
        int j=0, i=0, k=len-1;
        while(j<k)
        {
            if(nums[j]>pivot)
            {
                swap(nums[j], nums[k]);
                --k;
            }
            else if(nums[j]<pivot)
            {
                swap(nums[i], nums[j]);
                ++i;
                ++j;
            }
            else 
            {
                ++j;
            }
        }
        vector<int> numsTemp=nums;
        for(int i=0, j=0; i<len; ++i, ++j)
        {
            nums[i]=numsTemp[mid-1-j];
            ++i;
            if(i>=len)
            {
                break;
            }
            nums[i]=numsTemp[len-1-j];
        }

    }
    void quickSelect(vector<int> &nums, int start, int end, int n)
    {
        int pivot=nums[end-1];
        int i=start,
            j=start;
        while(j<end)
        {
            if(nums[j]<pivot)
            {
                swap(nums[j], nums[i]);
                ++i;
                ++j;
            }
            else
            {
                ++j;
            }
        }
        swap(nums[end-1], nums[i]);
        if(i>n)
        {
            quickSelect(nums, start, i, n);
        }
        else if(i<n)
        {
            quickSelect(nums, i+1, end, n);
        }

    }
	
	void wiggleSort2(vector<int>& nums) {
        int len=nums.size();
        if(len<2)
        {
            return;
        }
        auto midPtr=nums.begin()+(len>>1);
        nth_element(nums.begin(), midPtr, nums.end());
        int pivot=*midPtr;
        int j=0, i=0, k=len-1;
        while(j<k)
        {
            if(nums[j]>pivot)
            {
                swap(nums[j], nums[k]);
                --k;
            }
            else if(nums[j]<pivot)
            {
                swap(nums[i], nums[j]);
                ++i;
                ++j;
            }
            else 
            {
                ++j;
            }
        }
        if(len%2)
        {
            ++midPtr;
        }
        vector<int> tmp1(nums.begin(), midPtr);
        vector<int> tmp2(midPtr, nums.end());
        int indx=0;
        for(vector<int>::reverse_iterator rit=tmp1.rbegin(); rit!=tmp1.rend(); ++rit)
        {
            nums[indx]=*rit;
            indx+=2;
        }
        indx=1;
        for(vector<int>::reverse_iterator rit=tmp2.rbegin(); rit!=tmp2.rend(); ++rit)
        {
            nums[indx]=*rit;
            indx+=2;
        }
    }
	
};