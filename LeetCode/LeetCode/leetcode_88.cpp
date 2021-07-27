#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/merge-sorted-array/
/// </summary>
class LeetCode_88 : public ISolution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        std::multiset<int> ms;
        for (int i = 0; i < m; i++)
            ms.emplace(nums1[i]);

        for (int j = 0; j < n; j++)
            ms.emplace(nums2[j]);

        nums1.resize(ms.size());
        std::copy(ms.begin(), ms.end(), nums1.begin());

        //1,2,3,0,0,0
        //2,5,6
        //index : 0 1 2 3 4 5
        //value : 1,2,2,3,5,6
    }

};

