#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    stack<int> s;
    
    int timer = 1;
    for(int i =0; i< prices.size(); i++)
    {        
        while(!s.empty() && s.top() > prices[i])
        {
            answer[i] = timer++;
            s.pop();
        }
        timer = 1;
        s.push(i);
    }   
    
    timer = 0;
    while(!s.empty())
    {
        answer[s.top()] = timer++;
        s.pop();
    }
    
    return answer;
}