#pragma once
#include "ISoultion.h"


/// <summary>
/// https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
/// </summary>
/// <param name="nums"> std::vector<int>, start with an initial postivie value.</param>
/// <returns> minimum positivie value. never less than 1</returns>
/// step by step sum is less than 1.
/// 

class Leetcode_1413 : public ISolution
{
public:
	int minStartValue(vector<int>& nums)
	{
		int result(0);
		int sum(0);
		for (const auto num : nums)
		{
			sum += num;
			if (sum < 1)
			{
				int val = 1 - sum;
				result += val;
				sum += val;
			}
		}

		return result == 0 ? 1 : result;
	}
	
	int minStartValue_recommand(vector<int>& nums)
	{
		int min_sum(0);
		int sum(0);
		for (const auto& num : nums)
		{
			sum += num;
			min_sum = std::min(min_sum, sum);
		}
		return 1 - min_sum;
	}
	virtual void Drive() override
	{
		std::vector<int> nums;

		nums = { 2, 3, 5, -5, 1 };
		assert(minStartValue_recommand(nums) == 1);

		nums = { -3, 2, -3, 4, 2 };
		assert(minStartValue_recommand(nums) == 5);

		nums = { 1, 2 };
		assert(minStartValue_recommand(nums) == 1);

		nums = { 1, -2, -3 };
		assert(minStartValue_recommand(nums) == 5);
	}
};

