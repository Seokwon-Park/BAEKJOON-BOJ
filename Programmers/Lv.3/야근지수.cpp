#include <bits/stdc++.h>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    
    priority_queue<int> pq;
    long long sum =0;
    for(auto work:works)
    {
        pq.push(work);
        sum += work;
    }
    
    if(sum -n <=0)
    {
       answer =0; 
    }
    else
    {
    for(int i =0; i< n; i++)
    {
        int a = pq.top();
       // cout << a << "->" << a-1<<endl;
        a--;
        pq.pop();
        pq.push(a);
    }
    
    
    int s= pq.size();
    for(int i =0; i < s; i++)
    {
        int a = pq.top();

        //cout << a << "->" << a*a<<endl;
        pq.pop();
        answer += a*a;
    }
    }
    


    
    
    return answer;
}
