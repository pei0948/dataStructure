class Solution {
public:
    struct TreeNode
    {
        int val;
        int count=0;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int v):val(v), left(nullptr), right(nullptr){}
    };
    TreeNode* insertTreeNode(TreeNode *root, int num, vector<int> &res,int index)
    {
        if(!root)
        {
            root=new TreeNode(num);
        }
        else if(num <= root->val)
        {
            ++(root->count);
            root->left=insertTreeNode(root->left, num, res, index);
        }
        else if(num > root->val)
        {
            res[index]=res[index] + root->count + 1;
            root->right=insertTreeNode(root->right, num, res, index);
        }
        return root;
    }
    vector<int> countSmaller1(vector<int>& nums) {
        int len=nums.size();
        if(len<1)
        {
            return {};
        }
        if(len==1)
        {
            return {0};
        }
        vector<int> res(len, 0);
        TreeNode *root=new TreeNode(nums.back());
        for(int i=len-2; i>=0; --i)
        {
            root=insertTreeNode(root, nums[i], res, i);
        }
        return res;
    }
	
	////////////////////////////////////////
	vector<int> cnt;
    vector<int> index;
    vector<int> helper;

    vector<int> countSmaller2(vector<int>& nums) {
        int len=nums.size();
        if(len<1)
        {
            return {};
        }
        if(len==1)
        {
            return {0};
        }
        cnt.resize(len, 0);
        helper.resize(len);
        for(int i=0; i<len; ++i)
        {
            index.push_back(i);
        }
        mergeSort(nums, 0, len-1);
        return cnt;
    }

    void mergeSort(vector<int> &nums, int low, int high)
    {
        if(low==high)
        {
            return;
        }
        int mid=((low+high)>>1);
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        int left=low, right=mid+1, copyIndex=low;
        while(left<=mid && right<=high)
        {
            if(nums[index[left]] <= nums[index[right]])
            {
                cnt[index[left]]+=right-mid-1;
                helper[copyIndex]=index[left];
                ++left;
                ++copyIndex;
            }
            else
            {
                helper[copyIndex]=index[right];
                ++copyIndex;
                ++right;
            }
        }
        while(left<=mid)
        {
            cnt[index[left]]+=right-mid-1;
            helper[copyIndex]=index[left];
            copyIndex++;
            left++;
        }
        while(right<=high)
        {
            helper[copyIndex]=index[right];
            copyIndex++;
            right++;
        }
        for(int i=low; i<=high; ++i)
        {
            index[i]=helper[i];
        }
    }
};