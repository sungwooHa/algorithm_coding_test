#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/next-permutation/
/// </summary>
/// �ԷµǴ� ���� ���� ������ ���� ������ �;��� ���� ���.
/// 1,2,3 -> 1,3,2
/// 3,2,1 -> 1,2,3
/// �ڿ� ���ڸ� �ٲٰ�, ���� ��� ���� ���� ���� ����ϸ� ���� ������
/// �Ѱ� �� ���� �ǵ��� ����!
/// <returns></returns>
/// 

/// 
class LeetCode_31 : public ISolution {
public:

    void nextPermutation_example(vector<int>& nums)
    {
        int n = nums.size(), k;
        for (k = n - 2; k >= 0; k--)
        {
            //1,4,2,3
            //k = 2, k+1 = 3;
            if (nums[k] < nums[k + 1])
                break;
        }
        if (k < 0)
            std::sort(nums.begin(), nums.end());
        else
        {
            int l;
            for (l = n - 1; l > k; l--) // ���������� k������
            {
                if (nums[l] > nums[k])
                    break;
            }
            swap(nums[l], nums[k]);
            std::sort(nums.begin() + k + 1, nums.end());
        }
    }

    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1)
            return;

        std::priority_queue<int> pq;
        int idxPrev = nums.size() - 2;
        int idxTarget = nums.size() - 1;

        auto lambda_swap = [&nums](int idxPrev, int idxTarget) {
            int tmp = nums[idxPrev];
            nums[idxPrev] = nums[idxTarget];
            nums[idxTarget] = tmp;
        };

        while (idxPrev >= 0)
        {
            if (nums[idxPrev] >= nums[idxTarget])
            {
                pq.push(-nums[idxTarget]);
                idxPrev--;
                idxTarget--;
                continue;
            }

            //1,3,2,0
            //2,0,1,3

            //�տ� ���ڰ� ���� ��� target���� ū �� �߿� ���� ���� ���� idx prev���� ����, �ڿ��� ����.
            pq.push(-nums[idxTarget]);
            std::pair<int, int> val = {0, INT_MAX};//first : idx, second : value;
            while (!pq.empty())
            {
                int tmp = -pq.top();
                if (nums[idxPrev] < tmp)
                {
                    if (val.second > tmp)
                        val = { idxTarget, tmp};
                }
                nums[idxTarget++] = tmp;
                pq.pop();
            }
            lambda_swap(idxPrev, val.first);
            return;
        }

        //ù���� ���� �����.
        std::sort(nums.begin(), nums.end());
    }

    // ISolution��(��) ���� ��ӵ�
    virtual void Drive() override
    {
        std::vector<int> nums = { 1, 3, 2 };

        nextPermutation(nums);

        if (nums != std::vector<int>{2, 1, 3})
        {
            assert(false);
        }
    }
};