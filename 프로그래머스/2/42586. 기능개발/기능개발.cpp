#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> s;
    
    int keep = 0;
    for(int i = 0; i< progresses.size(); i++)
    {
        int left = 100 -progresses[i];
        if(left % speeds[i] != 0) 
        {            
            left /= speeds[i];
            left += 1;
        }
        else
        {
            left /= speeds[i];
        }

        if(s.empty())
        {
            s.push(left);
            keep = 1;
        }
        else
        {
            if(left <= s.top())
            {
                keep++;
            }
            else
            {
                answer.push_back(keep);
                keep = 1;
                s.push(left);
            }
        }        
    }
    if(!s.empty())
        answer.push_back(keep);
    return answer;
}