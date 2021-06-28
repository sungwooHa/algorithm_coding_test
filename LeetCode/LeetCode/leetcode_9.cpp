#pragma once

#include "ISoultion.h"

/// <summary>
/// interger x
/// if x is palindrome integer
/// return ture
/// 
/// palindorme : 121, 131 etc.
/// 
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
class LeetCode_9 : public ISolution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        if (x != 0 && x % 10 == 0)
            return false;

        int reverseX = 0;
        while (reverseX < x)
        {
            int pop = x % 10;
            x /= 10;

            if (INT_MAX / 10 < reverseX)
                return false;
            reverseX *= 10;
            reverseX += pop;
        }
        //濠葬熱 礎熱 || 濠葬熱 �汝�

        return x == reverseX / 10 || x == reverseX;
    }

	bool isPalindrome_recommand(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int reverse = 0;
        while (x > reverse) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return (x == reverse) || (x == reverse / 10);
    }
    virtual void Drive() override
    {
        assert(isPalindrome(121) == true);
        assert(isPalindrome(-121) == false);
        assert(isPalindrome(10) == false);
        assert(isPalindrome(-101) == false);
        assert(isPalindrome(22) == true);
        assert(isPalindrome(1234567899) == false);
    }

};