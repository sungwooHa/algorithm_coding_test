#pragma once
#include "ISoultion.h"
#include <array>
#include <algorithm>

/// <summary>
/// https://leetcode.com/problems/integer-to-roman/
/// </summary>
/// <returns></returns>
class LeetCode_12 : public ISolution {
public:

	//symbol		value
	//I             1
	//V             5
	//X             10
	//L             50
	//C             100
	//D             500
	//M             1000

	//나머지연산을 통해서 할 수 있을 듯.
	string intToRoman(int num) {

		constexpr int NUMB_SYMBOL = 7;
		constexpr std::array<char, NUMB_SYMBOL> romanSymbol	 = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
		const std::array<int, NUMB_SYMBOL> symbolValue		 = { 1, 5, 10, 50, 100, 500, 1000 };
		std::array<int, NUMB_SYMBOL> symbolCount			 = { 0, };


		auto lambda_SubtractionExpression = [&](int currentSymbolIndex, int currentValue) -> std::optional<std::pair<string, int>>
		{
			//if
			//currentValue == 994;
			//currentSymbolIndex == 6 -> symbolValue[6] == 1000
			if (currentSymbolIndex >= NUMB_SYMBOL - 1)
				return {};
			//I 0 -> V 1,X 2
			//X 2 -> L 3,C 4
			//C 4 -> D 5,M 6

			const auto& prevSymbolIdx = currentSymbolIndex + 1;
			const auto& subtractRomanIdx = prevSymbolIdx % 2 == 0 ? prevSymbolIdx - 2 : prevSymbolIdx -1 ;

			if (currentValue >= (symbolValue[prevSymbolIdx] - symbolValue[subtractRomanIdx]))
			{
				string subtractionExpression = "";
				subtractionExpression += romanSymbol[subtractRomanIdx];
				subtractionExpression += romanSymbol[prevSymbolIdx];
				return std::make_pair(subtractionExpression, currentValue - (symbolValue[prevSymbolIdx] - symbolValue[subtractRomanIdx]));
			}

			return {};
		};

		auto lambda_RomanExpression = [&](const int count, const int roman_index) -> string
		{
			string str;
			for (int i = 0; i < count; ++i)
				str += romanSymbol[roman_index];

			return str;
		};

		string result = "";
		int idx = NUMB_SYMBOL - 1;
		while (idx >= 0)
		{
			if (auto count = num / symbolValue[idx]; count > 0)
			{
				//이전껄로 비교할 수 있는지 체크
				if (auto subtractionExpr = lambda_SubtractionExpression(idx, num))
				{
					const auto& [subtrationString, newNum] = subtractionExpr.value();
					result += subtrationString;
					num = newNum;
				}
				else
				{
					//subtractionExpr이 없을 경우, 일반 추가 (후위)
					result += lambda_RomanExpression(count, idx);
					num %= symbolValue[idx];
				}
			}
			idx--;
		}

		return result;
	}


	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		std::cout << intToRoman(3) << std::endl; //III
		std::cout << intToRoman(58) << std::endl; //LVIII
		std::cout << intToRoman(1994) << std::endl; //MCMXCIV
	}
};

