#pragma once
#include "ISoultion.h"

#include <vector>
#include <limits.h>

class programmers_02 : public ISolution
{
public:

	int solution(int n, vector<int> v1, vector<int> v2, vector<int> num, vector<int> amount)
	{

		std::vector<int> student(n+1); // student, index, Teamnumb
		std::unordered_map<int, std::set<int>> teamInfo; // teamnumb, studentSet

		for (int i = 1; i <= n; i++)
		{
			student[i] = i;

			std::set<int> teamSet;
			teamSet.insert(i);
			teamInfo[i] = teamSet;
		}

		int teamNumb(0);

		for (int i = 0; i < v1.size(); ++i)
		{
			//v2 + v1 합침
			int targetTeam = student[v1[i]];
			auto moveTeamNumb = student[v2[i]];
			auto moveTeam = teamInfo[moveTeamNumb];

			//team info 수정
			for (const auto& numb : moveTeam)
			{
				student[numb] = targetTeam;
				teamInfo[targetTeam].insert(numb);
			}

			//기존 team 정보 삭제
			teamInfo.erase(moveTeamNumb);
		}

		std::map<int, int> teamAmount; //teamNumb, amount

		for (const auto&[teamNumb, teamSet] : teamInfo)
		{
			teamAmount.insert({ teamNumb, 0 });
		}

		for (int i = 0; i < num.size(); ++i)
		{
			auto targetTeamNumb = student[num[i]];

			teamAmount[targetTeamNumb] += amount[i];
		}

		std::vector<int> targetTeam;
		int topTeamNumb = teamAmount.begin()->first;
		for (const auto&[teamNumb, total] : teamAmount)
		{
			if (teamAmount[topTeamNumb] < total)
			{
				targetTeam.clear();
				topTeamNumb = teamNumb;
				targetTeam.push_back(teamNumb);
			}
			else if(teamAmount[topTeamNumb] == total)
			{
				targetTeam.push_back(teamNumb);
			}
		}

		int presiNumb(INT_MAX);

		for (int teamNumb : targetTeam)
		{
			if (presiNumb > *teamInfo[teamNumb].begin())
			{
				presiNumb = *teamInfo[teamNumb].begin();
			}
		}


		return presiNumb;
	}

	virtual void Drive() override
	{
		int n;
		std::vector<int> v1, v2;
		std::vector<int> num, amount;

// 		n = 10;
// 		v1 = { 1, 10, 6, 5, 6, 9 };
// 		v2 = { 3, 7, 2, 8, 7, 3 };
// 
// 		num = { 3, 4, 5, 1, 8, 7, 9, 2 };
// 		amount = { 10, 5, 6, -6, -8, 2, -2, 5 };
// 
// 		assert(solution(n, v1, v2, num, amount) == 2);
// 
// 		n = 10;
// 		v1 = { 8, 4, 4, 1 };
// 		v2 = { 1, 10, 9, 4 };
// 
// 		num = { 2, 5, 8, 6, 4, 1, 3, 10, 7, 4 };
// 		amount = { 3, -1, 3, 3, 1, -2, -4, 1, 2, -5 };
// 		assert(solution(n, v1, v2, num, amount) == 2);

		n = 10;
		v1 = { 1, 2,3,4,5 };
		v2 = { 6,7,8,9,10 };

		num = {1,2,3,4,5,6,7,8,9,10};
		amount = { 0,0,0,0,0, 0,0,0,0,0 };
		assert(solution(n, v1, v2, num, amount) == 1);
	}
};