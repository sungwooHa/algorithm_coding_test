#pragma once
#include "ISoultion.h"

#include <vector>

class stack_truck_lv2 : public ISolution
{
public:
    int solution(int bridge_length, int weight, vector<int> truck_weights)
    {
        int answer = 0;
        std::queue<std::pair<int, int>> qu;
        int idxNextTruck(0);
        int sumWeight(0);
        
        while (true)
        {
            answer++;

            if (idxNextTruck < truck_weights.size())
            {
                if (weight >= sumWeight + truck_weights[idxNextTruck])
                {
                    sumWeight += truck_weights[idxNextTruck];
                    qu.push({ truck_weights[idxNextTruck++], bridge_length });
                }
            }
            else
            {
				if (!qu.empty())
					answer += (bridge_length - 1);

				break;
            }

            //queue 의 size만큼 반복.
            const auto numbTruckOnBridge = qu.size();
            for (int i = 0; i < numbTruckOnBridge; ++i)
            {
                auto [truckWeight, length] = qu.front();
                qu.pop();
                length--;
                if (length > 0)
                {
                    qu.push({ truckWeight, length });
                }
                else
                {
                    sumWeight -= truckWeight;
                }
			}
		}

        return answer;
    }

    virtual void Drive() override
    {
        int bridge_length(0);
        int weight(0);
        std::vector<int> truck_weights;
        

        bridge_length = 2;
        weight = 10;
        truck_weights = {7,4,5,6};
        assert(solution(bridge_length, weight, truck_weights) == 8);

        bridge_length = 100;
        weight = 100;
        truck_weights = { 10 };
        assert(solution(bridge_length, weight, truck_weights) == 101);
    }
};
