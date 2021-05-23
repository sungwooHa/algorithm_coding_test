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

class LeetCode_20 : public ISolution
{
public:
	bool isValid(string s);
	virtual void Drive() override;
};


class LeetCode_21 : public ISolution
{
private:
	//Definition for singly - linked list.
	struct ListNode
	{
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
	virtual void Drive() override;

	ListNode* CreateList(const std::vector<int>& sv)
	{
		ListNode* first(nullptr);
		ListNode* curNode(nullptr);
		for (const auto& val : sv)
		{
			if (first == nullptr)
			{
				first = new ListNode(val);
				curNode = first;
				continue;
			}
			curNode->next = new ListNode(val);
			curNode = curNode->next;
		}
		return first;
	}
};

class LeetCode_26 : public ISolution
{
public:
	int removeDuplicates(vector<int>& nums);
	virtual void Drive() override;
};

class LeetCode_27 : public ISolution
{
public:
	int removeElement(vector<int>& nums, int val);
	virtual void Drive() override;
};

class LeetCode_28 : public ISolution
{
public:
	int strStr_hash(string haystack, string needle);
	int strStr(string haystack, string needle);
	virtual void Drive() override;
};

class LeetCode_35 : public ISolution
{
public:
	int searchInsert(vector<int>& nums, int target);
	virtual void Drive() override;
};

class LeetCode_53 : public ISolution
{
public:
	int maxSubArray(vector<int>& nums);
	int maxSubArray_advanced(vector<int>& nums);
	virtual void Drive() override;
};

class LeetCode_58 : public ISolution
{
public:
	int lengthOfLastWord(string s);
	int lengthOfLastWord_array(string s);
	virtual void Drive() override;
};
