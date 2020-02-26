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
    TreeNode *res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        travTree(root, p, q);
        return res;
    }
    bool travTree(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if(!root)
        {
            return false;
        }
        int leftFound=(travTree(root->left, p, q)?1:0);
        int rightFound=(travTree(root->right, p, q)?1:0);
        int mid=((root==p || root==q)?1:0);
        if(mid+leftFound+rightFound>=2)
        {
            res=root;
        }
        return (leftFound+rightFound+mid>0);
    }
};