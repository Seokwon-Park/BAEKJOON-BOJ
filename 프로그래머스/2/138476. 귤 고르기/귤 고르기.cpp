#include <bits/stdc++.h>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    for(auto tan:tangerine)
    {
        m[tan]++;
    }
    
    vector<pair<int, int>> mvec;
    for(auto i = m.begin(); i != m.end(); i++)
    {
        mvec.push_back({i->first, i->second});
    }
    
    sort(mvec.begin(), mvec.end(), [](pair<int, int> a, pair<int, int> b)
         {
             return a.second > b.second;
         });    
    
    int total =0;
    for(auto m : mvec)
    {
        total += m.second;
        answer++;
        if(total >= k)break;
        
    }
    
    return answer;
}