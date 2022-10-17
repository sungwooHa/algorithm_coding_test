#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/check-if-the-sentence-is-pangram/
/// </summary>
/// <returns></returns>
/// pangram은 문장임. 모든 알파벳이 적어도 한번은 나오는.
/// pangram일 경우 return true 아니면 return false;

constexpr int ALPHABET_SIZE = 'z' - 'a' + 1;
class LeetCode_1832 : public ISolution {
public:
    bool checkIfPangram(string sentence) {
        std::unordered_set<char> hash;
        hash.reserve(26);

        for (const auto& ch : sentence)
            hash.insert(ch);
     
        return hash.size() == ('z' - 'a' + 1);
    }

    bool checkIfPangram_ex(string sentence)
    {
        std::vector<bool> alphabet(26, false);

        for (const auto& ch : sentence)
        {
            alphabet[ch - 'a'] = true;
        }
        
        return std::find(alphabet.begin(), alphabet.end(), false) == alphabet.end();
    }
    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
    }
};

