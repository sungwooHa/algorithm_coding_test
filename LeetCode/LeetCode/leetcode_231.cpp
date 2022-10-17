#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/power-of-two/
/// </summary>
/// <returns></returns>
/// 
class LeetCode_231 : public ISolution {
public:
    //2�� �ŵ��������ΰ�?
    bool isPowerOfTwo(int n) {
        if (n <= 0) 
            return false;

        //��Ʈ����,
        //0000  : 0
        //0001  : 1
        //0010  : 2
        
        //0011  : 3
        //0100  : 4
        
        //0111  : 7
        //1000  : 8

        return (n & (n - 1)) == 0;
    }

    // ISolution��(��) ���� ��ӵ�
    virtual void Drive() override
    {
    }
};

