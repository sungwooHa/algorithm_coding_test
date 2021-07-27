#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/count-and-say/
/// </summary>
class LeetCode_38 : public ISolution
{
private:


public:
	string Method1(string strNumb)
	{
		std::vector<std::pair<char, int>> svPair; //value, cnt;

		for (const auto& ch : strNumb)
		{
			if (!svPair.empty())
			{
				if (svPair.back().first == ch)
				{
					svPair.back().second++;
					continue;
				}
			}

			svPair.push_back(std::make_pair(ch, 1));
		}
		//
		//vector<"numb", "count">
		//

		string answer;
		for (const auto& elem : svPair)
		{
			answer += to_string(elem.second); //count
			answer += elem.first;             //numb
		}

		return answer;
	}

	string countAndSay(int n)
	{
		if (n == 1)
			return "1";

		string prvString = "1";
		for (int i = 1; i < n; i++)
		{
			prvString = Method1(prvString);
		}

		return prvString;
	}
};

