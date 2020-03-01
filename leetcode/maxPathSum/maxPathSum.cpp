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
    int res=INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        getMax(root);
        return res;
    }
    int getMax(TreeNode *root)//相当于后序遍历
    {
        if(!root)
        {
            return 0;
        }
        int left=max(0, getMax(root->left));
        int right=max(0, getMax(root->right));
        res=max(res, root->val+left+right);//以当前节点为根节点，判断其保护左右子树后，是否比当前路径和大
        return max(left, right)+root->val;//若当前节点为子节点，需返回保护该节点的最大路径长，也就是左右节点中的最大值加上当前节点的值
    }
};