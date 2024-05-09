#include <bits/stdc++.h>

using namespace std;

bool isEnd[505];

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(),jobs.end());
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    int time = jobs[0][0];
    pq.push({jobs[0][1], 0});
    int ended = 0;
    isEnd[0] = true;
    while(ended != jobs.size())
    {
        if(!pq.empty())
        {
        auto [tmp, ix] = pq.top();
        pq.pop();
        //cout << tmp << '\n';
        time+=tmp;
        //cout << time-jobs[ix][0] << '\n';
        answer+= time -jobs[ix][0];
        ended++;
        for(int i = 0; i< jobs.size(); i++)
        {
            if(isEnd[i])continue;
            if(jobs[i][0] <= time)
            {
                pq.push({jobs[i][1], i});
                isEnd[i] = true;
            }
        }
        }
        else
        {
        for(int i = 0; i< jobs.size(); i++)
        {
            if(isEnd[i])continue;
            pq.push({jobs[i][1], i});
            time = jobs[i][0];
            isEnd[i] = true;
            break;
        }
        }
    }
    
    return answer/jobs.size();
}