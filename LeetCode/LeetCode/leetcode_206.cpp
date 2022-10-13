#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problemset/algorithms/?difficulty=EASY&page=1
/// </summary>
/// 
class LeetCode_206 : public ISolution {
public:
	ListNode* reverseList_ex(ListNode* head) 
	{
		ListNode* nextNode, * prevNode = nullptr;
		while (head)
		{
			nextNode = head->next;
			head->next = prevNode;
			prevNode = head;
			head = nextNode;
		}

		return prevNode;
	}

	ListNode* reverseList(ListNode* head) {
		if (!head) return head;

		std::vector<ListNode*> arr;

		while (head != nullptr)
		{
			arr.push_back(head);
			head = head->next;
		}

		for (int n = arr.size() - 1; n >= 0; --n)
		{
			if (n == 0)
				arr[n]->next = nullptr;
			else
				arr[n]->next = arr[n - 1];
		}
		
		return arr[arr.size() - 1];
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		auto pHead = utilClass::CreateList({ 1, 2,3,4,5});

		pHead = reverseList(pHead);

		while (pHead)
		{
			cout << pHead->val << endl;
			pHead = pHead->next;
		}

	}
};

