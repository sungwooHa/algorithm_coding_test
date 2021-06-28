#pragma once
#include "ISoultion.h"
#include <array>

/// <summary>
/// https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/
/// </summary>
/// <param name = "startTime"> HH:MM </param>
/// <param name = "finishTime">HH:MM  </param>
/// 각 round는 15분
/// 단위는 00, 15, 30, 45
/// full round 개수 구하기
/// 
/// example
/// start 12:01, finsih 12:44
/// --> 1 (12:15~12:30)
///
/// example
/// start 20:00, finsih 06:00
/// --> 40 = 16(20:00~24:00) + 24(00:00~06:00)
/// <retrun> int </retrun>

class Leetcode_1904 : public ISolution
{
public:
	int numberOfRounds(string startTime, string finishTime)
	{
		//To minute
		int start = stoi(startTime.substr(0, 2)) * 60 + stoi(startTime.substr(3, 2));
		int finish = stoi(finishTime.substr(0, 2)) * 60 + stoi(finishTime.substr(3, 2));


		if (start > finish)
		{
			//over night
			finish += 24 * 60;
		}

		//start 올림
		//finish 내림
		//-음수가 나올수 있음,
		return std::max(0, finish / 15 - (start + 14) / 15);
	}


	virtual void Drive() override
	{
	}
};