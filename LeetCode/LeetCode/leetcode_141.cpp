#pragma once
#include "ISoultion.h"
#include <unordered_set>

/// <summary>
/// https://leetcode.com/problems/linked-list-cycle/
/// </summary>
/// <param name="head"> ListNode *  </param>
///
/// <return> bool</return>
/// <return> 반복되면 true </return>
/// <return> 반복되지 않으면 false </return>
///  
/**
* Definition for singly - linked list.
* struct ListNode {
	*int val;
	*ListNode* next;
	*ListNode(int x) : val(x), next(NULL) {}
	*
};
*/

class LeetCode_141 : public ISolution
{
public:
	std::unordered_set<ListNode**>  hash;
	bool hasCycle_hash(ListNode* head)
	{
		if (!head)
			return false;

		if (hash.find(&head) != hash.end())
			return true;

		hash.insert(&head);
		return hasCycle_hash(head->next);
	}

	bool hasCycle(ListNode* head)
	{
		if (!head)
			return false;

		ListNode* slow = head; //1칸씩
		ListNode *fast = head; //2칸씩 순회하면 언젠간 만나겠지.

		while (fast->next && fast->next->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}

		return false;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		std::vector<int> tmpList = { -21, 10, 17, 8, 4, 26, 5, 35, 33, -7, -16, 27, -12, 6, 29, -12, 5, 9, 20, 14, 14, 2, 13, -24, 21, 23, -21, 5 };

		auto head = utilClass::CreateList(tmpList);

		assert(hasCycle_hash(head) == false);
	}
};