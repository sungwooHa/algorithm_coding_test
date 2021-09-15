#pragma once
#include "ISoultion.h"

class q3 : public ISolution {
public:
    int solution(vector<int>& A)
    {
        if (A.size() < 3)
            return 0;

        //at least 3.
        int numbStable(0);
        std::vector<int> arrStable;

        int idx(0);
        while (idx < A.size() - 2)
        {
            int stable(2);
            int prevGap = A[idx + 1] - A[idx];

            for (int j = idx + 2; j < A.size(); ++j)
            {
                auto curGap = A[j] - A[j - 1];
                if (prevGap == curGap)
                {
                    stable++;
                    idx++;
                }
                else
                {
                    idx = j - 1;
                    break;
                }
            }

            if (stable >= 3)
                arrStable.push_back(stable);

        }

        int res(0);

        for (const auto& stableStep : arrStable)
        {
            for (int i = stableStep - 2; i > 0; i--)
                res += i;
        }

        return res;
    }


    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
        std::vector<int> a;

        a = { -1, 1, 3, 3, 3, 2, 3, 2, 1, 0 };
        solution(a); //5;

        a = { 0, 1, 3, 6, 10 };
        solution(a); // 0;

        a = { 3, 3, 4, 5 };
        solution(a); //1;
    }
};
