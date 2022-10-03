#pragma once
#include "ISoultion.h"
#include <algorithm>
/// <summary>
/// https://leetcode.com/problems/generate-parentheses/
/// </summary>
/// <returns></returns>
class LeetCode_22 : public ISolution {
public:

	//n개의  pairs of parentheses, 
	//3개의 ()로 닫기 잘 만들어 져 있는거 구하기.
	//()로 할 수 있는 조합 다 찾고..?
	//잘 만들어진것만 검사하면될거같은데?

	//입력된 n으로 (쌍을 넣어서 만들 수 있는 조합 만들기)
	//// 0::(, 1::)로 나타낼 수 있음
	//조합에서 () 잘 만들어진거 골라내기

	vector<string> generateParenthesis(int n) {
		
		auto Check = [](const string& str) -> bool {
			int balance(0);
			for (const auto& ch : str) {
				if (ch == '(') {
					balance++;
				}
				else if (ch == ')')
				{
					balance--;
					if (balance < 0)
						return false;
				}
			}

			return balance == 0;
		};

		std::vector<string> result;
		std::string str = std::string(n, '(') + std::string(n, ')');

		std::sort(str.begin(), str.end()); //( 부터 나오려나??

		do {

			if (Check(str))
				result.push_back(str);

		} while (next_permutation(str.begin(), str.end()));
			
		return result;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
		std::vector<string> res;
		res = generateParenthesis(3);
		//"((()))","(()())","(())()","()(())","()()()"

		res = generateParenthesis(1);
		//["()"]
	}

};