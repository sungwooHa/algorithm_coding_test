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


public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
	virtual void Drive() override;

	
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

class LeetCode_105 : public ISolution
{
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
	virtual void Drive() override;

private:
};

class LeetCode_1375 : public ISolution
{
public:
	int numTimesAllBlue(vector<int>& light);
	virtual void Drive() override;

private:
};

class LeetCode_822 : public ISolution
{
public:
	int flipgame(vector<int>& fronts, vector<int>& backs);
	virtual void Drive() override;
};

class LeetCode_693 : public ISolution
{
public:
	bool hasAlternatingBits(int n);
	virtual void Drive() override;
};

class LeetCode_66 : public ISolution
{
public:
	vector<int> plusOne(vector<int>& digits);
	virtual void Drive() override;

private:
};
class LeetCode_67 : public ISolution
{
public:
	string addBinary(string a, string b);
	virtual void Drive() override;

private:
};

class LeetCode_1073 : public ISolution
{
public:
	vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2);
	virtual void Drive() override;

private:
};

class LeetCode_150 : public ISolution
{
public:
	int evalRPN(vector<string>& tokens);
	int evalRPN_other(vector<string>& tokens);
	virtual void Drive() override;

private:
};

class LeetCode_69 : public ISolution
{
public:
	int mySqrt(int x);
	virtual void Drive() override;

private:
};

class LeetCode_70 : public ISolution
{
public:
	int climbStairs(int n);
	virtual void Drive() override;

private:
};

class LeetCode_83 : public ISolution
{
public:
	ListNode* deleteDuplicates(ListNode* head);
	virtual void Drive() override;

private:
};

class LeetCode_94 : public ISolution
{
public:
	void search(TreeNode* curNode, std::vector<int>& answer);
	vector<int> inorderTraversal(TreeNode* root);
	virtual void Drive() override;

private:
};

class LeetCode_100 : public ISolution
{
public:
	bool isSameTree(TreeNode* p, TreeNode* q);
	virtual void Drive() override;

private:
};

class LeetCode_101 : public ISolution
{
public:
	void PreorderSearch(TreeNode* curNode, std::vector<int>& answer);
	void rPreorderSearch(TreeNode* curNode, std::vector<int>& answer);
	bool isSymmetric(TreeNode* root);
	virtual void Drive() override;

private:
};


class LeetCode_104 : public ISolution
{
public:
	int find(TreeNode* node, int depth);
	int maxDepth(TreeNode* root);
	virtual void Drive() override;

private:
};


class LeetCode_1334 : public ISolution
{
public:
	int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold);
	virtual void Drive() override;

private:
};

class LeetCode_95 : public ISolution
{
public:

	vector<TreeNode*> GeneratePartialTree(int start, int end);
	vector<TreeNode*> generateTrees(int n);
	virtual void Drive() override;

private:
};

class LeetCode_108 : public ISolution
{
public:
	TreeNode* sortedArrayToBST(vector<int>& nums);
	TreeNode* GeneratedTree(int idxMin, int idxMax, const std::vector<int> nums);
	virtual void Drive() override;

private:
};
class LeetCode_110 : public ISolution
{
public:
	bool isBalanced(TreeNode* root);
	bool GetHeight(int prevHeight, int& currHeight, TreeNode* curNode);
	virtual void Drive() override;

private:
};

class LeetCode_530 : public ISolution
{
public:
	void inOrder(TreeNode* node, std::vector<int>& treeValue);
	int getMinimumDifference(TreeNode* root);
	virtual void Drive() override;

private:
};


class LeetCode_1394 : public ISolution
{
public:
	int findLucky(vector<int>& arr);
	virtual void Drive() override;

private:
};

class LeetCode_111 : public ISolution
{
public:
	void GetDepth(TreeNode* node, int prevDepth, int& lastDepth);
	int minDepth(TreeNode* root);

	int minDepth_best(TreeNode* root);
	virtual void Drive() override;

private:
};