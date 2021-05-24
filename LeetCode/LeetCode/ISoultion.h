#pragma once

#include <assert.h>

class ISolution
{
public:
	virtual void Drive() = 0;
};

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Definition for singly - linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class utilClass
{
public :
	static ListNode* CreateList(const std::vector<int>& sv)
	{
		ListNode* first(nullptr);
		ListNode* curNode(nullptr);
		for (const auto& val : sv)
		{
			if (first == nullptr)
			{
				first = new ListNode(val);
				curNode = first;
				continue;
			}
			curNode->next = new ListNode(val);
			curNode = curNode->next;
		}
		return first;
	}

};