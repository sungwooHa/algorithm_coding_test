#pragma once

#include "ISoultion.h"

/// <summary>
/// slidng window.
/// 연산이 될 경우 index+=2
/// 연산이 안될경우 단일 연산 후 index++
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
class LeetCode_13 : public ISolution
{
public:
    int romanToInt(string s)
    {
        auto lambada_Convert = [&](char ch) -> int
        {
            switch (ch)
            {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            }
            return -1;
        };

        auto lambda_Comp = [&](char ch1, char ch2) -> int
        {
            if (((ch1 == 'I' && ch2 == 'V')
                || (ch1 == 'I' && ch2 == 'X'))  //case 1
                || ((ch1 == 'X' && ch2 == 'L')
                    || (ch1 == 'X' && ch2 == 'C')) //case 2
                || ((ch1 == 'C' && ch2 == 'D')
                    || (ch1 == 'C' && ch2 == 'M'))) //case 3
            {
                return lambada_Convert(ch2) - lambada_Convert(ch1);
            }
            else
            {
                return -1;
            }
        };

        int answer = 0;

        int index = 0;
        while (true)
        {
            if (s.size() > index + 1)
            {
                auto val = lambda_Comp(s[index], s[index + 1]);
                if (val == -1)
                {
                    answer += lambada_Convert(s[index]);
                    index++;
                }
                else
                {
                    answer += val;
                    index += 2;
                }
            }
            else if (s.size() - 1 == index) //마지막
            {
                answer += lambada_Convert(s[index]);
                break;
            }
            else
                break;
        }

        return answer;
    }

    virtual void Drive() override
    {
        assert(romanToInt("III") == 3);
        assert(romanToInt("IV") == 4);
        assert(romanToInt("IX") == 9);
        assert(romanToInt("LVIII") == 58);
        assert(romanToInt("MCMXCIV") == 1994);
        assert(romanToInt("MCDLXXVI") == 1476);
        assert(romanToInt("MCMXCIV") == 1994);

    }
};