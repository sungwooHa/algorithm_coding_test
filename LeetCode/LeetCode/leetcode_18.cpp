#pragma once
#include "ISoultion.h"
#include <algorithm>
/// <summary>
/// https://leetcode.com/problems/4sum/
/// </summary>
/// <returns></returns>
class LeetCode_18 : public ISolution {
public:

	vector<vector<int>> fourSum(vector<int>& nums, int target) {

		vector<vector<int>> res;
		if (nums.size() < 4) return res;
		vector<int> combi(nums.size());
		combi[0] = 1;
		combi[1] = 1;
		combi[2] = 1;
		combi[3] = 1;

		std::sort(nums.begin(), nums.end());
		do {

			int sum(0);
			std::vector<int> tmp;
			for(int i = 0; i < nums.size(); ++i)
			{
				if (combi[i] != 1)
					continue;

				sum += nums[i];
				tmp.push_back(nums[i]);

				if (sum == target && tmp.size() == 4)
				{
					std::sort(tmp.begin(), tmp.end());
					if (auto itr = std::find(res.begin(), res.end(), tmp); itr == res.end())
						res.push_back(tmp);

					break;
				}
			}

		} while (std::prev_permutation(combi.begin(), combi.end()));

		return res;
	}

	virtual void Drive() override
	{
		std::vector<std::vector<int>> res;
		std::vector<int> nums;
		int target;

		nums = { 1, 0, -1, 0, -2, 2 };
		target = 0;
		res = fourSum(nums, target);

		nums = {1, -2, -5, -4, -3, 3, 3, 5 };
		target = -11;

		res = fourSum(nums, target);
	}
};
