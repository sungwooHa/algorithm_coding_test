#pragma once
#include "ISoultion.h"
#include <cmath>
/// <summary>
/// https://leetcode.com/problems/happy-number/
/// </summary>
/// 
/// 각 자릿수의 제곱을 더함
/// 계속 반복
/// 합이 1로 끝나면 true
/// 합이 1로 끝나지 못하면 false.
/// check infinite loop
/// 

class LeetCode_202 : public ISolution {
public:
    bool isHappy(int n)
    {
        //check infinite loop
        std::unordered_map<int, int> hashMap;

        const int HAPPY_NUMBER = 1;

        while (n != HAPPY_NUMBER)
        {
            if (!hashMap[n])
                hashMap[n]++;
            else
                return false;

            int sum = 0;
            while (n)
            {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            
            n = sum;
        }

        return true;
    }

    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
    }
};

