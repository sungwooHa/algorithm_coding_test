#pragma once
#include "ISoultion.h"
#include <map>
/// <summary>
/// https://leetcode.com/problems/contains-duplicate/
/// </summary>
/// <returns></returns>
class LeetCode_207 : public ISolution {
public:
	bool containsDuplicate(vector<int>& nums) {
		//twice ? return true.
		std::unordered_map<int, int> hash;
		hash.reserve(nums.size());
		
		for (const auto& num : nums)
		{
			hash[num]++;
			if (hash[num] > 1)
				return true;
		}
		return false;
	}

	bool containsDuplicate_ex(vector<int>& nums) {
		//twice ? return true.
		return std::unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
	}
};

