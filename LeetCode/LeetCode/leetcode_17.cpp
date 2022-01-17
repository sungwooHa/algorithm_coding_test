#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
/// </summary>
/// <returns></returns>
class LeetCode_17 : public ISolution {
public:
	//digit [2, 9]
	//digit.length [0, 4]
	//조합가능한 문자열 전부 출력하기.

	const vector<string> phoneKeyPad = {
		"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
	};//2~9

	vector<string> letterCombinations(string digits) {
		if (digits == "") return {};

		vector<string> answer{ "" };

		for (const auto& digit : digits)
		{
			vector<string> combi;

			for (const auto& curCombi : answer)
			{
				for (const auto& keyPad : phoneKeyPad[digit - '2'])
				{
					combi.push_back(curCombi + keyPad);
				}
			}
			answer = move(combi);
		}
		return answer;
	}
	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		auto answer = letterCombinations("2");
		//"a", "b", "c"

		answer = letterCombinations("");
		//""

		answer = letterCombinations("23");
		//"ad","ae","af","bd","be","bf","cd","ce","cf"
	}
};

