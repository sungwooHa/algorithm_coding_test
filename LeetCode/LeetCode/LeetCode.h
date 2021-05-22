#pragma once
#include <vector>
#include <string>
#include "ISoultion.h"

using namespace std;

class LeetCode_1 : public ISolution {
public:
	vector<int> twoSum(vector<int>& nums, int target);

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override;
};

class LeetCode_9 : public ISolution
{
public:
	bool isPalindrome(int x);
	bool isPalindrome_recommand(int x);
	virtual void Drive() override;

};

class LeetCode_13 : public ISolution
{
public:
	int romanToInt(string s);
	int romanToInt_recommand(string s);
	virtual void Drive() override;

};


class LeetCode_14 : public ISolution
{
public:
	string longestCommonPrefix(vector<string>& strs);
	virtual void Drive() override;

};