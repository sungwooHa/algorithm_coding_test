#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/intersection-of-two-linked-lists/
/// </summary>
/// <param name="HeadA"> Linked list </param>
/// <param name="HeadB"> Linked list </param>
/// 
/// 교집합 node를 list로 만들어서 합쳐서 return,.
/// 
class LeetCode_160 : public ISolution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
	{
		ListNode* res = nullptr;
		bool find(false);

		ListNode *curA, *curB;

		while (headA)
		{
			curA = headA;
			curB = headB;
			while (curA && curB)
			{
				//curA와 curB가 있어야함.
				if (curA == curB)
				{
					//curA, curB 같을때
					//마지막까지 같아야함.

					if (!find)
					{
						//최초 발견
						res = curB;
						find = true;
					}
					//둘다 다음으로 넘김
					curA = curA->next;
					curB = curB->next;
				}
				else
				{
					//curA, curB 다를때
					//curB만 다음으로 옮겨서 확인
					//curA는 다시 next;

					find = false;
					res = nullptr;
					curA = headA;
					curB = curB->next;
				}
			}

			if (find)
			{
				//찾았을때
				break;
			}

			//찾지 못했을떄
			//HeadA = headA->next;
			headA = headA->next;
		}
		return res;
	}
	ListNode* getIntersectionNode_best(ListNode* headA, ListNode* headB)
	{
		ListNode* curA = headA;
		ListNode* curB = headB;
		while (curA != curB)
		{
			curA = curA ? curA->next : headB;
			curB = curB ? curB->next : headA;
		}
		return curA;
	}



	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
	}
};

