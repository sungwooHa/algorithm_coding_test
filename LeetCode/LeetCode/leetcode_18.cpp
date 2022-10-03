#pragma once
#include "ISoultion.h"
#include <algorithm>
/// <summary>
/// https://leetcode.com/problems/4sum/
/// </summary>
/// <returns></returns>
class LeetCode_18 : public ISolution {
public:
	
	//combination���� ����.
	//�̰ɷδ� TIL �߻�
	//��� 4�� ������ ã��
	//����� ���� target�� ���� �� collect.
	vector<vector<int>> fourSum_combi(vector<int>& nums, int target) {

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

	vector<vector<int>> fourSum_dp(vector<int>& nums, int target) 
	{
		vector<vector<int>> res;
		//����ó��
		if (nums.size() < 4) return res;

		std::sort(nums.begin(), nums.end());
		//4���� pivot
		//4���� ��ġ���� ����
		//���ؼ� 0�� �Ǵ� ���� ã��

		auto sum_arr = [](std::vector<int> tmp) -> int {
			int res(0);
			for (const auto& val : tmp)
				res += val;
			return res;
		};

		for (int first = 0; first < nums.size() - 3; ++first)
		{
			const auto target_sub_1 = target - nums[first];

			for (int second = first + 1; second < nums.size() - 2; ++second)
			{
				const long int target_sub_1_2 = (long int)target_sub_1 - nums[second];

				int third = second + 1;
				int fourth = nums.size() - 1;

				while (third < fourth)
				{
					auto sum = nums[third] + nums[fourth];
					if (sum > target_sub_1_2)
					{
						//���� target���� Ŭ ���, ������(fourth)�� ��������
						fourth--;
						continue;
					}
					
					if (sum < target_sub_1_2)
					{
						//���� target���� ���� ���, ����(third)�� ����������
						third++;
						continue;
					}

					res.push_back({ nums[first], nums[second], nums[third], nums[fourth] });

					//third���� ���������� ���� ���� ���� ���
					while (third < nums.size() - 1 && nums[third + 1] == nums[third]) third++;

					//fourth���� ���������� ���� ���� ���� ���
					while (fourth > 0 && nums[fourth - 1] == nums[fourth]) fourth--;

					//target�� ���
					//�Ѵ� �Ű������, �ϳ��� �ű�� �ᱹ �ߺ�
					third++;
					fourth--;
				}

				//second�� �������θ� �� �̵�
				while (second < nums.size() - 1 && nums[second + 1] == nums[second]) second++;
			}

			//first�� �������θ� �� �̵�
			while (first < nums.size() - 1 && nums[first + 1] == nums[first]) first++;
		}

		return res;
	}

	virtual void Drive() override
	{
		std::vector<std::vector<int>> res;
		std::vector<int> nums;
		int target;

		nums = { 1, 0, -1, 0, -2, 2 };
		target = 0;
		res = fourSum_combi(nums, target);

		nums = {1, -2, -5, -4, -3, 3, 3, 5 };
		target = -11;

		res = fourSum_combi(nums, target);
	}
};
