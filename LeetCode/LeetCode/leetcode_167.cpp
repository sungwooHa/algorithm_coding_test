#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
/// </summary>
/// <param name="numbers">vector<int>  sorted in non-decreasing order(오름차순) </param>
/// <param name="targer"> int</param>
/// 
/// target 숫자를 만들기 위해 더해야하는 index return
/// 
/// 
class LeetCode_167 : public ISolution {
public:

	bool GetNumberIndex(int index, const int& targetNumber, const std::vector<int>& numbers, std::vector<int>
		res, int sum)
	{
		if (index >= numbers.size())
			return false;
	}

	vector<int> twoSum(vector<int>& numbers, int target)
	{

	}
	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
	}
};

