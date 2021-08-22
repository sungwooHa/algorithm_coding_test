#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/string-to-integer-atoi/
/// </summary>
/// 
/// 
/// 

class LeetCode_8 : public ISolution {
public:
    int myAtoi(string s) 
    {
        long result(0);
        if (s.empty())
            return result;

        int indicator(1); //if it doesn't have indicator? that's '+

        int strIdx = s.find_first_not_of(' ');
        if (strIdx == -1)
            return result;

        if (s[strIdx] == '-' || s[strIdx] == '+')
            indicator = (s[strIdx++] == '-') ? -1 : +1;


        while (isdigit(s[strIdx]))
        {
            result = result * 10 + (s[strIdx] - '0');

            if (result * indicator >= INT_MAX) return INT_MAX;
            else if (result * indicator <= INT_MIN) return INT_MIN;
            else
                strIdx++;
        }
        
        return result* indicator;
    }
    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
        string s;

        s = " ";

        auto val = myAtoi(s);
    }
};

