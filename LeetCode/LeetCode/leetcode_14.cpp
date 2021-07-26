#pragma once
#include "ISoultion.h"


/// <summary>
/// prefix 찾기
/// https://leetcode.com/problems/longest-common-prefix/
/// </summary>
/// <param name="strs">단어 배열</param>
/// <returns></returns>
class LeetCode_14 : public ISolution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		size_t length(INT_MAX);

		for (int i = 0; i < strs.size(); ++i)
		{
			if (length > strs[i].size())
				length = strs[i].size();

			if (i < strs.size() - 1)
				if ((strs[i][0] != strs[i + 1][0]))
					return "";
		}

		for (unsigned int idxCh = 0; idxCh < length; ++idxCh)
		{
			for (int idxStr = 0; idxStr < strs.size() - 1; ++idxStr)
			{
				if (strs[idxStr][idxCh] == strs[idxStr + 1][idxCh])
					continue;

				return strs[0].substr(0, idxCh);
			}
		}

		return strs[0].substr(0, length);
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		std::vector<string> strs = { "dog", "racecar", "car" };
		auto val = longestCommonPrefix(strs); //fl
		assert(strcmp(val.c_str(), "") == 0);

		strs = {
			"ab", "a" };
		val = longestCommonPrefix(strs);
		assert(strcmp(val.c_str(), "a") == 0);

		strs = {
			"flower", "flow", "flight" };
		val = longestCommonPrefix(strs);
		assert(strcmp(val.c_str(), "fl") == 0);
	}
};

