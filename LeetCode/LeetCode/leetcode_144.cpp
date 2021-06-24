#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/binary-tree-preorder-traversal/
/// </summary>
/// <param name="root"> root node of binaray tree </param>
/// <returns> result the preorder traversal of its nodes' values.</returns>
/// 
/// 
/**
* Definition for a binary tree node.
* struct TreeNode {
	*int val;
	*TreeNode* left;
	*TreeNode* right;
	*TreeNode() : val(0), left(nullptr), right(nullptr) {}
	*TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	*TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
	*
};
*/

class LeetCode_144 : public ISolution {
public:

	void preOrder(TreeNode* root, std::vector<int>& result)
	{
		if (!root)
			return;

		result.push_back(root->val);
		preOrder(root->left, result);
		preOrder(root->right, result);
	}
	vector<int> preorderTraversal(TreeNode* root)
	{
		//parents -> left -> right
		std::vector<int> result;
		preOrder(root, result);
		return result;
	}

	vector<int> preorderTraversal_stack(TreeNode* root)
	{
		std::vector<int> result;
		stack<TreeNode*> resStack;

		while (root || !resStack.empty())
		{
			if (root)
			{
				result.push_back(root->val);
				if (root->right)
					resStack.push(root->right);

				root = root->left;
			}
			else
			{
				root = resStack.top();
				resStack.pop();
			}
		}

		return result;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{

	}
};

