#pragma once
#include "ISoultion.h"
#include <algorithm>
/// <summary>
/// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
/// </summary>
/// <returns></returns>
class LeetCode_19 : public ISolution {
public:

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		//맨뒤에서 부터 n번째 노드 지우기.

		std::vector<ListNode*> arrListNode;

		auto ptr = head;
		while (ptr != nullptr)
		{
			arrListNode.push_back(ptr);
			ptr = ptr->next;
		}

		if (arrListNode.size() - n < 0)
			return {};

		//size 5
		// n = 1
		//size - n -1 //직전 //if null? -> return {};
		//size - n + 1 // 다음 //if null? -> next == nullptr;

		const int& listSize = arrListNode.size();
		//직전 index 가 -1 일 경우 return {};
		const int& prevIdx = (listSize - n) - 1;
		const int& nextIdx = (listSize - n) + 1;
		const int& targetIdx = listSize - n;
		if (prevIdx < 0)
		{
			if (arrListNode.size() > 1)
			{
				//target idx가 0
				return arrListNode[1];
			}
			else
				return {};
		}


		arrListNode[prevIdx]->next = [&]() -> ListNode* {
			if (nextIdx >= arrListNode.size())
				return {};

			return arrListNode[nextIdx];
		}();

		return arrListNode.front();
	}


	void removeNode(ListNode* node, int& n)
	{
		if (!node) return;

		removeNode(node, n);

		if (n == 0)
			node->next = node->next->next;

		n--;
	}

	ListNode* removeNthFromEnd_recursive(ListNode* node, int n)
	{
		auto dummy = new ListNode(-1);
		dummy->next = node;

		removeNode(dummy, n);
		return dummy->next;
	}

	virtual void Drive() override
	{
		auto pNode = utilClass::CreateList({1,2,3,4,5});
		removeNthFromEnd(pNode, 2);

		while (pNode != nullptr)
		{
			cout << pNode->val;
			pNode = pNode->next;
		}

		pNode = utilClass::CreateList({ 1});
		removeNthFromEnd(pNode, 1);
	}
};