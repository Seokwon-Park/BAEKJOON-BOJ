#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();

    vector<int> answer;
    
    stack<int> s;
    
    s.push(numbers[n-1]);
    answer.push_back(-1);
    for(int i = n-2; i>=0; i--)
    {
        while(!s.empty())        
        {
            int tp = s.top();
            s.pop();
            if(tp > numbers[i])
            {
                answer.push_back(tp);
                s.push(tp);
                s.push(numbers[i]);
                break;
            }
        }
        if(s.empty())
        {
            answer.push_back(-1);
            s.push(numbers[i]);
        }
    }
    
    reverse(answer.begin(), answer.end());    
    
    return answer;
}