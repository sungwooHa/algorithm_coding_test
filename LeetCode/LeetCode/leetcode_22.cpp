#pragma once
#include "ISoultion.h"
#include <algorithm>
/// <summary>
/// https://leetcode.com/problems/generate-parentheses/
/// </summary>
/// <returns></returns>
class LeetCode_22 : public ISolution {
public:

	//n����  pairs of parentheses, 
	//3���� ()�� �ݱ� �� ����� �� �ִ°� ���ϱ�.
	//()�� �� �� �ִ� ���� �� ã��..?
	//�� ��������͸� �˻��ϸ�ɰŰ�����?

	//�Էµ� n���� (���� �־ ���� �� �ִ� ���� �����)
	//// 0::(, 1::)�� ��Ÿ�� �� ����
	//���տ��� () �� ��������� ��󳻱�

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

		std::sort(str.begin(), str.end()); //( ���� ��������??

		do {

			if (Check(str))
				result.push_back(str);

		} while (next_permutation(str.begin(), str.end()));
			
		return result;
	}

	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
		std::vector<string> res;
		res = generateParenthesis(3);
		//"((()))","(()())","(())()","()(())","()()()"

		res = generateParenthesis(1);
		//["()"]
	}

};