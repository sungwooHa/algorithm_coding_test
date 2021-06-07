﻿#include "LeetCode.h"
#include <stack>
#include <iostream>
#include <deque>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <queue>
#include <optional>

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


ListNode* LeetCode_21::mergeTwoLists(ListNode* l1, ListNode* l2)
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
	auto list1 = utilClass::CreateList({ 1, 2, 4 });
	auto list2 = utilClass::CreateList({ 1, 3, 4 });
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
		maxsum = std::max(maxsum, currsum);
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


/// <summary>
/// use List.
/// find length of last word
/// </summary>
/// <param name="s"> 1) "hello world"</param>
/// <param name="s"> 2) "a " </param>
/// <returns> 1) 5</returns>
/// <returns> 2) 1</returns>
int LeetCode_58::lengthOfLastWord(string s)
{
	int count(0);
	bool isMeetWord(false);
	for (auto itr = s.rbegin(); itr != s.rend(); ++itr)
	{
		if (*itr == ' ')
		{
			if (!isMeetWord)
				continue;
			else
				break;;
		}
		else
			isMeetWord = true;

		count++;
	}

	return count;
}

int LeetCode_58::lengthOfLastWord_array(string s)
{
	int count(0);
	bool isMeetWord(false);

	for (int i = s.length()-1; i >= 0; --i)
	{
		if (s[i] == ' ')
		{
			if (!isMeetWord)
				continue;
			else
				break;
		}
		else
			isMeetWord = true;

		count++;
	}
	return count;
}

void LeetCode_58::Drive()
{
}

TreeNode* LeetCode_105::buildTree(vector<int>& preorder, vector<int>& inorder)
{
	if (preorder.empty() || inorder.empty())
		return nullptr;

	//preorder의 맨앞 : root
	//inordered: 중간 : root

	int rootVal = *preorder.begin();
	int rootIdx = 0;
	for (int idx = 0; idx < inorder.size(); idx++)
	{
		if (rootVal == inorder[idx])
		{
			rootIdx = idx;
			break;
		}
	}
	//<1>,<2>,<3>,<4>,5,6
	//<2>,<3>,<1>,5,<4>,6
	// 
	//inorderd의 rootidx
	//    left subtree - <rootIdx> - right  subtree

	//leftSubTree가 있고, preOrder의 root+1 의 값이 존재하는가? --> 없으면 rigth subtree의 root값
	//preOrdred의 root+1 == leftSubtree rootValue;

	auto lambda_Tree = [&](int rootIdx, int leftIdx, int rightIdx) -> TreeNode*
	{
		return nullptr;
	};

	return nullptr;
}

void LeetCode_105::Drive()
{
}

int LeetCode_1375::numTimesAllBlue(vector<int>& light)
{
	int bulbCount(0);
	int answer(0);
	int maxNumb(0);
	for (const auto& moment : light)
	{
		if (moment > maxNumb)
			maxNumb = moment;
		
		bulbCount++;
		if (bulbCount == maxNumb)
			answer++;
	}

	return answer;
}

void LeetCode_1375::Drive()
{
}

int LeetCode_822::flipgame(vector<int>& fronts, vector<int>& backs)
{
	int answer = INT_MAX;
	for (int i = 0; i < fronts.size(); i++)
	{
		if (fronts[i] == backs[i])
			continue;

		std::swap(fronts[i], backs[i]);

		if(auto itrFront = find(fronts.begin(), fronts.end(), backs[i]); itrFront == fronts.end())
		{
			answer = std::min(answer, backs[i]);
		}

		if (auto itrBack = find(backs.begin(), backs.end(), fronts[i]); itrBack == backs.end())
		{
			answer = std::min(answer, fronts[i]);
		}

		std::swap(fronts[i], backs[i]);
	}
	return answer == INT_MAX ? 0 : answer;
}

void LeetCode_822::Drive()
{
	vector<int> front = { 1, 2, 4, 4, 7 };
	vector<int> back = { 1, 3, 4, 1, 3 };


	assert(flipgame(front, back) == 2);

	front = { 1, 1 };
	back = { 1, 2 };
	assert(flipgame(front, back) == 2);

	front = { 2, 2, 5, 1, 2 };
	back = { 4, 1, 2, 1, 1 };
	assert(flipgame(front, back) == 2);

	front = { 1, 1 };
	back = { 2, 2 };
	assert(flipgame(front, back) == 1);
}

bool LeetCode_693::hasAlternatingBits(int n)
{	
	bool val = n % 2;
	n = n >> 1;
	while (n > 0)
	{
		if (val == n % 2)
			return false;
		val = n % 2;
		n = n >> 1;
	}
	return true;
}

void LeetCode_693::Drive()
{
	assert(hasAlternatingBits(5) == true);
	assert(hasAlternatingBits(4) == false);
}

vector<int> LeetCode_66::plusOne(vector<int>& digits)
{
	auto lastIdx = digits.size() - 1;

	for (int lastIdx = digits.size() - 1; lastIdx >= 0; --lastIdx)
	{
		if (digits[lastIdx] < 9)
		{
			digits[lastIdx]++;
			return digits;
		}

		digits[lastIdx] = 0;
	}

	digits[0]++;
	digits.push_back(0);
	return digits;

	while (true)
	{
		if (digits[lastIdx] == 9)
		{
			digits[lastIdx] = 0;
			if (lastIdx == 0)
			{
				digits.insert(digits.begin(), 1);
				break;
			}
			else
			{
				lastIdx -= 1;
			}
		}
		else
		{
			digits[lastIdx] += 1;
			break;
		}
	}
	return digits;
}

void LeetCode_66::Drive()
{

	auto lambda_verify = [&](const std::vector<int>& res, const std::vector<int>& expect) -> void
	{
		assert(res.size() == expect.size());
		for (auto i = 0; i < expect.size(); i++)
		{
			assert(res[i] == expect[i]);
		}
	};

	std::vector<int> nums, expect;
	nums = { 1, 2, 3 };
	expect = { 1, 2, 4 };

	auto res = plusOne(nums);

	lambda_verify(expect, res);

	nums = { 9 };
	expect = { 1,0 };
	res = plusOne(nums);
	lambda_verify(expect, res);

	nums = { 0 };
	expect = { 1 };
	res = plusOne(nums);
	lambda_verify(expect, res);

}

string LeetCode_67::addBinary(string a, string b)
{
	string res;
	bool preVal(false);
	int idxA(a.length() - 1);
	int idxB(b.length() - 1);

	while (idxA >= 0 || idxB >= 0)
	{
		if (idxA < 0)
		{
			if (preVal)
			{
				if (b[idxB] == '0')
				{
					preVal = false;
					res.insert(res.begin(), '1');
				}
				else
				{
					preVal = true;
					res.insert(res.begin(), '0');
				}
			}
			else
			{
				res.insert(res.begin(), b[idxB]);
			}
			idxB--;
			continue;
		}

		if (idxB < 0)
		{
			if (preVal)
			{
				if (a[idxA] == '0')
				{
					preVal = false;
					res.insert(res.begin(), '1');
				}
				else
				{
					preVal = true;
					res.insert(res.begin(), '0');
				}
			}
			else
			{
				res.insert(res.begin(), a[idxA]);
			}
			idxA--;
			continue;
		}

		if (preVal)
		{
			if (a[idxA] == '1' && b[idxB] == '1')
			{
				res.insert(res.begin(), '1');
			}
			else if (a[idxA] == '0' && b[idxB] == '0')
			{
				preVal = false;
				res.insert(res.begin(), '1');
			}
			else
			{
				res.insert(res.begin(), '0');
			}
		}
		else
		{
			if (a[idxA] == '1' && b[idxB] == '1')
			{
				preVal = true;
				res.insert(res.begin(), '0');
			}
			else if (a[idxA] == '0' && b[idxB] == '0')
			{
				res.insert(res.begin(), '0');
			}
			else
			{
				res.insert(res.begin(), '1');
			}
		}

		idxA--;
		idxB--;

	}

	if (preVal)
		res.insert(res.begin(), '1');
	return res;
}

void LeetCode_67::Drive()
{
	assert(addBinary("11", "1") == "100");
	assert(addBinary("1010", "1011") == "10101");
	assert(addBinary("1", "111") == "1000");
}

vector<int> LeetCode_1073::addNegabinary(vector<int>& arr1, vector<int>& arr2)
{
	int idx1 = arr1.size() - 1;
	int idx2 = arr2.size() - 1;

	//example
	//1,1,1,1,1
	//    1,0,1
	//+ - + - +  //-부터
	//---------
	//1,0,0,0,0

	//1,1,1,1,1 -->  11
	//  1,0,1,0 --> -10
	//+ - + - +  //-부터
	//---------
	//0,0,0,0,1

	std::vector<int> answer;
	int carray(0);
	while (idx1 >= 0 || idx2 >= 0 || carray != 0) //carray가 남아있으면 push back해야함
	{
		//거꾸로.
		//마지막 index부터 더함
		if (idx1 >= 0)
			carray += arr1[idx1--];
		if (idx2 >= 0)
			carray += arr2[idx2--];

		//and 연산을 통해서.
		//3(11) & 1 == 1;
		//2(10) & 1 == 0
		//1( 1)	& 1 == 1;
		//0( 0)	& 1 == 0
		answer.push_back(abs(carray) & 1); //(1 or 0)
		
		//next carray
		if (carray > 1)  //바로 앞의 자릿수의 값과 - 해야함(부호가 다르기 떄문)
			carray = -1;
		else if (carray < 0) //-1
			carray = 1;
		else
			carray = 0;  //0,1
	}

	while (answer.size() > 1 && answer.back() == 0) //제일 앞자리가 0일 경우
		answer.pop_back();

	std::reverse(answer.begin(), answer.end());

	return vector<int>(answer);
}

void LeetCode_1073::Drive()
{
}

int LeetCode_150::evalRPN(vector<string>& tokens)
{
	std::unordered_map<string, int> op; //operator
	op.emplace("+", 0);
	op.emplace("-", 1);
	op.emplace("*", 2);
	op.emplace("/", 3);

	auto lambda_calc = [&](int val1, int val2, int op) -> int
	{
		switch (op)
		{
		case 0:
			return val1 + val2;
		case 1:
			return val1 - val2;
		case 2:
			return val1 * val2;
		case 3:
			return val1 / val2;
		default:
			break;
		}
		assert(false);
		return 0;
	};

	std::queue<string> qTocken;
	for (const auto& token : tokens)
		qTocken.push(token);

	std::stack<int> sNumb;
	while (!qTocken.empty())
	{
		auto tocken = qTocken.front();
		qTocken.pop();
		if (op.end() == op.find(tocken))
		{
			//숫자
			sNumb.push(std::atoi(tocken.c_str()));
		}
		else
		{
			//operator 연산
			auto val2 = sNumb.top();
			sNumb.pop();
			auto val1 = sNumb.top();
			sNumb.pop();

			auto res = lambda_calc(val1, val2, op[tocken]);
			sNumb.push(res);
		}
	}

	if (sNumb.size() != 1)
	{
		assert(false);
		return 0;
	}

	return sNumb.top();
}

int LeetCode_150::evalRPN_other(vector<string>& tokens)
{
	stack<int>st;
	for (auto it : tokens)
	{
		if (it == "+" || it == "-" || it == "*" || it == "/")
		{
			int f = st.top(); st.pop();
			int s = st.top(); st.pop();

			if (it == "+")
			{
				int r = s + f;  st.push(r);
			}
			else if (it == "*")
			{
				int r = s * f;  st.push(r);
			}
			else if (it == "-")
			{
				int r = s - f;   st.push(r);
			}
			else if (it == "/")
			{
				int r = s / f;   st.push(r);
			}
		}
		else { st.push(stoi(it)); }
	}
	return st.top();
}

void LeetCode_150::Drive()
{
	vector<string> tockens;
	tockens = { "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+" };
	assert(evalRPN_other(tockens) == 22);

	tockens = { "2", "1", "+", "3", "*" };
	assert(evalRPN_other(tockens) == 9);

	tockens = { "4", "13", "5", "/", "+" };
	assert(evalRPN_other(tockens) == 6);

}

int LeetCode_69::mySqrt(int x)
{
	if (!x) return 0;

	unsigned long long min = 0;
	unsigned long long max = x;

	unsigned long long  res(0);
	while (min <= max)
	{
		unsigned long long mid = (min + max) >> 1;
		unsigned long long square = mid * mid;

		if (square == x)
			return mid;

		if (square < x)
		{
			min = mid + 1;
			res = mid;
		}
		else //  x < (mid*mid)
		{
			max = mid - 1;
		}
	}

	return res;
}

void LeetCode_69::Drive()
{
}


int LeetCode_70::climbStairs(int n)
{
	//1 :1 = 1
	//2 :2 = 1+1, 2,
	//3 :3 = 1+1+1, 1+2, 2+1
	//4 :5 = 1+1+1+1, 1+1+2, 1+2+1, 2+1+1. 2+2
	//5 :8 = 1+1+1+1+1, 1+1+1+2, 1+1+2+1, 1+2+1+1, 2+1+1+1. 1+2+2, 2+1+2, 2+2+1, 
	

	if (n == 1)
		return 1;

	if (n == 2)
		return 2;


	int cur1 = 1;
	int cur2 = 2;

	for (int step = 3; step <= n; step++)
	{
		int cur3 = cur1 + cur2;
		cur1 = cur2;
		cur2 = cur3;
	}

	return cur2;
}

void LeetCode_70::Drive()
{
	auto val = climbStairs(44);
	
	return;
}

ListNode* LeetCode_83::deleteDuplicates(ListNode* head)
{
	auto first = head;
	while (head)
	{
		int preVal = head->val;
		while (head->next)
		{
			if (preVal == head->next->val)
				head->next = head->next->next;
			else
			{
				break;
			}
		}

		head = head->next;
	}
	return first;
}

void LeetCode_83::Drive()
{
	std::vector<int> sv;
	sv = { 1, 1, 1 };
	auto first = utilClass::CreateList(sv);

	auto val = deleteDuplicates(first);
}

void LeetCode_94::search(TreeNode* curNode, std::vector<int>& answer)
{
	if (!curNode)
		return;

	search(curNode->left, answer);
	answer.push_back(curNode->val);
	search(curNode->right, answer);
}

vector<int> LeetCode_94::inorderTraversal(TreeNode* root)
{
	std::vector<int> answer;
	search(root, answer);
	return answer;
}

bool LeetCode_100::isSameTree(TreeNode* p, TreeNode* q)
{
	if (!p && !q)
		return true;

	if (!p || !q)
		return false;

	if (p->val != q->val)
		return false;

	if (!isSameTree(p->left, q->left))
		return false;

	if (!isSameTree(p->right, q->right))
		return false;

	return true;
}

void LeetCode_100::Drive()
{
}

void LeetCode_101::PreorderSearch(TreeNode* curNode, std::vector<int>& answer)
{
	if (!curNode)
	{
		answer.push_back(-101);
		return;
	}

	answer.push_back(curNode->val);
	PreorderSearch(curNode->left, answer);
	PreorderSearch(curNode->right, answer);
}

void LeetCode_101::rPreorderSearch(TreeNode* curNode, std::vector<int>& answer)
{
	if (!curNode)
	{
		answer.push_back(-101);
		return;
	}

	answer.push_back(curNode->val);
	rPreorderSearch(curNode->right, answer);
	rPreorderSearch(curNode->left, answer);
}

bool LeetCode_101::isSymmetric(TreeNode* root)
{
	std::vector<int> left, right;
	PreorderSearch(root->left, left);
	rPreorderSearch(root->right, right);

	if (left.size() != right.size())
		return false;

	for (int i = 0; i < left.size(); i++)
	{

		if (left[i] != right[i])
			return false;
	}

	return true;

	//			    1
	//		 2    	       3
	//     4     5     6        7
	//    8 9  10 11  12 13   14 15
	//1
	//2,4,8 ,9 ,5,10,11
	//3,6,12,13,7,14,15

	//1
	//3,7,15,14,6,13,12

	//[1,2,2,2,null,2]
	//				1
	//            2   2
	//			2 null 2, ?


	return true;
}

void LeetCode_101::Drive()
{
}

int LeetCode_104::find(TreeNode* node, int depth)
{
	if (!node)
		return depth;

	int leftDepth = find(node->left, depth + 1);
	int rightDepth = find(node->right, depth + 1);

	return leftDepth < rightDepth ? rightDepth : leftDepth;
}

int LeetCode_104::maxDepth(TreeNode* root)
{
	return find(root, 0);
}

void LeetCode_104::Drive()
{
}

int LeetCode_1334::findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
{
	//from, to, weight
	//모든 node를연결
	//특정 시티에서 distanceThresHold값이 넘지않아야함
	//들리는 시티수가 가장 많고
	//시티수가 같다면, 시티 numb가 가장높은 city를 출력

	//각 city에서 distanceThreshold내에 갈 수 있는 최소비용 경로 구하기
	//가장 많은 city를 방문할 수 있는 city구하기
	//city numb가 가장큰 city 구하기


	//create graph
	std::unordered_map<int, std::vector<std::pair<int, int>>> graph; //from, arr( std::pair(to, weight))

	for (const auto& info : edges)
	{
		graph[info[0]].push_back(std::make_pair(info[1], info[2]));
		graph[info[1]].push_back(std::make_pair(info[0], info[2])); //bidirection
	}

	//answer
	int resCity(0);
	int numbVisitCity(INT_MAX);
	////
	for (int city = 0; city < n; city++)
	{
		std::unordered_map<int, int> mNextCity; //next city, weight
		for (int i = 0; i < n; i++)
			mNextCity[i] = INT_MAX;

		mNextCity[city] = 0; //myself

		std::priority_queue<std::pair<int, int>> pqWeightCity;
		pqWeightCity.push(std::make_pair(mNextCity[city], city));

		while (!pqWeightCity.empty())
		{
			auto weight = -pqWeightCity.top().first; //가장 가까운순서로 하기때문에,
			auto visitCity = pqWeightCity.top().second;

			pqWeightCity.pop();

			if (weight > distanceThreshold)//threshold 넘는건 방문 필요 없음.
				continue;

			if (weight < mNextCity[visitCity]) //weight가 클 경우 할 필요 없음
				continue;

			//현재 방문하는 city에 연결되어있는 city들
			for (const auto& edgeInfo : graph[visitCity])
			{
				auto nextCity = edgeInfo.first;
				auto nextWeight = edgeInfo.second;

				if (weight + nextWeight > distanceThreshold)
					continue;

				if (mNextCity[nextCity] > (nextWeight + weight))
				{
					mNextCity[nextCity] = nextWeight + weight;
					pqWeightCity.push({ -mNextCity[nextCity], nextCity });
				}
			}
		}

		auto tmpNumbCity(0);
		for (const auto& visitCity : mNextCity)
		{
			if (visitCity.first == city) //자기자신 제외
				continue;

			//thredhold 보다 클 경우 제외
			if (visitCity.second  > distanceThreshold)
				continue;
			tmpNumbCity++;
		}

		if (tmpNumbCity < numbVisitCity)
		{
			resCity = city; //visity city 적은 순으로
			numbVisitCity = tmpNumbCity;
		}
		else if (tmpNumbCity == numbVisitCity)
		{
			if (resCity < city)
			{
				resCity = city; //city numb 높은 걸로 바꿈
				numbVisitCity = tmpNumbCity;
			}
		}
	}

	return resCity;
}

void LeetCode_1334::Drive()
{

	int n = 0;
	std::vector<std::vector<int>> edges;
	int distanceThresHold = 0;

	n = 4;
	edges = { { 0, 1, 3 }, { 1, 2, 1 }, { 1, 3, 4 }, { 2, 3, 1 } };
	distanceThresHold = 4;
	assert(findTheCity(n, edges, distanceThresHold) == 3);

	n = 5;
	edges = { { 0, 1, 2 }, { 0, 4, 8 }, { 1, 2, 3 }, { 1, 4, 2 }, { 2, 3, 1 }, { 3, 4, 1 } };
	distanceThresHold = 2;
	assert(findTheCity(n, edges, distanceThresHold) == 0);


	n = 5;
	edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
	distanceThresHold = 2;
	assert(findTheCity(n, edges, distanceThresHold) == 0);
}

vector<TreeNode*> LeetCode_95::GeneratePartialTree(int start, int end)
{
	std::vector<TreeNode*> resArrTree;

	if (start > end) //null
	{
		resArrTree.push_back(NULL);
		return resArrTree;
	}

	for (int i = start; i <= end; ++i)
	{
		auto leftTree = GeneratePartialTree(start, i - 1);
		auto rightTree = GeneratePartialTree(i + 1, end);

		for (auto left : leftTree)
		{
			for (auto right : rightTree)
			{
				TreeNode* root = new TreeNode(i);
				root->left = left;
				root->right = right;
				resArrTree.push_back(root);
			}
		}
	}

	return vector<TreeNode*>(resArrTree);
}

vector<TreeNode*> LeetCode_95::generateTrees(int n)
{
	vector<TreeNode*> arrTree;
	if (n == 0) return arrTree;

	return GeneratePartialTree(1, n);
}

void LeetCode_95::Drive()
{
	auto tree1 = generateTrees(3);
	auto tree2 = generateTrees(1);


}

TreeNode* LeetCode_108::sortedArrayToBST(vector<int>& nums)
{
	//bst
	//nums를 정렬하고 하면되지 않나?
	// 
	//root[0] : 0
	// 
	//left[1] :  0+1
	//right[2] : 0+2  
	// 
	//left-left[3] 0 + 1 + 2
	//left-right[4] 0 + 1 + 3
	//right-left[5]  0 + 2 + 3
	//right-right[6] 0 + 2 + 4
	//
	//left-left-left[7] 0 + 1 + 2 + 4
	//left-left-right[8] 0 + 1 + 2 + 5
	//left-right-left[9] 0 + 1 + 3 + 5
	//left-right-right[10] 0 + 1 + 3 + 6
	// 
	//right-left-left[11] 0 + 2 + 3 + 6
	//right-left-right[12] 0 + 2 + 3 + 7
	//right-right-left[13] 0 + 2 + 4 + 7
	//right-right-right[14] 0 + 2 + 4 + 8


	// min, max idx
	//mid  = min + max >>1

	if (nums.size() == 0)
		return nullptr;

	return GeneratedTree(0, nums.size()-1, nums);
	
}

TreeNode* LeetCode_108::GeneratedTree(int idxMin, int idxMax, const std::vector<int> nums)
{
	if (idxMin > idxMax)
		return nullptr;

	auto mid = (idxMin + idxMax) >> 1;
	auto left = GeneratedTree(idxMin, mid - 1, nums);
	auto right = GeneratedTree(mid + 1, idxMax, nums);
	TreeNode* node = new TreeNode(nums[mid]);
	node->left = left;
	node->right = right;
	return node;
}

void LeetCode_108::Drive()
{
	std::vector<int> nums;
	nums = { -10, -3, 0, 5, 9 };
	
	auto val1 = sortedArrayToBST(nums);

	nums = {1,3};
	auto val2 = sortedArrayToBST(nums);

	nums = { };
	auto val3 = sortedArrayToBST(nums);
}

bool LeetCode_110::isBalanced(TreeNode* root)
{

	//		     1
	//		2	    2
	//	3	  3  null null
	//4  4

	int curHeight(0);
	return GetHeight(0, curHeight, root);
}

bool LeetCode_110::GetHeight(int prevHeight, int& currHeight, TreeNode* curNode)
{
	if (curNode == nullptr)
	{
		currHeight = prevHeight;
		return true;
	}

	int lHeight(0), rHeight(0);
	if (!GetHeight(prevHeight + 1, lHeight, curNode->left)) return false;
	if (!GetHeight(prevHeight + 1, rHeight, curNode->right)) return false;

	if (abs(lHeight - rHeight) < 2)
	{
		currHeight = max(lHeight, rHeight);
		return true;
	}
	return false;
}

void LeetCode_110::Drive()
{
	//	   3,
	//	9,	 20,
	//		15, 7 
	//== true

	auto lambda_generate = [&](TreeNode* curNode, std::optional<int> left, std::optional<int> right)->void
	{
		if (!curNode) return;

		if(left)
			curNode->left = new TreeNode(left.value());
		if(right)
			curNode->right = new TreeNode(right.value());
	};

	{
		TreeNode* root = new TreeNode(3);
		lambda_generate(root, 9, 20);
		lambda_generate(root->right, 15, 7);
		isBalanced(root);

	}

	// 
	//				1,
	//			2,      2,
	//		3,	3,   null,null,
	//    4,  4
	//false

	{
		TreeNode* root = new TreeNode(3);
		lambda_generate(root, 2, 2);
		lambda_generate(root->left, 3, 3);
		lambda_generate(root->left->left, 4, 4);
		isBalanced(root);
	}
}

void LeetCode_530::inOrder(TreeNode* node, std::vector<int>& treeValue)
{
	if (!node) return;

	inOrder(node->left, treeValue);
	treeValue.push_back(node->val);
	inOrder(node->right, treeValue);
}

int LeetCode_530::getMinimumDifference(TreeNode* root)
{
	std::vector<int> treeValue;//sorted
	
	inOrder(root, treeValue);

	if (treeValue.size() == 1)
		return treeValue.front();

	int min(INT_MAX);
	for (int i = 0; i < treeValue.size()-1; ++i)
	{
		min = std::min(treeValue[i + 1] - treeValue[i], min);
	}

	return min;
}

void LeetCode_530::Drive()
{
}

int LeetCode_1394::findLucky(vector<int>& arr)
{
	std::map<int, int> mapFrequency;

	for (const auto& val : arr) mapFrequency[val]++;

	int luckyNumb(-1);
	for (const auto& [key, val] : mapFrequency)
	{
		if (key == val)
			luckyNumb = key;
	}

	return luckyNumb;
}

void LeetCode_1394::Drive()
{
}

void LeetCode_111::GetDepth(TreeNode* node, int prevDepth, int& lastDepth)
{
	if (!node->left && !node->right)
	{
		lastDepth = prevDepth;
		return;
	}

	int leftLastDepth(INT_MAX);
	int rightLastDepth(INT_MAX);
	if (node->left)
	{
		GetDepth(node->left, prevDepth + 1, leftLastDepth);
		lastDepth = std::min(lastDepth, leftLastDepth);
	}

	if (node->right)
	{
		GetDepth(node->right, prevDepth + 1, rightLastDepth);
		lastDepth = std::min(lastDepth, rightLastDepth);
	}
	
	return;
}

int LeetCode_111::minDepth(TreeNode* root)
{
	int minDepth(INT_MAX);
	GetDepth(root, 1, minDepth);
	return minDepth;
}

int LeetCode_111::minDepth_best(TreeNode* root)
{
	if (!root)
		return 0;

	if (!root->left)
		return 1 + minDepth_best(root->right);

	if (!root->right)
		return 1 + minDepth_best(root->left);

	int ans = 1 + std::min(minDepth_best(root->left), minDepth_best(root->right));

	return ans;
}

void LeetCode_111::Drive()
{
}

vector<int> LeetCode_1882::assignTasks(vector<int>& servers, vector<int>& tasks)
{
	std::vector<int> answer(tasks.size());

	//std::pair<weight, srvIdx>
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> freeSrv;

	//std::pair<end time, srvIdx>
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> busySrv;

	//t + tasks[idxTask] --> endTime

	for (int i = 0; i < servers.size(); ++i)
		freeSrv.push({servers[i], i});//weight, idx


	long time(0);
	for (int idxTask = 0; idxTask < tasks.size(); ++idxTask)
	{
		time = max((long)idxTask, time);
		
		//srv가 full로 사용중 일때
		//현재 시간을, 가장 먼저 끝날 task end time으로 맞춤
		//무조건 busy srv 한개 이상은 비어짐
		if (freeSrv.empty() && busySrv.top().first > time)
			time = busySrv.top().first; //end time


		//finish processing
		while (!busySrv.empty() && busySrv.top().first <= time)
		{
			auto&[endTime, srvIdx] = busySrv.top();
			freeSrv.push({servers[srvIdx], srvIdx});
			busySrv.pop();
		}

		auto &[weight, srvIdx] = freeSrv.top();
		busySrv.push({ time + tasks[idxTask], srvIdx }); //{endTiem, srvIdx}
		answer[idxTask] = srvIdx;
		freeSrv.pop();
	}


	return vector<int>(answer);
}

void LeetCode_1882::Drive()
{

	auto lambda_verify = [&](const std::vector<int>& res, const std::vector<int>& expected)->bool
	{
		if (res.size() != expected.size())
			return false;

		for (int i = 0; i < res.size(); ++i)
			if (res[i] != expected[i])
				return false;

		return true;
	};

	std::vector<int> servers, tasks, expected, result;

	servers = { 3, 3, 2 };
	tasks = { 1, 2, 3, 2, 1, 2 };
	expected = { 2, 2, 0, 2, 1, 2 };
	result = assignTasks(servers, tasks);
	assert(lambda_verify(result, expected));

	servers = { 5, 1, 4, 3, 2 };
	tasks = { 2, 1, 2, 4, 5, 2, 1 };
	expected = { 1, 4, 1, 4, 1, 3, 2 };
	result = assignTasks(servers, tasks);
	assert(lambda_verify(result, expected));

	servers = { 1,2,3 };
	tasks = { 5,4,3,1,2 };
	expected = { 0,1,2,0,1 };
	result = assignTasks(servers, tasks);
	assert(lambda_verify(result, expected));
}
