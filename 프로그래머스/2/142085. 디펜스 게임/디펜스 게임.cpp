#include <bits/stdc++.h>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;

    priority_queue<int> pq;
    for(int e: enemy)
    {
        if(n >= e)
        {
            pq.push(e);
            n -= e;
        }
        else
        {
            if(k > 0)
            {
                if(!pq.empty())
                {
                    if(e < pq.top())
                    {
                        n+= pq.top();
                        pq.pop();
                        n-= e;
                        pq.push(e);
                        k--;
                        answer++;
                    }
                    else
                    {
                        k--;
                        answer++;
                    }
                }
                else
                {
                    k--;
                    answer++;
                }
            }
            else
                break;
            
        }
    }
    
    return answer + pq.size();
}