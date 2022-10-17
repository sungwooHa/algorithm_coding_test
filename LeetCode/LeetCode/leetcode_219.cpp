#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/contains-duplicate-ii/
/// </summary>
/// <returns></returns>
class LeetCode_219 : public ISolution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		//abs(i-j) <= k.
		//nums[i] == nums[j]
		//있으면 return true 없으면 return false;

		if (k == 0) return 
			false;
		if (k >= nums.size()) 
			k = nums.size() - 1;

		std::unordered_set<int> hashSet;
		for (int i = 0; i < nums.size(); ++i)
		{
			//index가 커질경우 이전에 넣었던거 지움
			if (i > k) 
				hashSet.erase(nums[i - k - 1]);

			if (hashSet.find(nums[i]) != hashSet.end())
				return true;

			hashSet.insert(nums[i]);
		}

		return false;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		std::vector<int> nums = {1,2,3,1};
		containsNearbyDuplicate(nums, 3);
	}
};

