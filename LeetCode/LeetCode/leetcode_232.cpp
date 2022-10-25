#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/implement-queue-using-stacks/
/// </summary>
/// <returns></returns>
/// 
class LeetCode_232 : public ISolution {
public:
    class MyQueue {
    public:
        MyQueue() {

        }

        void push(int x) {
            m_input.push(x);
        }

        int pop() {
            auto val = peek();
            m_output.pop();
            return val;
        }

        int peek() {
            if (m_output.empty())
            {
                while (m_input.size())
                {
                    m_output.push(m_input.top());
                    m_input.pop();
                }
            }
            return m_output.top();
        }

        bool empty() {
            return m_input.empty() && m_output.empty();
        }
        std::stack<int> m_input, m_output;
    };

    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
    }
};

