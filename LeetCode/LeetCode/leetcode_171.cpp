#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/excel-sheet-column-number/
/// </summary>
/// <param name="columnTitle">string <int> </param>
/// 
/// excel column(26) to integer(digit)
/// 
/// 

class LeetCode_171 : public ISolution {
public:
	int titleToNumber(string columnTitle)
	{
		int numb(0);
		for (const auto& ch : columnTitle)
		{
			numb *= 26;
			numb += ch - 'A' + 1;
		}

		return numb;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		string column;

		column = "A";
		assert(titleToNumber(column) == 1);

		column = "AB";
		assert(titleToNumber(column) == 28);

		column = "ZY";
		assert(titleToNumber(column) == 701);
	}
};

