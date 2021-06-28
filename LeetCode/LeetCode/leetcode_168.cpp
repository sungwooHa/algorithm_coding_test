#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/excel-sheet-column-title/
/// </summary>
/// <param name="columnNumber">int </param>
/// excel column return!
/// A -> 1
/// AA -> 27

class LeetCode_168 : public ISolution {
public:

	string convertToTitle(int columnNumber) 
	{
		//ASCII 코드
		//26진수 만들기

		string res;
		while (columnNumber > 0)
		{
			columnNumber--; //각 자리수 1부터 시작하기때문.
			const char ch = 'A' + columnNumber % 26;
			res = ch + res;
			columnNumber /= 26;
		}

		return res;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		assert(strcmp(convertToTitle(1).c_str(), "A") == 0);
		assert(strcmp(convertToTitle(28).c_str(), "AB") == 0);
		assert(strcmp(convertToTitle(701).c_str(), "ZY") == 0);
		assert(strcmp(convertToTitle(2147483647).c_str(), "FXSHRXW") == 0);

	}
};

