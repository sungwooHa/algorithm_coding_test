#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/remove-linked-list-elements/
/// </summary>
/// link의 head와 target val이 주어짐
/// delete target val on link
/// 

class LeetCode_203 : public ISolution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
		ListNode* first(nullptr);
		ListNode* curNode(nullptr);
		while (head)
		{
			if (head->val != val)
			{
				if (first == nullptr)
				{
					curNode = new ListNode(head->val);
					first = curNode;
				}
				else
				{
					curNode->next = new ListNode(head->val);
					curNode = curNode->next;
				}
			}

			head = head->next;
		}
		return first;

    }
    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
        std::vector<int> list;
        int val(0);
		ListNode* head;

        list = { 1, 2, 6, 3, 4, 5, 6 };
        val = 6;


		head = utilClass::CreateList(list);
		auto result = removeElements(head, val);

		while (result)
		{
			std::cout << result->val << " ";
			result = result->next;
		}
    }
};

