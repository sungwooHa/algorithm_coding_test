#pragma once

#include "ISoultion.h"

#include <vector>
#include <string>


class graph_ranking : public ISolution
{
public:
    int solution(int n, vector<vector<int>> results) 
    {
        //모든 노드의 모든 경로를 찾기.
        //각 노드가 모든 노드로 갈수 있는 경로가 있다면, (승패니까 반대도 허용) 랭킹을 알 수 있음
        //알고리즘 : 플로이드 와샬 (floyd warshall)

        int answer = 0;
        //승패가 주어진다.
        //등수가 확실한 선수를 찾아라.
        std::vector<std::vector<bool>> gameResult(n+1, std::vector<bool>(n+1, false));

        constexpr int IDX_WINNER = 0;
        constexpr int IDX_LOSER = 1;

        for (const auto& gameInfo : results)
        {
            gameResult[gameInfo[IDX_WINNER]][gameInfo[IDX_LOSER]] = true;
        }

        //i 거쳐가는 노드
        for (unsigned int i = 1; i <= n; ++i)
        {
            //j = 출발 노드
            for (unsigned int j = 1; j <= n; ++j)
            {
                //k = 도착 노드
                for (unsigned int k = 1; k <= n; ++k)
                {
                    if (gameResult[j][i] && gameResult[i][k])
                    {
                        gameResult[j][k] = true;
                    }
                }
            }
        }

        for (unsigned int i = 1; i <= n; ++i)
        {
            int knowRankingCount(1);
            for (unsigned int j = 1; j <= n; ++j)
            {
                if (gameResult[i][j] || gameResult[j][i])
                    knowRankingCount++;
                    
            }

            if (knowRankingCount == n)
                answer++;
        }

        return answer;
    }
    virtual void Drive() override
    {

        std::vector<std::vector<int>> results;
        int n(0);

        results = { { 4, 3 }, { 4, 2 }, { 3, 2 }, { 1, 2 }, { 2, 5 } };
        n = 5;

        auto val = solution(n, results);
    }
};
