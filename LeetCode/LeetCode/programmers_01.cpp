#pragma once
#include "ISoultion.h"

#include <vector>

class programmers_01 : public ISolution
{
public:

	int CountMine(const int x, const  int y, const int size, const vector<vector<int>>& answer)
	{
		//(x-1, y-1) , (x, y-1), (x+1, y-1)
		//(x-1, y	) , (x, y),  (x+1, y)
		//(x-1, y+1) , (x, y+1), (x+1, y+1)

		int count(0);
		for (int i = x-1; i <= x + 1; ++i)
		{
			if (i < 0)
				continue;

			if (size <= i)
				continue;

			for (int j = y - 1; j <= y + 1; ++j)
			{
				if (j < 0)
					continue;

				if (size <= j)
					continue;

				if (i == x && j == y)
					continue;

				if (answer[i][j] == -1)
					count++;
			}
		}

		return count;
	}

	vector<vector<int> > solution(int N, vector<vector<int>> mine)
	{
		vector<vector<int> > answer(N);

		for (auto& col : answer)
			col.resize(N);

		for (const auto& mineInfo : mine)
		{
			answer[mineInfo[0]-1][mineInfo[1]-1] = -1;
		}

		//Áö·Ú°¡ ÀÖ´Â Ä­¿¡´Â -1
		//Áö·Ú°¡ ¾ø´Â Ä­¿¡´Â ÀÎÁ¢ Áö·ÚÀÇ °³¼ö


		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (answer[i][j] == -1)
					continue;

				answer[i][j] = CountMine(i, j, N, answer);
			}
		}

		return answer;
	}

	virtual void Drive() override
	{
		int size;
		std::vector<std::vector<int>> mine;
		std::vector<std::vector<int>> result;

		size = 9;
		mine = { { 1, 1 }, { 1, 7 }, { 2, 7 }, { 3, 6 }, { 4, 1 }, { 4, 4 }, { 4, 8 }, { 8, 4 }, { 8, 5 }, { 9, 6 } };
		result = {
			{ -1, 1, 0, 0, 0, 2, -1, 2, 0 },
			{ 1, 1, 0, 0, 1, 3, -1, 2, 0 },
			{ 1, 1, 1, 1, 2, -1, 3, 2, 1 },
			{ -1, 1, 1, -1, 2, 1, 2, -1, 1 },
			{ 1, 1, 1, 1, 1, 0, 1, 1, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 2, 2, 1, 0, 0, 0 },
			{ 0, 0, 1, -1, -1, 2, 1, 0, 0 },
			{ 0, 0, 1, 2, 3, -1, 1, 0, 0 } };



		assert(result == solution(size, mine));
	}
};