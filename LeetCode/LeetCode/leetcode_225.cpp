#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/implement-stack-using-queues/
/// </summary>
/// <returns></returns>
/// 
/// queue�� �̿��� stack �����
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
                //���� ������
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

	// ISolution��(��) ���� ��ӵ�
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

