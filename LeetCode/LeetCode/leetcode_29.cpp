#pragma once
#include "ISoultion.h"
#include <algorithm>
/// <summary>
/// https://leetcode.com/problems/divide-two-integers/
/// </summary>
/// <returns></returns>
class LeetCode_29 : public ISolution {
public:
	int divide(int dividend, int divisor) {
		//divide �����
		//��/������/������ ���� ��� X

		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX;

		if (dividend == INT_MIN && divisor == 1)
			return INT_MIN;

		long int dvd{ abs(dividend) };
		long int dvs{ abs(divisor) };
		int res{ 0 };
		
		//dvs�� �ϳ��� ���ϸ鼭 ��������.
		while (dvd >= dvs)
		{
			long int mul = dvs, tmp = 1;
			while (mul <= dvd - mul) 
			{
				mul += mul;
				tmp += tmp;
			}
			res += tmp;
			dvd -= mul;
		}

		//If either of dividend or divisor is negative our result will be negative
		return dividend < 0 ^ divisor < 0 ? -res : res;
	}

	// ISolution��(��) ���� ��ӵ�
	virtual void Drive() override
	{
		divide(10, 3);
	}

};