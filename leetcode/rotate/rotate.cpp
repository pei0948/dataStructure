class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        if(len<2)
        {
            return;
        }
        if(k==0)
        {
            return;
        }
        if(k>len)
        {
            k=k%len;
        }
        reverse(nums, 0, len-k-1);
        reverse(nums, len-k, len-1);
        reverse(nums, 0, len-1);
    }
    void reverse(vector<int> &nums, int low, int high)
    {
        while(low<high)
        {
            swap(nums[low], nums[high]);
            low++;
            high--;
        }
    }
};