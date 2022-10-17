#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/power-of-two/
/// </summary>
/// <returns></returns>
/// 
class LeetCode_231 : public ISolution {
public:
    //2의 거듭제곱근인가?
    bool isPowerOfTwo(int n) {
        if (n <= 0) 
            return false;

        //비트연산,
        //0000  : 0
        //0001  : 1
        //0010  : 2
        
        //0011  : 3
        //0100  : 4
        
        //0111  : 7
        //1000  : 8

        return (n & (n - 1)) == 0;
    }

    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
    }
};

