#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/add-two-numbers/
/// </summary>
/// <param name="l1"> List 1 </param>
/// <param name="l2"> List 2</param>
/// <returns>2개의 List의 각자리값을 더해서 출력</returns>
/// 값이 증가할 경우 그다음 순서의 숫자 ++
/// 
/// l1 = [2,4,3] , l2 = [5,6,4]
/// output : 7,0,8
/// 
/// explanation : 342 + 465
/// 
/// 
class LeetCode_2 : public ISolution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* resList = new ListNode(l1->val + l2->val);

        l1 = l1->next;
        l2 = l2->next;

        ListNode* prevNode = resList;
        bool isPrevBig(prevNode->val >= 10 ? true : false);
        prevNode->val %= 10;

        while (l1 != nullptr || l2 != nullptr)
        {
            ListNode* nextNode = new ListNode();
            if (isPrevBig)
                nextNode->val += 1;

            if (l1 != nullptr)
            {
                nextNode->val += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                nextNode->val += l2->val;
                l2 = l2->next;
            }

            if (nextNode->val >= 10)
            {
                isPrevBig = true;
                nextNode->val %= 10;
            }
            else
                isPrevBig = false;

            prevNode->next = nextNode;
            prevNode = nextNode;
        }

        if (isPrevBig)
        {
            ListNode* nextNode = new ListNode(1);
            prevNode->next = nextNode;
        }

        return resList;
    }

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{

	}
};

