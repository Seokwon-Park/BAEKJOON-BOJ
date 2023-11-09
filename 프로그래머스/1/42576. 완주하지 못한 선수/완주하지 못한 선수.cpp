#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> um;
    
    for(string str:participant)
    {
        um[str]++;
    }
    
    for(string str:completion)
    {
        um[str]--;
    }
    
    for(auto pair:um)
    {
        if(pair.second == 1)
        {
            answer = pair.first;
        }
    }
    
    
    
    return answer;
}