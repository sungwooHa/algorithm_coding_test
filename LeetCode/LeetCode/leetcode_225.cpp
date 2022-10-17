#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/implement-stack-using-queues/
/// </summary>
/// <returns></returns>
/// 
/// queue를 이용해 stack 만들기
/// stack : LIFO.
/// 
class LeetCode_225 : public ISolution {
public:
    class MyStack {
    public:
        MyStack() {
            q = std::queue<int>();
        }

        void push(int x) {
            q.push(x);
            for (int idx = 0; idx < q.size(); ++idx)
            {
                //순서 뒤집기
                q.push(q.front());
                q.pop();
            }
        }

        int pop() {
            auto val = q.front();
            q.pop();
            return val;
        }

        int top() {
            return q.front();
        }

        bool empty() {
            return q.empty();
        }
        
    private:
        std::queue<int> q;

    };

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
        MyStack myStack;
        myStack.push(1);
        myStack.push(2);
        auto val = myStack.top();
        auto val2 = myStack.pop();
        auto val3 = myStack.empty();
	}
};

