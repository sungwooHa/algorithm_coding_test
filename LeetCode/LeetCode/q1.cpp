#pragma once
#include "ISoultion.h"

/// <summary>
/// </summary>
/// 
/// 
class q1 : public ISolution {
public:
    int solution(vector<int>& A)
    {
        std::sort(A.begin(), A.end());
        int maxDist(0);
        for (unsigned int i = 0; i < A.size() - 1; ++i)
        {
            maxDist = std::max(maxDist, A[i + 1] - A[i]);
            if (maxDist > (A[A.size() - 1] - A[i]))
                break;
        }

        return maxDist > 0 ? (maxDist >> 1) : 0;
    }

    int bst(vector<int> A)
    {
        std::sort(A.begin(), A.end());



    }
    // ISolution을(를) 통해 상속됨
    virtual void Drive() override
    {
        vector<int> A;
        int res(0);

        A = { 10, 0, 8, 2, -1, 12, 11, 3 };
        res = solution(A);

        A = { 0, 5 };
        res = solution(A); // 2

        A = { 0, 4 };
        res = solution(A); //2

        A = { 0, 3 };
        res = solution(A); //1
        
        A = { 0, 2 };
        res = solution(A); //1

        A = { 0, 1 };
        res = solution(A); //0
    }
};
