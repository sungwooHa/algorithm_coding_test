#pragma once
#include "ISoultion.h"

/// <summary>
/// </summary>
class LeetCode_21 : public ISolution
{
private:


public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (!l1 && !l2)
			return NULL;
		ListNode* first(nullptr);
		ListNode* curNode(nullptr);

		while (true)
		{
			if (!curNode)
			{
				if (!l1)
					return l2;
				if (!l2)
					return l1;

				if (l1->val < l2->val)
				{
					curNode = l1;
					l1 = l1->next;
				}
				else
				{
					curNode = l2;
					l2 = l2->next;
				}
				first = curNode;
			}

			if (l1 == nullptr)
			{
				curNode->next = l2;
				break;
			}

			if (l2 == nullptr)
			{
				curNode->next = l1;
				break;
			}

			if (l1->val < l2->val)
			{
				curNode->next = l1;
				l1 = l1->next;
			}
			else
			{
				curNode->next = l2;
				l2 = l2->next;
			}
			curNode = curNode->next;
		}

		return first;

	}
	virtual void Drive() override
	{
		auto list1 = utilClass::CreateList({ 1, 2, 4 });
		auto list2 = utilClass::CreateList({ 1, 3, 4 });
		auto answer = mergeTwoLists(list1, list2);

		while (answer != nullptr)
		{
			std::cout << answer->val << std::endl;
			answer = answer->next;
		}
	}

};

