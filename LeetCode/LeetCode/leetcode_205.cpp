#pragma once
#include "ISoultion.h"
#include <map>
/// <summary>
/// https://leetcode.com/problems/isomorphic-strings/
/// </summary>
/// <returns></returns>
class LeetCode_205 : public ISolution {
public:

	bool isIsomorphic(string s, string t) {

		auto lambda_IsIsomorphic = [](const string& s, const string& t) -> bool
		{
			std::map<char, char> mp;
			for (int idx = 0; idx <= s.length(); ++idx)
			{
				if (mp.find(s[idx]) == mp.end())
				{
					mp[s[idx]] = t[idx];
				}
				else
				{
					if (mp[s[idx]] != t[idx])
						return false;
				}
			}
			return true;
		};

		if (!lambda_IsIsomorphic(s, t)) return false;
		if (!lambda_IsIsomorphic(t, s)) return false;

		return true;
	}
	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		string s = {};
		string t = {};

		s = "badc";
		t = "baba";

		isIsomorphic(s, t);
	}
};

