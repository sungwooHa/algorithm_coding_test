#pragma once
#include "ISoultion.h"


/// <summary>
/// https://leetcode.com/problems/3sum/
/// </summary>
/// <returns></returns>
class LeetCode_15 : public ISolution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		std::sort(nums.begin(), nums.end());

		vector<vector<int>> res;

		for (auto i = 0; i < nums.size(); ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;

			const auto& target = nums[i];
			auto left = i + 1;
			auto right = nums.size() - 1;

			while (left < right)
			{
				const auto& sum = target + nums[left] + nums[right];

				if (sum > 0)
					right--;
				else if (sum < 0)
					left++;
				else
				{
					vector<int> triplet = { nums[i], nums[left++], nums[right--] };
					res.push_back(triplet);

					while (left < right && nums[left] == nums[left+1]) left++; // 중복 제거
					while (left < right && nums[right] == nums[right-1]) right--; //중복 제거
				}

			}
		}
		return res;
	}
	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		vector<int> nums;

		nums = { -1, 0, 1, 2, -1, -4 };

		threeSum(nums);

	}
};

