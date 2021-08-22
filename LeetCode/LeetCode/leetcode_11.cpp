#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/container-with-most-water/
/// </summary>
/// 
/// 
/// 

class LeetCode_11 : public ISolution {
public:
    int maxArea(vector<int>& height) 
    {
        int area(0);
        int maxHeight = *(std::max_element(height.begin(), height.end()));
        for (int i = 0; i < height.size(); ++i)
        {
            if (((height.size() - 1 - i) * maxHeight) < area)
                return area;

            for (int j = height.size()-1; i < j; --j)
            {
                int minHeight = (height[i] < height[j]) ? height[i] : height[j];
                area = std::max(area, minHeight * (j-i));
            }
        }

        return area;
    }
    // ISolution을(를) 통해 상속됨

    int maxArea_BST1(vector<int>& height)
    {
        int area(0);
        int i = 0, j = height.size() - 1;

        while (i < j)
        {
            int minHeight = std::min(height[i], height[j]);
            area = std::max(area, (j - i) * minHeight);

            while (height[i] <= minHeight && i < j) ++i;
            while (height[j] <= minHeight && i < j) --j;
        }
        return area;
    }

    int maxArea_BST2(vector<int>& height)
    {
        int area(0);
        int i = 0;
        int j = height.size() - 1;

        while (i < j)
        {
            area = std::max(area, (j - i) * std::min(height[i], height[j]));

            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return area;
    }

    virtual void Drive() override
    {
        std::vector<int> height;
        height = {1,8,6,2,5,4,8,3,7};
        int res;

        res = maxArea_BST1(height);
    }
};

