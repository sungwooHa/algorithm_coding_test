#pragma once
#include "ISoultion.h"
#include <stack>

/// <summary>
/// https://leetcode.com/problems/min-stack/
/// </summary>
/// stack 만들기!
/// min 값을 구할수 있어야함.
/// 
class LeetCode_155 : public ISolution 
{
private:
    std::stack<std::pair<int, int>> minStack;
public:
    /** initialize your data structure here. */

    LeetCode_155()
    {
    }
    void push(int val)
    {
        if (minStack.empty())
        {
            minStack.push({ val, val });
        }
        else
        {
            minStack.push({ val, std::min(val, minStack.top().second) });
        }
    }

    void pop() 
    {
        minStack.pop();
    }

    int top()
    {
        return minStack.top().first;
    }

    int getMin()
    {
        return minStack.top().second;
    }

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
	}
};

