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
    int nth=0, res;
    int kthSmallest(TreeNode* root, int k) {
        medTrav(root, k);
        return res;
    }
    void medTrav(TreeNode *tn, int k)
    {
        if(!tn)
        {
            return;
        }
        else
        {
            medTrav(tn->left, k);
            nth++;
            if(nth==k)
            {
                res=tn->val;
                return;
            }
            medTrav(tn->right, k);
        }
    }
 int kthSmallest2(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode *curr=root;
        int nth=0;
        while(!s.empty() || curr)
        {
            if(curr)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                curr=s.top();
                s.pop();
                nth++;
                if(nth==k)
                {
                    return curr->val;
                }
                curr=curr->right;
            }
        }
        return -1;
    }

};