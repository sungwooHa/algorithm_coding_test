#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/summary-ranges/
/// </summary>
/// <returns></returns>
/// range a~b
/// 가장 적은 sorting으로 array의 모든 숫자를 cover하라.
/// 
class LeetCode_228 : public ISolution {
public:

    string ConvertToString(int first, int second) {
        if (first == second)
        {
            return std::to_string(first);
        }
        else
        {
            string str;
            str += (std::to_string(first));
            str += "->";
            str += (std::to_string(second));
            return str;
        }
    }

    vector<string> summaryRanges(vector<int>& nums) 
    {
        if (nums.empty())
            return {};

        vector<string> res;

        //0,1,4
        int first = -1;
        int second = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (first == -1 && second == -1)
            {
                first = nums[i];
                second = nums[i];
                continue;
            }

            if (second + 1 == nums[i])
            {
                second++;
                continue;
            }
            else
            {
                res.push_back(ConvertToString(first, second));
                
                first = nums[i];
                second = nums[i];
            }
        }
        res.push_back(ConvertToString(first, second));

        return res;
    }

    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
        std::vector<int> nums;
        nums = { 0, 1, 2, 4, 5, 7 };
        summaryRanges(nums);

    }
};

