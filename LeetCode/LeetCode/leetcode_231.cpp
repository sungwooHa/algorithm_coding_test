#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/power-of-two/
/// </summary>
/// <returns></returns>
/// range a~b
/// ���� ���� sorting���� array�� ��� ���ڸ� cover�϶�.
/// 
class LeetCode_231 : public ISolution {
public:
    //2�� �ŵ��������ΰ�?
    bool isPowerOfTwo(int n) {
        if (n <= 0) 
            return false;

        return (n & (n - 1)) == 0;
    }

    // ISolution��(��) ���� ��ӵ�
    virtual void Drive() override
    {
    }
};

