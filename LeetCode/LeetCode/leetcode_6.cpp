#pragma once
#include "ISoultion.h"

/// <summary>
///https://leetcode.com/problems/zigzag-conversion/
/// </summary>
/// 
/// "PAYPALISHIRING" row : 3
/// 
/// P   A   H   N
/// A P L S I I G
/// Y   I   R
/// 
/// "PAHNAPLSIIGYIR"
/// 
/// 
/// "PAYPALISHIRING" row : 4
/// P     I    N
/// A   L S  I G
/// Y A   H R
/// P     I
/// 
/// "PINALSIGYAHRPI"
/// 
/// 

class LeetCode_6 : public ISolution {
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        std::vector<string> arrStr(numRows);
        bool reverse(false);
        int idx = 0;
        while (s.size())
        {
            arrStr[idx].push_back(s.front());
            s.erase(s.begin());

            if (reverse)
            {
                if (idx == 0)
                {
                    reverse = !reverse;
                    idx++;
                }
                else
                    idx--;
            }
            else
            {
                if (idx == numRows - 1)
                {
                    reverse = !reverse;
                    idx--;
                }
                else
                    idx++;
            }
        }

        for (const auto& str : arrStr)
        {
            s.append(str);
        }

        return s;
    }
    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
        string s, res;
        int numRows;

        s = "AB";
        numRows = 1;
        res = convert(s, 1);
    }
};

