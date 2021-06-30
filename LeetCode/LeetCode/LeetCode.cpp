#include "LeetCode.h"
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

string LeetCode_1881::maxValue(string n, int x)
{
	//input n : digit, very large integer, (-) or (+)
	//int x : [1,9]
	//n의 어느 위치든, x를 넣어서 가장 큰 수 만들기

	//if n == {1,2,3,4,5} //size 5
	//x가 들어갈 수 있는 위치 : 6곳

	auto length = n.size() - 1;
	auto answerPlace = length + 1;

	//char - '0' -> number

	if (n[0] == '-')
	{
		//negative.
		//뒤에서 부터
		//x보다 큰 수가 있을 경우, 그자리에 x 넣으면 값이 작아짐.
		//자릿수가 커질수록 더 작아짐.
		for (int i = length; i > 0; --i)
		{
			auto digit = n[i] - '0';
			if (digit > x)
				answerPlace = i;
		}
	} 
	else
	{
		//positive
		//뒤에서부터
		//x보다 작은 수가 있을 경우 그 자리에 x넣으면 값이 커짐
		//자릿수가 커질수록 더 커짐
		for (int i = length; i >= 0; --i)
		{
			auto digit = n[i] - '0';
			if (digit < x)
				answerPlace = i;
		}
	}

	n.insert(n.begin() + answerPlace, x + '0');
	return n;
}

void LeetCode_1881::Drive()
{

	string n;
	int x;

	n = "99";
	x = 9;
	auto val1 = maxValue(n, x);
	//999

	n = "-13";
	x = 2;
	auto val2 = maxValue(n, x);
	//-123


	n = "28824579515";
	x = 8;
	auto val3 = maxValue(n, x);
	//828824579515
}

vector<int> LeetCode_1878::getBiggestThree(vector<vector<int>>& grid)
{
	//마름모 규칙
	//마름모 중심 (cx,cy)(idx) 이 분명하게 있음

	//width, height
	//right: cx + size, cy + 0 // cx(idx) - size >= 0
	//left : cx - size, cy + 0 // cx(idx) + size < width
	//top : cx + 0, cy + size  // cy(idx) - size >= 0
 	//bot : cx + 0, cy - size  // cy(idx) + size < height

	//마름모지만, 정사각형 only. 

	auto lambda_GetMaximum = [&](const int width, const int height, const int& col, const int& row) -> std::vector<int>
	{
		int size = 0; //원점에서 끝점까지의 거리

		std::vector<int> svMaximum;
		while (true)
		{
			//verify check
			////left
			if (row - size < 0)
				break;

			//right
			if (row + size >= width)
				break;

			//top
			if (col - size < 0)
				break;

			//bottom
			if (col + size >= height)
				break;

			int sum(0);
			if (size == 0)
				sum = grid[col][row];
			else
			{
				
				auto leftMax = row - size;
				auto rightMax = row + size;
				auto topMax = col - size;
				auto botMax = col + size;
				
				int curCol(0);
				int curRow(0);

				//left to top
				curCol = col;
				curRow = leftMax;
				while(curCol > topMax)
					sum += grid[curCol--][curRow++];

				//top to right
				curCol = topMax;
				curRow = row;
				while (curCol < col)
					sum += grid[curCol++][curRow++];

				//right to bottom
				curCol = col;
				curRow = rightMax;
				while (curRow > row)
					sum += grid[curCol++][curRow--];


				//bottom to left
				curCol = botMax;
				curRow = row;
				while (curCol > col)
					sum += grid[curCol--][curRow--];
				//마지막꺼는 중복이니 제외
			}

			svMaximum.push_back(sum);
			size++;
		}
		return svMaximum;

	};

	std::vector<int> answer;

	const int& height = grid.size();
	const int& width = grid.front().size();
	for (int col = 0; col < height; col++)
	{
		for (int row = 0; row < width; row++)
		{
			auto partialRes = lambda_GetMaximum(width, height, col, row);
			answer.insert(answer.end(), partialRes.begin(), partialRes.end());
		}
	}
	
	std::sort(answer.begin(), answer.end(), std::greater<int>());
	answer.erase(std::unique(answer.begin(), answer.end()), answer.end());

	if (answer.size() > 3)
	{
		std::vector<int> res(3);
		for (int i = 0; i < 3; i++)
			res[i] = answer[i];
		return res;
	}
	else
		return answer;
}

void LeetCode_1878::Drive()
{
	std::vector<vector<int>> grid;
	std::vector<int> answer;
// 	grid = { 
// 	{ 3 , 4 , 5  , 1 , 3 }, 
// 	{ 3 , 3 , 4  , 2 , 3 }, 
// 	{ 20, 30, 200, 40, 10 }, 
// 	{ 1 , 5 , 5  , 4 , 1 }, 
// 	{ 4 , 3 , 2  , 2 , 5 } };
// 
// 	answer = getBiggestThree(grid);
// 	//228,216,211
// 
// 
// 	grid = { 
// 	{ 20, 17, 9 , 13, 5 , 2 , 9 , 1 , 5 }, 
// 	{ 14, 9 , 9 , 9 , 16, 18, 3 , 4 , 12 }, 
// 	{ 18, 15, 10, 20, 19, 20, 15, 12, 11 }, 
// 	{ 19, 16, 19, 18, 8 , 13, 15, 14, 11 }, 
// 	{ 4 , 19, 5 , 2 , 19, 17, 7 , 2 , 2 } };
// 
// 	answer = getBiggestThree(grid);
// 	//

	grid = {
	{ 20, 17, 9 , 13, 5 , 2 , 9 , 1 , 5 },
	{ 14, 9 , 9 , 9 , 16, 18, 3 , 4 , 12 },
	{ 18, 15, 10, 20, 19, 20, 15, 12, 11 },
	{ 19, 16, 19, 18, 8 , 13, 15, 14, 11 },
	{ 4 , 19, 5 , 2 , 19, 17, 7 , 2 , 2 } };


	answer = getBiggestThree(grid);
	//107 103 102
}

bool LeetCode_1886::findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
{
	//dest[i][j] = src[size - j - 1][i] //90
	//src[i][j] == dset1[j][size-i-1] == dest2[size-i-1][size-j-1] == dest3[size-j-1][size-(size-i-1)-1];
	//src[i][j] == dset1[j][size-i-1] == dest2[size-i-1][size-j-1] == dest3[size-j-1][i];
	int n = mat.size();

	bool rotate90 = [&]()->bool
	{
		for (int i = 0; i < target.size(); ++i)
		{
			for (int j = 0; j < target[i].size(); ++j)
			{
				if (mat[i][j] != target[j][n-i-1])
					return false;
			}
		}
		return true;
	}();

	bool rotate180 = [&]()->bool
	{
		for (int i = 0; i < target.size(); ++i)
		{
			for (int j = 0; j < target[i].size(); ++j)
			{
				if (mat[i][j] != target[n - i - 1][n - j - 1])
					return false;
			}
		}
		return true;
	}();

	bool rotate270 = [&]()->bool
	{
		for (int i = 0; i < target.size(); ++i)
		{
			for (int j = 0; j < target[i].size(); ++j)
			{
				if (mat[i][j] != target[n - j - 1][i])
					return false;
			}
		}
		return true;
	}();

	bool rotate360 = [&]()->bool
	{
		for (int i = 0; i < target.size(); ++i)
		{
			for (int j = 0; j < target[i].size(); ++j)
			{
				if (mat[i][j] != target[i][j])
					return false;
			}
		}
		return true;
	}();

	return rotate90 || rotate180 || rotate270 || rotate360;
}

void LeetCode_1886::Drive()
{
	//00 01 02      
	//10 11 12
	//20 21 22

	//size = 3
	//00 -> 02 -> 22 -> 20
	//01 -> 12 -> 21 -> 20
	


	//[[0, 0, 0], 
	// [0, 1, 0], 
	// [1, 1, 1]]
	// 
	//[[1, 1, 1], 
	// [0, 1, 0], 
	// [0, 0, 0]]
	//true

	//[[0, 0, 0], 
	// [0, 0, 1], 
	// [0, 0, 1]]
	// 
	//[[0, 0, 0], 
	// [0, 0, 1], 
	// [0, 0, 1]]
	//true
}

int LeetCode_1887::reductionOperations(vector<int>& nums)
{
	//find largest elements //if there are multiple? pick the smallest i
	//find next largest elements.smaller than largest, 
	//reduce largestNums to nextLarget

	std::sort(nums.begin(), nums.end());

	int max = nums.back();
	int min = nums.front();
	if (max == min)
		return 0;
	
	std::map<int, int> mapNums;
	for (const auto& num : nums)
		mapNums[num] ++;

	int opCnt(0);
	int i = 0;
	for (const auto& [val, cnt] : mapNums)
	{
		opCnt += cnt*i;
		i++;
	}

	return opCnt;
}

void LeetCode_1887::Drive()
{
	std::vector<int> nums;

	nums = { 5, 1, 3 };


	assert(reductionOperations(nums) == 3);


	nums = { 1,1,2,2,3};
	assert(reductionOperations(nums) == 4);
	//
	//1,1,2,2,3
	//
	//1,1,2,3,3
	//1,1,3,3,3
	// 
	//1,1,1,3,3
	//1,1,1,1,3
	//1,1,1,1,1
	//
	//




	//[7,9,10,8,6,4,1,5,2,3]
	//1,2,3,4,5,6,7,8,9,10
	//10 : 1
	// 9 : 2
	// 8 : 3
	// 7 : 4
	// 6 : 5
	// 5 : 6
	// 4 : 7
	// 3 : 8
	// 2 : 9

	nums = { 7, 9, 10, 8, 6, 4, 1, 5, 2, 3 };
	//7, 9, 10, 8, 6, 4, 1, 5, 2, 3 
	//7, 9, 9, 8, 6, 4, 1, 5, 2, 3 
	// 
	//7, 8, 9, 8, 6, 4, 1, 5, 2, 3 
	//7, 8, 8, 8, 6, 4, 1, 5, 2, 3 
	// 
	//7, 7, 8, 8, 6, 4, 1, 5, 2, 3 
	//7, 7, 7, 8, 6, 4, 1, 5, 2, 3 
	//7, 7, 7, 7, 6, 4, 1, 5, 2, 3 
	//
	//6, 7, 7, 7, 6, 4, 1, 5, 2, 3 
	//6, 6, 7, 7, 6, 4, 1, 5, 2, 3 
	//6, 6, 6, 7, 6, 4, 1, 5, 2, 3 
	//6, 6, 6, 6, 6, 4, 1, 5, 2, 3 
	// 
	//5, 6, 6, 6, 6, 4, 1, 5, 2, 3 
	//5, 5, 6, 6, 6, 4, 1, 5, 2, 3 
	//5, 5, 5, 6, 6, 4, 1, 5, 2, 3 
	//5, 5, 5, 5, 6, 4, 1, 5, 2, 3 
	//5, 5, 5, 5, 5, 4, 1, 5, 2, 3 
	//


	//expect : 45

	assert(reductionOperations(nums) == 45);

	
}

bool LeetCode_112::dfs(TreeNode* node, int curSum, const int& targetSum)
{
	if (!node)
		return false;

	if (!node->left && !node->right)
	{
		if (node->val + curSum == targetSum)
			return true;
		else
			return false;
	}

	bool isFind(false);

	if (node->left)
		isFind = dfs(node->left, curSum + node->val, targetSum);

	if (node->right && !isFind)
		isFind = dfs(node->right, curSum + node->val, targetSum);


	return isFind;
}

bool LeetCode_112::hasPathSum(TreeNode* root, int targetSum)
{
	return dfs(root, 0, targetSum);
}

void LeetCode_112::Drive()
{
	//			1
	//		-2,		-3
	//	  1,  3   -2,	null
	//-1

	auto lambda_generate = [&](TreeNode* curNode, std::optional<int> left, std::optional<int> right)->void
	{
		if (!curNode) return;

		if (left)
			curNode->left = new TreeNode(left.value());
		if (right)
			curNode->right = new TreeNode(right.value());
	};

	
		TreeNode* root = new TreeNode(1);
		lambda_generate(root, -2, -3);
		lambda_generate(root->left, 1, 3);
		lambda_generate(root->right, -2, {});
		lambda_generate(root->left->left, -1, {});
		auto val = hasPathSum(root, -1);
	

}

vector<vector<int>> LeetCode_118::generate(int numRows)
{
	std::vector<std::vector<int>> answer(numRows);
	for (int i = 0; i < numRows; ++i)
	{
		answer[i].resize(i + 1);
		for (int j = 0; j <= i; ++j)
		{
			if (j == 0 || j == i)
				answer[i][j] = 1;
			else
				answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j];
		}
	}
	return vector<vector<int>>(answer);
}

void LeetCode_118::Drive()
{
	auto val = generate(5);

	assert(val.size() == 5);

}

vector<int> LeetCode_119::getRow(int rowIndex)
{
	std::vector<int> pre;
	std::vector<int> answer;
	for (int i = 0; i < rowIndex+1; ++i)
	{
		answer.resize(i + 1, 1);
		for (int j = 1; j < i; ++j)
		{
			answer[j] = pre[j - 1] + pre[j];
		}

		pre = answer;
	}

	return answer;
}

void LeetCode_119::Drive()
{
	//1		  1				//
	//2	     1 1			//
	//3     1 2 1			//d-1
	//4	   1 3 3 1			//d-1 d-1 
	//5	  1 4 6 4 1			//d-1, 2*(d-2), d-1 
	//6  1 5 10 10 5 1		//d-1  2*(d-2), 2*(d-2) , d-1
	//7 1 6 15 20 15 6 1    //d-1  2*(d-2)
	// 
	//
}

int LeetCode_121::maxProfit(vector<int>& prices)
{
	if (prices.size() < 1)
		return 0;

	int minPrice = INT_MAX;
	int maxPrice = 0;
	for (int i = 0; i < prices.size(); ++i)
	{
		if (prices[i] < minPrice)
			minPrice = prices[i];
		else if(prices[i] - minPrice > maxPrice)
		{
			maxPrice = prices[i] - minPrice;
		}
	}

	return maxPrice;
}

void LeetCode_121::Drive()
{
	std::vector<int> prices;

	prices = { 7, 1, 5, 3, 6, 4 };
	assert(maxProfit(prices) == 5);
}

int LeetCode_122::maxProfit(vector<int>& prices)
{
	//greedy?
	//팔고, 사고
	//get Sub profit.

	int profit(0);
	for (int i = 1; i < prices.size(); ++i)
	{
		auto val = prices[i] - prices[i - 1];
		if (val > 0)
			profit += val;
	}

	return profit;
}

void LeetCode_122::Drive()
{
}

vector<string> LeetCode_1408::stringMatching(vector<string>& words)
{
	std::sort(words.begin(), words.end(), [&](const string& str1, const string& str2) -> bool
		{
			return str1.size() < str2.size();
		});

	std::vector<string> answer;
	//words를 길이 순으로 정렬
	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = i + 1; j < words.size(); ++j)
		{
			if (words[j].find(words[i]) != string::npos)
			{
				answer.push_back(words[i]);
				break;
			}
		}
	}

	return answer;
	
	return vector<string>();
}

void LeetCode_1408::Drive()
{
	std::vector<string> words;
	std::vector<string> answer;

	//as, hero
	words = { "mass", "as", "hero", "superhero" };
	answer = stringMatching(words);


	//et, code
	words = { "leetcode", "et", "code" };
	answer = stringMatching(words);

	//NULL
	words = { "blue", "green", "bu" };
	answer = stringMatching(words);

	//"leetcode","od","am"
	words = { "leetcoder", "leetcode", "od", "hamlet", "am" };
	answer = stringMatching(words);
}

int LeetCode_1888::minFlips(string s)
{
	//if? 100
	//op1 : 100, 001, 010
	//100 + 100 ---> 100100

	const int ORIGINAL_SIZE = s.size();
	s += s;
	const int EXTEND_SIZE = s.size();
	string ref1; //10101010101...
	string ref2; //01010101010...
	ref1.reserve(EXTEND_SIZE);
	ref2.reserve(EXTEND_SIZE);
	for (int i = 0; i < EXTEND_SIZE; ++i)
	{
		ref1 += (i % 2 == 0 ? "1" : "0");
		ref2 += (i % 2 == 0 ? "0" : "1");
	}

	int answer(INT_MAX);
	int flip1(0);
	int flip2(0);
	for (int idx = 0; idx < EXTEND_SIZE; ++idx)
	{
		if (s[idx] != ref1[idx])
			flip1++;

		if (s[idx] != ref2[idx])
			flip2++;

		if (idx == ORIGINAL_SIZE - 1)
		{
			answer = min(flip1, answer);
			answer = min(flip2, answer);
		}
		else if (idx >= ORIGINAL_SIZE)
		{
			if (s[idx - ORIGINAL_SIZE] != ref1[idx- ORIGINAL_SIZE])
				flip1--;

			if (s[idx - ORIGINAL_SIZE] != ref2[idx- ORIGINAL_SIZE])
				flip2--;

			answer = min(flip1, answer);
			answer = min(flip2, answer);
		}
		else continue;
	}

	return answer;
}

void LeetCode_1888::Drive()
{

	string s;

// 	s = "111000";
// 	assert(minFlips(s) == 2);	
// 	
// 	s = "010";
// 	assert(minFlips(s) == 0);

	s = "01001001101";
	assert(minFlips(s) == 2);
}

bool LeetCode_125::isPalindrome(string s)
{
	//isanum : 숫자,영문 판단
	//tolower : 소문자로 전환.

	int start = 0, end = s.length() - 1;

	while (start < end)
	{
		if (!isalnum(s[start]))
			start++;
		else if (!isalnum(s[end]))
			end++;
		else
		{
			if (tolower(s[start++]) != tolower(s[end--]))
				return false;
		}
	}
	return true;

}

void LeetCode_125::Drive()
{
	string s;
	
	s = "A man, a plan, a canal: Panama";
	assert(isPalindrome(s) == true);

	s = "race a car";
	assert(isPalindrome(s) == false);

	s = "0P";
	assert(isPalindrome(s) == false);
}

int Leetcode_136::singleNumber(vector<int>& nums)
{
	std::unordered_map<int, int> hashMap;

	for (const auto& num : nums)
		hashMap[num]++;

	for (const auto& [key, val] : hashMap)
	{
		if (val == 1)
			return key;
	}

	assert(false);
	return 0;
}

int Leetcode_136::singleNumber_good(vector<int>& nums)
{
	int answer(0);
	for (const auto& num : nums)
	{
		answer ^= num;
	}
	return answer;
}

void Leetcode_136::Drive()
{
}
