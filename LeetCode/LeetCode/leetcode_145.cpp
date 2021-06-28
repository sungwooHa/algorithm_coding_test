#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/binary-tree-postorder-traversal/
/// </summary>
/// <param name="root"> root node of binaray tree </param>
/// <returns> result the postorder traversal of its nodes' values.</returns>
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

class LeetCode_145 : public ISolution {
public:

	void postOrder(TreeNode* root, std::vector<int>& result)
	{
		if (!root)
			return;

		postOrder(root->left, result);
		postOrder(root->right, result);
		result.push_back(root->val);
	}
	vector<int> postorderTraversal(TreeNode* root)
	{
		//left -> right-> root
		std::vector<int> result;
		postOrder(root, result);
		return result;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{

	}
};

