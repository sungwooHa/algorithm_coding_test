#pragma once
#include "ISoultion.h"

#include <sstream>

class q2 : public ISolution {
public:
    int solution(string& S, string& T) 
    {
        // write your code in C++14 (g++ 6.2.0)
        //time stamp;
        
        auto lambda_split = [](string input) -> std::vector<int>
        {
            vector<int> answer;
            stringstream ss(input);
            string tmp;
            while (getline(ss, tmp, ':'))
            {
                answer.push_back(std::stoi(tmp));
            }

            return answer;
        };

        auto time_tic = [](std::vector<int>& time)
        {
            time[2] += 1;
            if ((time[2] % 60) == 0)
            {
                time[2] = 0;
                time[1] += 1;

                if ((time[1] & 60) == 0)
                {
                    time[1] = 0;
                    time[0] += 1;

                    if (time[0] % 24 == 0)
                        time[0] = 0;
                }
            }

            return time;
        };

        auto same_time = [](const std::vector<int>& s, const std::vector<int>& t)
        {
            for (auto i = 0; i < 3; ++i)
            {
                if (s[i] != t[i])
                    return false;
            }
            return true;
        };

        auto IsInteresting = [](const std::vector<int>& time)
        {
            std::unordered_set<int> ss;

            for (auto intTime : time)
            {
                auto strTime = std::to_string(intTime);
                if (strTime.size() == 1)
                    strTime = "0" + strTime;

                for (const auto& ch : strTime)
                {
                    ss.insert(ch);
                }
            }

            if (ss.size() < 3)
                return true;

            return false;
        };


        auto time_s = lambda_split(S);
        auto time_t = lambda_split(T);

        int countInterest(0);
        while (same_time(time_s, time_t) == false)
        {
            if (IsInteresting(time_s))
                countInterest++;
            time_tic(time_s);
        }

        if (IsInteresting(time_s))
            countInterest++;
        return countInterest;
    }

    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
        string s, t;
        int cnt(0);
        s = "15:15:00";
        t = "15:15:12";
        cnt = solution(s, t);

        s = "22:22:21";
        t = "22:22:23";
        cnt = solution(s,t);

        s = "22:22:59";
        t = "22:23:23"; 
        cnt = solution(s, t); //2개!??
    }
};
