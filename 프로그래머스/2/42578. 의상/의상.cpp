#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, int> um;
    for(auto cloth: clothes)
    {
        um[cloth[1]]++;
    }
    
    answer = 1;
    for(auto itr = um.begin(); itr != um.end(); itr++)
    {
        answer *= itr->second+1;
    }
    
    answer--;
    
    
    return answer;
}