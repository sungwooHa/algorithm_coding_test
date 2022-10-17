#pragma once
#include "ISoultion.h"
/// <summary>
/// https://leetcode.com/problems/check-if-the-sentence-is-pangram/
/// </summary>
/// <returns></returns>
/// pangram�� ������. ��� ���ĺ��� ��� �ѹ��� ������.
/// pangram�� ��� return true �ƴϸ� return false;

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
    // ISolution��(��) ���� ��ӵ�
    virtual void Drive() override
    {
    }
};

