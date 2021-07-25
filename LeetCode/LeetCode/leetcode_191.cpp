#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/number-of-1-bits/
/// </summary>
/// 
/// 
/// 

class LeetCode_191 : public ISolution {
public:
	int hammingWeight(uint32_t n) 
	{
		int numb(0);
		while (n)
		{
			if (n & 1)
				numb++;

			n = n >> 1;
		}

		return numb;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		uint32_t input;

		input = 11;
		assert(hammingWeight(input) == 3);
	}
};

