#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/factorial-trailing-zeroes/
/// </summary>
/// <param name="columnTitle">string <int> </param>
/// 
/// excel column(26) to integer(digit)
/// 
/// 

class LeetCode_172 : public ISolution {
public:
	int trailingZeroes(int n)
	{
		int cnt(0);
		for (long long i = 5; n / i; i *= 5)
			cnt += n / i;

		return cnt;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
	}
};

