#pragma once
#include "ISoultion.h"
#include <array>

/// <summary>
/// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
/// </summary>
/// <param name = "triplets"> Array<Array<int>> array of three intergers. </param>
/// <param name = "target"> </param>
/// <retrun> </retrun>

class Leetcode_1899 : public ISolution
{
public :
	bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) 
	{
		std::array<bool, 3> find = { false, };
		for (int i = 0; i < triplets.size(); ++i)
		{
			bool isPossible(true);
			for (int idx = 0; idx < 3; ++idx)
			{
				if (triplets[i][idx] > target[idx])
				{
					//작으면 std::max에서 불가능.
					isPossible = false;
					break;
				}
			}

			if (isPossible)
			{
				for (int idx = 0; idx < 3; ++idx)
				{
					if (triplets[i][idx] == target[idx])
						find[idx] = true;
				}
			}
		}
		
		for (int idx = 0; idx < 3; ++idx)
		{
			if (!find[idx])
				return false;
		}

		return true;
	}

	virtual void Drive() override
	{
		vector<vector<int>> triplets;
		vector<int> target;

		triplets = { { 2, 5, 3 }, { 2, 3, 4 }, { 1, 2, 5 }, { 5, 2, 3 } };
		target = { 5, 5, 5 };


		assert(true == mergeTriplets(triplets, target));
	}
};