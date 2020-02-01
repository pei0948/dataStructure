/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int cnt=0;
    vector<int> subSum;

    int calDepth(TreeNode *root)
    {
        if(!root)
        {
            return 0;
        }
        return (max(calDepth(root->left), calDepth(root->right))+1);
    }
    void travTree(TreeNode *tn, int sum, int d)
    {
        if(!tn)
        {
            return;
        }
        subSum[d]=subSum[d-1]+tn->val;
        for(int i=0; i<d; i++)
        {
            if((subSum[d]-subSum[i])==sum)
            {
                cnt++;
            }
        }
        travTree(tn->left, sum, d+1);
        travTree(tn->right, sum, d+1);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root)
        {
            return 0;
        }
        int depth=calDepth(root);
        subSum.resize(depth+1, 0);
        travTree(root, sum, 1);
        return cnt;
    }
};