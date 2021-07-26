#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/reverse-bits/
/// </summary>
/// 
/// 
/// 

class LeetCode_190 : public ISolution {
public:
	uint32_t reverseBits(uint32_t n)
	{
		uint32_t res = 0;
		int power = 31;

		while (n)
		{
			res += (n & 1) << power;
			n = n >> 1;
			power -= 1;
		}

		return res;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
	}
};

