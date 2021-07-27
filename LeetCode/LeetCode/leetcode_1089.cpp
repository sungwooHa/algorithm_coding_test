#pragma once
#include "ISoultion.h"

/// <summary>
///https://leetcode.com/problems/duplicate-zeros/
/// </summary>
/// 
/// 
/// 

class LeetCode_1089 : public ISolution {
public:
    void duplicateZeros(vector<int>& arr)
    {
        std::queue<int> sq;

        int idx(0);
        while (arr.size() >= sq.size())
        {
            sq.push(arr[idx]);
            if (arr.size() == sq.size())
                break;

            if (arr[idx++] == 0)
                sq.push(0);
        }

        for (auto& val : arr)
        {
            val = sq.front();
            sq.pop();
        }
    }
    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
    }
};

