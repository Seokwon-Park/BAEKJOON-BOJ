#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    vector<pair<int,int>> vec;
    
    for(int i = 0; i< priorities.size(); i++)
    {
        q.push({priorities[i], i});
        vec.push_back({priorities[i], i});
    }
    stable_sort(vec.begin(), vec.end(), [](pair<int,int> a, pair<int,int> b)
             {
                return a.first > b.first;        
             });
    
    int find_value = priorities[location];
    int cursor = 0;
    int count = 0;
    while(!q.empty())
    {
        int max_value = vec[cursor].first;
        auto qfr = q.front();
        if(qfr.first == max_value)
        {
            if(qfr.second == location)
            {
                answer = cursor+1;
            }
            q.pop();
            cursor++;
        }
        else
        {            
            q.pop();
            q.push(qfr);
        }
    }
    
    return answer;
}