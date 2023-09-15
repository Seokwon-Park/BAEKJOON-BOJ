#include <bits/stdc++.h>

using namespace std;

bool visited[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i<n; i++)
    {
        if(visited[i]) continue;          
        answer++;
        queue<int> Q;
        visited[i] = true;
        Q.push (i);
        while(!Q.empty())
        {
            int cur_pos = Q.front();
            Q.pop();
            for(int i =0; i< n; i++)
            {
                if(visited[i] || computers[cur_pos][i] == 0) continue;
                Q.push(i);
                visited[i] = 1;;
            }
        }
    }    
     
    return answer;
}
