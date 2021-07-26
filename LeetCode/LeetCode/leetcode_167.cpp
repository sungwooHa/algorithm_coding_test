#pragma once
#include "ISoultion.h"
#include <array>

/// <summary>
/// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
/// </summary>
/// <param name="numbers">vector<int>  sorted in non-decreasing order(오름차순) </param>
/// <param name="targer"> int</param>
/// 
/// target 숫자를 만들기 위해 더해야하는 index 2개 return
/// 
/// 
class LeetCode_167 : public ISolution {
public:

	vector<int> twoSum(vector<int>& numbers, int target)
	{
		int left = 0;
		int right = numbers.size() - 1;


		while (left < right)
		{
			if (numbers[left] + numbers[right] == target)
			{
				return { left + 1, right + 1 };
			}
			else if (numbers[left] + numbers[right] > target)
			{
				right--;
			}
			else
				left++;
		}

		return {};

	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		std::vector<int> number;
		int target;


		number = {2,7,11,15};
		target = 9;

		twoSum(number, target);
	}
};

