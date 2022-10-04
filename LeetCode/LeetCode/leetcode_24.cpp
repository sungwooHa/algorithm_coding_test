#pragma once
#include "ISoultion.h"
#include <algorithm>
/// <summary>
/// https://leetcode.com/problems/swap-nodes-in-pairs/
/// </summary>
/// <returns></returns>
class LeetCode_24 : public ISolution {
public:
	//lined list 가 주어진다
	//인접한 2개의 노드를 swap
	//1,2,3,4 -> 2,1,4,3

	//count를 세면서 바꿔야할 node와 그렇지 않은 노드 찾기.


	//cnt는 1부터 시작
	//짝수 일때 (2,4,6..) 만 swap
	void helper(ListNode* pPrev, ListNode* pCur, ListNode* pNext, const int cnt)
	{
		//1,3,4
		if (cnt % 2 == 1)
		{
			if (pNext != nullptr)
			{
				pPrev->next = pNext;
				auto pNextNext = pNext->next;
				pCur->next = pNextNext;
				pNext->next = pCur;
				pCur = pPrev->next;
			}
			else if (pNext == nullptr)
			{
				return;
			}
		}

		if(pCur->next != nullptr)
			helper(pCur, pCur->next, pCur->next->next, cnt + 1);

		return;
	}

	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr)
			return head;

		if (head->next == nullptr)
			return head;

		if (head->next->next == nullptr)
		{
			head->next->next = head;
			head = head->next;
			head->next->next = nullptr;
			return head;
		}
		else
		{
			auto pCur = head;
			head = head->next;
			pCur->next = head->next;
			head->next = pCur;
			helper(head, pCur, pCur->next, 2);
			return head;
		}
	}

	ListNode* swapPairs_2(ListNode* head) {
		if (!head || !head->next)
			return head;

		auto pNext = head->next;
		head->next = swapPairs_2(pNext->next);
		pNext->next = head;
		return pNext;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		auto pNode = utilClass::CreateList({ 1, 2, 3, 4});
		swapPairs(pNode); //2 1 4 3

		pNode = utilClass::CreateList({});
		swapPairs(pNode); //{};

		pNode = utilClass::CreateList({1});
		swapPairs(pNode); //{1};

		pNode = utilClass::CreateList({1,2});
		swapPairs(pNode); //{2,1};

		pNode = utilClass::CreateList({ 1, 2,3,4,5});
		swapPairs(pNode); //{2,1,4,3,5};
	}

};