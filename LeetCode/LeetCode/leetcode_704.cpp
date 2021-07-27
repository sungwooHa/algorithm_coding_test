#pragma once
#include "ISoultion.h"

/// <summary>
///https://leetcode.com/problems/binary-search/
/// </summary>
/// 
/// 
/// 

class LeetCode_704 : public ISolution {
public:
    int search(vector<int>& nums, int target)
    {
        unsigned int min = 0;
        unsigned int max = nums.size() - 1;
        int mid(0);

        while (min <= max)
        {
            mid = (max + min) / 2; //무조건 양수.

            if (mid >= nums.size())
                return -1;

            //Result return;
            if (target == nums[mid])
                return mid;

            if (target > nums[mid])
            {
                //최소 range 수정
                min = mid + 1;
            }
            else
            {
                //최대 range 수정
                max = mid - 1;
            }

        }

        return -1;
    }
	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
	}
};

