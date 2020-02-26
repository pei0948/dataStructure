/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
        {
            return "[]";
        }
        string res="[";
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *v;
        while(!q.empty())
        {
            v=q.front();
            q.pop();
            if(v)
            {
                res+=to_string(v->val)+",";
                q.push(v->left);
                q.push(v->right);
            }
            else
            {
                res+="null,";
            }
        }
        int end=res.size()-1;
        while(end>=0 && (res[end]<48 || res[end]>57))
        {
            end--;
        }
        if(end<0)
        {
            return "[]";
        }
        else
        {
            return res.substr(0, end+1)+"]";
        }
    }

    TreeNode* getTreeNode(string &data, int &i)
    {
        if(data[i]=='n')
        {
            i=i+5;
            return NULL;
        }
        bool negative=false;
        if(data[i]=='-')
        {
            negative=true;
            i++;
        }
        int num=0;
        while(data[i]>=48 && data[i]<=57)
        {
            num=num*10-'0'+data[i];
            i++;
        }
        i++;
        num=(negative?-num:num);
        TreeNode *tn=new TreeNode(num);
        return tn;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="[]")
        {
            return NULL;
        }
        int lenStr=data.size()-1;
        int i=1, j=1;
        queue<TreeNode*> q;
        TreeNode *root=getTreeNode(data, i);
        q.push(root);
        TreeNode *curr=root;
        j=i;
        while(i<lenStr && j<lenStr)
        {
            curr=q.front();
            q.pop();
            if(curr)
            {
                TreeNode *leftNode=getTreeNode(data, j);
                curr->left=leftNode;
                q.push(leftNode);
                if(j<lenStr)
                {
                    TreeNode *rightNode=getTreeNode(data, j);
                    curr->right=rightNode;
                    q.push(rightNode);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));