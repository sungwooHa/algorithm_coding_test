#include "LeetCode.h"
#include <stack>
#include <iostream>
#include <deque>

/// <summary>
/// https://leetcode.com/problems/two-sum/
/// </summary>
/// <param name="nums"> 입력되는 숫자 배열 </param>
/// <param name="target">2개를 더해서 만들고 싶은 숫자 </param>
/// <returns>target을 만들 수 있는 두 수 </returns>
vector<int> LeetCode_1::twoSum(vector<int>& nums, int target)
{
	std::vector<int> svRes(2);
	for (unsigned int i = 0; i < nums.size() - 1; ++i)
	{
		for (unsigned int j = i + 1; j < nums.size(); ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				svRes[0] = i;
				svRes[1] = j;
				return svRes;

			}
		}
	}
	return svRes;
}

void LeetCode_1::Drive()
{
	auto lambda_verify = [&](std::vector<int> nums, int target, std::vector<int>result) -> void
	{
		auto val = twoSum(nums, target);
		assert(val[0] == result[0]);
		assert(val[1] == result[1]);
		return;
	};

	lambda_verify({ 2, 7, 11, 15 }, 9, { 0, 1 });
	lambda_verify({ 3, 2, 4 }, 6, { 1, 2, });
}

/// <summary>
/// interger x
/// if x is palindrome integer
/// return ture
/// 
/// palindorme : 121, 131 etc.
/// 
/// </summary>
/// <param name="x"></param>
/// <returns></returns>
bool LeetCode_9::isPalindrome(int x)
{
	if (x < 0)
		return false;

	if (x != 0 && x % 10 == 0)
		return false;

	int reverseX = 0;
	while (reverseX < x)
	{
		int pop = x % 10;
		x /= 10;

		if (INT_MAX / 10 < reverseX)
			return false;
		reverseX *= 10;
		reverseX += pop;
	}
	//짝수일때, 홀수일때

	return x == reverseX / 10 || x == reverseX;
}

bool LeetCode_9::isPalindrome_recommand(int x) {
	if (x < 0 || (x % 10 == 0 && x != 0))
		return false;
	int reverse = 0;
	while (x > reverse) {
		reverse = reverse * 10 + x % 10;
		x /= 10;
	}
	return (x == reverse) || (x == reverse / 10);
}

void LeetCode_9::Drive()
{
	assert(isPalindrome(121) == true);
	assert(isPalindrome(-121) == false);
	assert(isPalindrome(10) == false);
	assert(isPalindrome(-101) == false);
	assert(isPalindrome(22) == true);
	assert(isPalindrome(1234567899) == false);
}

/// <summary>
/// slidng window.
/// 연산이 될 경우 index+=2
/// 연산이 안될경우 단일 연산 후 index++
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
int LeetCode_13::romanToInt(string s)
{
	auto lambada_Convert = [&](char ch) -> int
	{
		switch (ch)
		{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		}
		return -1;
	};

	auto lambda_Comp = [&](char ch1, char ch2) -> int
	{
		if (((ch1 == 'I' && ch2 == 'V')
			|| (ch1 == 'I' && ch2 == 'X'))  //case 1
			|| ((ch1 == 'X' && ch2 == 'L')
				|| (ch1 == 'X' && ch2 == 'C')) //case 2
			|| ((ch1 == 'C' && ch2 == 'D')
				|| (ch1 == 'C' && ch2 == 'M'))) //case 3
		{
			return lambada_Convert(ch2) - lambada_Convert(ch1);
		}
		else
		{
			return -1;
		}
	};

	int answer = 0;

	int index = 0;
	while (true)
	{
		if (s.size() > index + 1)
		{
			auto val = lambda_Comp(s[index], s[index + 1]);
			if (val == -1)
			{
				answer += lambada_Convert(s[index]);
				index++;
			}
			else
			{
				answer += val;
				index += 2;
			}
		}
		else if (s.size() - 1 == index) //마지막
		{
			answer += lambada_Convert(s[index]);
			break;
		}
		else
			break;
	}

	return answer;
}

int LeetCode_13::romanToInt_recommand(string s)
{
	return 0;
}

void LeetCode_13::Drive()
{
	assert(romanToInt("III") == 3);
	assert(romanToInt("IV") == 4);
	assert(romanToInt("IX") == 9);
	assert(romanToInt("LVIII") == 58);
	assert(romanToInt("MCMXCIV") == 1994);
	assert(romanToInt("MCDLXXVI") == 1476);
	assert(romanToInt("MCMXCIV") == 1994);

}

/// <summary>
/// prefix 찾기
/// </summary>
/// <param name="strs">단어 배열</param>
/// <returns></returns>
string LeetCode_14::longestCommonPrefix(vector<string>& strs)
{
	size_t length(INT_MAX);

	for (int i = 0; i < strs.size(); ++i)
	{
		if (length > strs[i].size())
			length = strs[i].size();

		if (i < strs.size() - 1)
			if ((strs[i][0] != strs[i + 1][0]))
				return "";
	}

	for (unsigned int idxCh = 0; idxCh < length; ++idxCh)
	{
		for (int idxStr = 0; idxStr < strs.size() - 1; ++idxStr)
		{
			if (strs[idxStr][idxCh] == strs[idxStr + 1][idxCh])
				continue;

			return strs[0].substr(0, idxCh);
		}
	}

	return strs[0].substr(0, length);
}

void LeetCode_14::Drive()
{
	std::vector<string> strs = { "dog", "racecar", "car" };
	auto val = longestCommonPrefix(strs); //fl
	assert(strcmp(val.c_str(), "") == 0);

	strs = {
		"ab", "a" };
	val = longestCommonPrefix(strs);
	assert(strcmp(val.c_str(), "a") == 0);

	strs = {
		"flower", "flow", "flight" };
	val = longestCommonPrefix(strs);
	assert(strcmp(val.c_str(), "fl") == 0);
}

/// <summary>
/// 괄호 짝맞추기.
/// stack 이용해 계속 input
/// </summary>
/// <param name="s"></param>
/// <returns></returns>
bool LeetCode_20::isValid(string s)
{
	stack<char> bracketStack;

	int index(0);
	bracketStack.push(s[index++]);
	while (!bracketStack.empty())
	{
		if (index > (s.size() - 1))
			return false;

		auto curBracket = bracketStack.top();

		if (s[index] == ')' && curBracket == '(')
		{
			bracketStack.pop();
		}
		else if (s[index] == ']' && curBracket == '[')
		{
			bracketStack.pop();
		}
		else if (s[index] == '}' && curBracket == '{')
		{
			bracketStack.pop();
		}
		else
			bracketStack.push(s[index]);

		++index;

		if (bracketStack.empty() && index < s.size())
		{
			bracketStack.push(s[index]);
			++index;
		}
	}
	return true;
}

void LeetCode_20::Drive()
{
	assert(isValid("()") == true);
	assert(isValid("()[]{}") == true);
	assert(isValid("(]") == false);
	assert(isValid("([)]") == false);
	assert(isValid("{[]}") == true);
}


LeetCode_21::ListNode* LeetCode_21::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	if (!l1 && !l2)
		return NULL;
	ListNode* first(nullptr);
	ListNode* curNode(nullptr);

	while (true)
	{
		if (!curNode)
		{
			if (!l1)
				return l2;
			if (!l2)
				return l1;

			if (l1->val < l2->val)
			{
				curNode = l1;
				l1 = l1->next;
			}
			else
			{
				curNode = l2;
				l2 = l2->next;
			}
			first = curNode;
		}

		if (l1 == nullptr)
		{
			curNode->next = l2;
			break;
		}

		if (l2 == nullptr)
		{
			curNode->next = l1;
			break;
		}

		if (l1->val < l2->val)
		{
			curNode->next = l1;
			l1 = l1->next;
		}
		else
		{
			curNode->next = l2;
			l2 = l2->next;
		}
		curNode = curNode->next;
	}

	return first;
}

void LeetCode_21::Drive()
{
	auto list1 = CreateList({ 1, 2, 4 });
	auto list2 = CreateList({ 1, 3, 4 });
	auto answer = mergeTwoLists(list1, list2);

	while (answer != nullptr)
	{
		std::cout << answer->val << std::endl;
		answer = answer->next;
	}

}

/// <summary>
/// rmoeve duplicates
/// return : array size
/// paramete : without dupliates
/// </summary>
/// <param name="nums"></param>
/// <returns></returns>
int LeetCode_26::removeDuplicates(vector<int>& nums)
{
	deque<int> dq;
	for (const auto& num : nums)
	{
		if (dq.empty())
		{
			dq.push_back(num);
			continue;
		}
		if (dq.back() == num)
			continue;
		dq.push_back(num);
	}

	nums.resize(dq.size());
	for (auto num : nums)
	{
		num = dq.front();
		dq.pop_front();
	}
	
	return nums.size();
}

void LeetCode_26::Drive()
{
	vector<int> nums = { 1, 1, 2 };
	assert(removeDuplicates(nums) == 2);

	 nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	assert(removeDuplicates(nums) == 5);	
	
	nums = {};
	assert(removeDuplicates(nums) == 0);
}

int LeetCode_27::removeElement(vector<int>& nums, int val)
{
	if (nums.empty())
		return 0;

	int realIdx(0);
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] != val)
		{
			nums[realIdx++] = nums[i];
		}
	}

	return realIdx;
}

void LeetCode_27::Drive()
{
	vector<int> nums = { 3, 2, 2, 3 };
	assert(removeElement(nums, 2) == 2);

	nums = { 3, 2, 2, 3 };
	assert(removeElement(nums, 3) == 2);

	nums = { 3, 2, 2, 3 };
	assert(removeElement(nums, 1) == 4);

	nums = {  };
	assert(removeElement(nums, 1) == 0);

	nums = { 0, 1, 2, 2, 3, 0, 4, 2 };
	assert(removeElement(nums, 2) == 5);
}

int LeetCode_28::strStr_hash(string haystack, string needle)
{
	auto charToInt = [&](int idx, string s) -> int
	{
		return (int)s[idx] - (int)'a';
	};

	int L = needle.length(), n = haystack.length(); 
	
	if (L > n) return -1; // base value for the rolling hash function
	int a = 26; // modulus value for the rolling hash function to avoid overflow 
	long modulus = (long)pow(2, 31)-1; // compute the hash of strings haystack[:L], needle[:L]

	long h = 0, ref_h = 0; 
	for (int i = 0; i < L; ++i) 
	{
		h = (h * a + charToInt(i, haystack)) % modulus;
		ref_h = (ref_h * a + charToInt(i, needle)) % modulus; 
	} 
	
	if (h == ref_h) 
		return 0;

	// const value to be used often : a**L % modulus 
	long aL = 1; 
	for (int i = 1; i <= L; ++i)
		aL = (aL * a) % modulus; 
	for (int start = 1; start < n - L + 1; ++start) 
	{ 
		// compute rolling hash in O(1) time 
		h = (h * a - charToInt(start - 1, haystack) * aL + charToInt(start + L - 1, haystack)) % modulus;
		if (h == ref_h) 
			return start;
	} 
	return -1; 
}

int LeetCode_28::strStr(string haystack, string needle)
{
	if (needle.empty())
		return 0;
	if (haystack.size() < needle.size())
		return -1;

	for (int i = 0; i < haystack.size() - needle.size() + 1; ++i)
	{
		bool isFind(true);
		for (int j = 0; j < needle.size(); ++j)
		{
			if (haystack[i + j] != needle[j])
			{
				isFind = false;
				break;
			}
		}

		if (isFind)
			return i;
	}

	return -1;
}

void LeetCode_28::Drive()
{
	assert(strStr("hello", "ll") == 2);
	assert(strStr("aaaaa", "bba") == -1);
	assert(strStr("a", "a") == 0);
	assert(strStr_hash("ababaabbbbababbaabaaabaabbaaaabbabaabbbbbbabbaabbabbbabbbbbaaabaababbbaabbbabbbaabbbbaaabbababbabbbabaaabbaabbabababbbaaaaaaababbabaababaabbbbaaabbbabb",
		"abbabbbabaa") == 92);
}

/// <summary>
/// Use BST 
/// O(log N)
/// </summary>
/// <param name="nums"></param>
/// <param name="target"></param>
/// <returns></returns>
int LeetCode_35::searchInsert(vector<int>& nums, int target)
{
	long long min = 0;
	long long max = nums.size()-1;
	
	while (min <= max)
	{
		auto mid = min + (max - min) / 2;

		if (nums[mid] == target)
			return mid;

		if (target < nums[mid])
		{
			//change max
			max = mid - 1;
		}
		else
		{
			//change min
			min = mid + 1;
		}
	}
	return min;
}

void LeetCode_35::Drive()
{
	vector<int> nums = {1,3,5,6};
	assert(searchInsert(nums, 5) == 2);

	nums = { 1, 3, 5, 6 };
	assert(searchInsert(nums, 2) == 1);

	nums = { 1, 3, 5, 6 };
	assert(searchInsert(nums, 7) == 4);

	nums = { 1, 3, 5, 6 };
	assert(searchInsert(nums, 2) == 1);

	nums = { 1};
	assert(searchInsert(nums, 0) == 0);
}

int LeetCode_53::maxSubArray(vector<int>& nums)
{
	int answer = INT_MIN;
	for (unsigned int i = 0; i < nums.size(); ++i)
	{
		int tmpAnswer(0);
		for (unsigned int j = i; j < nums.size(); ++j)
		{
			tmpAnswer += nums[j];
			if (answer < tmpAnswer)
			{
				answer = tmpAnswer;
			}
		}
	}
	return answer;
}

int LeetCode_53::maxSubArray_advanced(vector<int>& nums)
{
	int currsum = 0;
	int maxsum = INT_MIN;

	for (int i = 0; i < nums.size(); i++)
	{
		currsum += nums[i];
		maxsum = max(maxsum, currsum);
		if (currsum < 0)
		{
			currsum = 0;
		}
	}

	return maxsum;
}

void LeetCode_53::Drive()
{
}
