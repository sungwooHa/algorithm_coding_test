#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/3sum-closest/
/// </summary>
/// <returns></returns>
class LeetCode_16 : public ISolution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		//3개를 더해서 target에 가장 근접한 수를 찾기.
		int ans(nums[0] + nums[1] + nums[2]);
		
		std::sort(nums.begin(), nums.end());

		for (int idx = 0; idx < nums.size()-2; ++idx)
		{
			//중복 등장 방지
			if (idx > 0 && nums[idx] == nums[idx - 1]) continue;

			int start(idx + 1);
			int end(nums.size() - 1);

			while (start < end)
			{
				int curSum = nums[start] + nums[end] + nums[idx];
				if (std::abs(target - curSum) < std::abs(target - ans))
					ans = curSum;
				
				if (curSum > target)
					end--;
				else if (curSum < target)
					start++;
				else //same
					return curSum;
			}

		}

		return ans;
	}
	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		std::vector<int> nums;
		int target(0);

		int result(0);

		nums = { -1, 2, 1, -4 };
		target = 1;
		result = threeSumClosest(nums, target);

		nums = { 1,1,1,1 };
		target = -100;
		result = threeSumClosest(nums, target);
	}
};

