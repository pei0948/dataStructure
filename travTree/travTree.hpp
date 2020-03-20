
#include "stdafx.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <typename T>
struct TreeNode
{
	T val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(T v=0, TreeNode *l=nullptr, TreeNode *r=nullptr):val(v), left(l),right(r){}
};

template <typename T>
void travTreeIn_R(TreeNode<T> *root)
{
	if (root == nullptr)
	{
		return;
	}
	travTreeIn_R(root->left);
	printV(root->val);
	travTreeIn_R(root->right);
}
template <typename T>
void travTreeIn_I(TreeNode<T> *root)
{
	if (root == nullptr)
	{
		return;
	}
	TreeNode<T> *curr = root;
	stack<TreeNode<T>*> nodes;
	while (curr!=nullptr || !nodes.empty()) {
		if (curr == nullptr)
		{
			curr = nodes.top();
			nodes.pop();
			printV(curr->val);
			curr = curr->right;
		}
		else
		{
			nodes.push(curr);
			curr = curr->left;
		}
	}
}

template <typename T>
void travTreePre_R(TreeNode<T> *root)
{
	if (root == nullptr)
	{
		return;
	}
	printV(root->val);
	travTreePre_R(root->left);
	travTreePre_R(root->right);
}
template <typename T>
void travTreePre_I(TreeNode<T> *root)
{
	if (root == nullptr)
	{
		return;
	}
	TreeNode<T> *curr = root;
	stack<TreeNode<T>*> nodes;
	while (curr!=nullptr || !nodes.empty()) {
		if (curr == nullptr)
		{
			curr = nodes.top();
			nodes.pop();
			curr = curr->right;
		}
		else
		{
			printV(curr->val);
			nodes.push(curr);
			curr = curr->left;
		}
	}
}

template <typename T>
void travTreePost_R(TreeNode<T> *root)
{
	if (root == nullptr)
	{
		return;
	}
	travTreePost_R(root->left);
	travTreePost_R(root->right);
	printV(root->val);
}
template <typename T>
void travTreePost_I(TreeNode<T> *root)
{
	if (root == nullptr)
	{
		return;
	}
	TreeNode<T> *curr = root,
				*last = root;
	stack<TreeNode<T>*> nodes;
	nodes.push(curr);
	while (!nodes.empty())
	{
		curr = nodes.top();
		if ((curr->left == nullptr && curr->right == nullptr)
			|| (curr->right == nullptr && last == curr -> left)
			|| (last == curr->right))
		{
			printV(curr->val);
			last = curr;
			nodes.pop();
		}
		else
		{
			if (curr->right != nullptr)
			{
				nodes.push(curr->right);
			}
			if (curr->left != nullptr)
			{
				nodes.push(curr->left);
			}
		}
	}
}

template <typename T>
void travTreeLevel_I(TreeNode<T> *root)
{
	if (root == nullptr)
	{
		return;
	}
	TreeNode<T> *curr = root;
	queue<TreeNode<T>*> nodes;
	nodes.push(curr);
	while (!nodes.empty())
	{
		curr = nodes.front();
		nodes.pop();
		if (curr == nullptr)
		{
			continue;
		}
		printV(curr->val);
		nodes.push(curr->left);
		nodes.push(curr->right);
	}
}

template <typename T>
void printV(T val)
{
	cout << val << " ";
}
template <typename T>
void printV(vector<T> &nums)
{
	for (T &num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
}

int main()
{
	TreeNode<int> *llNode = new TreeNode<int>(2);
	TreeNode<int> *lrNode = new TreeNode<int>(5);
	TreeNode<int> *lNode = new TreeNode<int>(5, llNode, lrNode);

	TreeNode<int> *rrNode = new TreeNode<int>(8);
	TreeNode<int> *rNode = new TreeNode<int>(7, nullptr, rrNode);

	TreeNode<int> *root = new TreeNode<int>(6, lNode, rNode);

	cout << "preTrav" << endl;
	travTreePre_R(root);
	cout << endl;
	travTreePre_I(root);
	cout << endl<<endl;

	cout << "inTrav" << endl;
	travTreeIn_R(root);
	cout << endl;
	travTreeIn_I(root);
	cout << endl<<endl;

	cout << "postTrav" << endl;
	travTreePost_R(root);
	cout << endl;
	travTreePost_I(root);
	cout << endl<<endl;

	cout << "levelTrav" << endl;
	travTreeLevel_I(root);
	cout << endl;


	system("pause");
    return 0;
}
