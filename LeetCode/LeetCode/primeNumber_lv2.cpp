#pragma once

#include "ISoultion.h"

#include <vector>
#include <string>
class primeNumber_lv2 : public ISolution
{
public:
    int solution(string numbers) 
    {
        auto lambda_findAllNumbCombi = [](const string& numbers)
        {
            std::vector<char> numbList;
            for (const auto& ch : numbers)
            {
                numbList.emplace_back(ch);
            }
            std::sort(numbList.begin(), numbList.end());


            std::vector<int> combiList;
            do 
            {
                string tmp = "";
                for (int i = 0; i < numbList.size(); ++i)
                {
                    tmp += numbList[i];
                    combiList.emplace_back(stoi(tmp));
                }
            } while (next_permutation(numbList.begin(), numbList.end()));

            //중복삭제
            std::sort(combiList.begin(), combiList.end());
            combiList.erase(std::unique(combiList.begin(), combiList.end()), combiList.end());


            return combiList;
        };

        auto lambda_IsPrime = [](const int& number)
        {
            if (number < 2) return false;

            //에라토스테네스의 채
            for (int i = 2; i <= sqrt(number); ++i)
            {
                if (number % i == 0) return false;
            }
            return true;
        };

        auto combiList = lambda_findAllNumbCombi(numbers);

        int answer = 0;
        for (const auto& number : combiList)
        {
            if (lambda_IsPrime(number))
                answer++;
        }

        return answer;
    }

    virtual void Drive() override
    {
        string numbers;

        numbers = "17";
        solution(numbers);


        numbers = "011";
        solution(numbers);
    }
};
