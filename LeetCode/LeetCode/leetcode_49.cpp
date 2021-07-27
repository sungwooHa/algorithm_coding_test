#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/group-anagrams/
/// </summary>
class LeetCode_49 : public ISolution
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{
		//정렬된 string, 그리고 각 index
		std::map<string, std::vector<int>> mapAnagram2Cnt;
		for (unsigned int idxStr = 0; idxStr < strs.size(); idxStr++)
		{
			//char 단위로 나눠서, 정렬한 뒤에 정렬된 str을 구한다
			std::vector<char> arrayForChar(strs[idxStr].size());
			for (unsigned int i = 0; i < strs[idxStr].size(); i++)
				arrayForChar[i] = strs[idxStr][i];

			std::sort(arrayForChar.begin(), arrayForChar.end());
			string strAnagram;

			for (const auto& ch : arrayForChar)
				strAnagram += ch;

			//정렬된 str을 key로 가지고 있는 input 배열의 index를 push_back
			mapAnagram2Cnt[strAnagram].push_back(idxStr);
		}

		vector<vector<string>> res;
		res.reserve(mapAnagram2Cnt.size()); //set value of capacity
		//map의 개수는 그룹의 개수
		for (const auto& elem : mapAnagram2Cnt)
		{
			//groupping.
			//find by index
			std::vector<string> resPartial;
			for (const auto& targetIdx : elem.second)
				resPartial.push_back(strs[targetIdx]);
			res.push_back(resPartial);
		}
		return res;
	}

};

