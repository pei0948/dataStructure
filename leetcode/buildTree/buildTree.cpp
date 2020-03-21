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
private:
    unordered_map<int, int> loc;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int lenPre=preorder.size(),
            lenIn=inorder.size();
        if(lenPre<=0 || lenIn<=0 || lenPre!=lenIn)
        {
            return nullptr;
        }
        for(int i=0; i<lenIn; ++i)
        {
            loc[inorder[i]]=i;
        }
        return subTree(preorder, 0, lenPre, inorder, 0, lenIn);
    }
    TreeNode *subTree(vector<int> &preorder, int startPreOrder, int endPreOrder,
                        vector<int> &inorder, int startInOrder, int endInOrder)
                        {
                            if(startPreOrder>=endPreOrder 
                            || startInOrder>=endInOrder 
                            || endPreOrder-startPreOrder!=endInOrder-startInOrder)
                            {
                                return nullptr;
                            }
                            int rootV=preorder[startPreOrder];
                            TreeNode *root=new TreeNode(rootV);
                            int idx;
                            if(loc.count(rootV)==0)
                            {
                                return nullptr;
                            }
                            else
                            {
                                idx=loc[rootV];
                            }
                            TreeNode *leftTree=subTree(preorder, startPreOrder+1, idx-startInOrder+startPreOrder+1,
                                                    inorder, startInOrder, idx);
                            TreeNode *rightTree=subTree(preorder, idx-startInOrder+startPreOrder+1, endPreOrder,
                                                    inorder, idx+1, endInOrder);
                            root->left=leftTree;
                            root->right=rightTree;
                            return root;
                        }
};