
class Solution{
	public£º
		vector<int> twoSum(vector<int> &nums, int target)
		{
			map<int, int> m;
			int len=nums.size();
			for(int i=0; i<len; i++)
			{
				if(m.count(nums[i]))
				{
					return {m[nums[i]], i};
				}
				else
				{
					m[target-nums[i]]=i;
				}
			}
			return {-1, -1};
		}
}
