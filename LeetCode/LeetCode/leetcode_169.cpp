#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/majority-element/
/// </summary>
/// <param name="nums">vectoin <int> </param>
/// 
/// use hash.
/// return most counted value

class LeetCode_169 : public ISolution {
public:
	int majorityElement(vector<int>& nums)
	{
		std::unordered_map<int, int> hashMap;
		for (const auto& num : nums)
		{
			if (++hashMap[num] > nums.size() >> 1)
				return num;
		}
		return 0;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		std::vector<int> nums;

		nums = { 3, 2, 3};
		assert(majorityElement(nums) == 3);

		nums = { 3, 3, 4 };
		assert(majorityElement(nums) == 3);
	}
};

