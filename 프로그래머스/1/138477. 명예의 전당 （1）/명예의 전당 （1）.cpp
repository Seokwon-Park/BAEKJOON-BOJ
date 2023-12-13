#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto s: score)
    {
        if(pq.size() < k)
        {
            pq.push(s);
            answer.push_back(pq.top());
        }
        else
        {
            pq.push(s);
            pq.pop();
            answer.push_back(pq.top());
        }
    }
    
    
    return answer;
}