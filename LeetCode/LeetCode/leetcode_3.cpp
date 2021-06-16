#pragma once
#include "ISoultion.h"

/// <summary>
/// https://leetcode.com/problems/longest-substring-without-repeating-characters/
/// </summary>
/// <param name="nums"> 입력되는 숫자 배열 </param>
/// <param name="target">2개를 더해서 만들고 싶은 숫자 </param>
/// <returns>target을 만들 수 있는 두 수 </returns>
/// 
class LeetCode_3 : public ISolution {
public:
	int lengthOfLongestSubstring(string s)
	{
        //반복 문자 없는 가장 긴 문자열 찾기.

        //pwwkew push.
        //[0] p -> pw   -> "pw"X
        //[1]     w     -> "w" X  ->  
        //[2]           -> w      ->  wk     ->wke   ->"wke" X
        //[3]                     ->  k      ->ke    -> kew
        //[4]                                ->e     ->  ew
        //[5]                                       ->   w

        if (s.empty())
            return 0;   //값이 없을땐 return 0

        unordered_map<int, int> lastIdx; //map을 통해 반복되는가 아닌가 찾음.
        int startIdx = 0;
        unsigned int result(0);

        //전체를 순회
        //한번 돌면서, 각 구간의 반복 되지 않는 word 체크함
        //start idx를 계속 고쳐주고
        //현재 idx - start idx(반복되지않는) +1 이랑 이전에 구한result랑 비교

        //pww kew
        for (unsigned int i = 0; i < s.size(); i++)
        {
            if (lastIdx.find(s[i]) == lastIdx.end())
                lastIdx[s[i]] = -1;  //없을경우 -1 넣음, start idx   // map {p, -1}---> map {p, 0} {w, -1}
            //map {p, 0} {w, 1}
            startIdx = max(startIdx, lastIdx[s[i]] + 1); //반복될 경우, start를 바꾼다.  //startIdx == 0 // startIdx = 0 // startIdx = 2

            result = max(result, i - startIdx + 1); //max(reuslt, 0 - 0 + 1) --> 1 --> max(1, 1 - 0 + 1) -->2  // (2, 2 - 2 + 1) --> 2

            lastIdx[s[i]] = i; //map {p, 0} {w, 1}
        }

        return result;
	}

	// ISolution을(를) 통해 상속됨
	virtual void Drive() override
	{
	}
};
