#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> bridge;
    int b_weight = 0;

    for(int i =0; i< bridge_length; i++)
    {
        bridge.push(0);
    }
    int ix =0;
    int time = 0;
    while(!bridge.empty())
    {
        if(bridge.front() != 0)
        {
            b_weight -= bridge.front();
        }
        if(ix == truck_weights.size())
        {
            time += bridge_length;
            break;
        }
        bridge.pop();
        if(b_weight+truck_weights[ix] <= weight)
        {
            bridge.push(truck_weights[ix]);
            b_weight += truck_weights[ix];
            ix++;
        }
        else
        {
            bridge.push(0);
        }
        time++;
    }
    
    return time;
}