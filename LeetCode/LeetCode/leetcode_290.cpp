#pragma once
#include "ISoultion.h"
#include <sstream>
#include <iostream>
/// <summary>
/// https://leetcode.com/problems/word-pattern/
/// </summary>
/// <returns></returns>
class LeetCode_290 : public ISolution {
public:

	bool wordPattern(string pattern, string s) 
	{
		std::istringstream ss(s);
		string unit;

		std::map<string, char> mp;
		char sPattern = 'a';
		string s2pattern;

		int i = 0;
		while (std::getline(ss, unit, ' '))
		{
			if (mp.find(unit) == mp.end())
			{
				mp[unit] = sPattern;
				sPattern++;
			}
			s2pattern += mp[unit];
		}

		if (pattern.size() != s2pattern.size())
			return false;

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

		if (!lambda_IsIsomorphic(pattern, s2pattern)) return false;
		if (!lambda_IsIsomorphic(s2pattern, pattern)) return false;

		return true;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		string pattern = "abba";
		string s = "dog cat cat dog";

		wordPattern(pattern, s);

		pattern = "jquery";
		s = "jquery";
		wordPattern(pattern, s);
	}
};

