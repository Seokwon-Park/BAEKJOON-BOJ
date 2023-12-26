#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int d[55][55];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i = 1; i<= N; i++)
    {
        fill(d[i], d[i]+N+5, INF);
        d[i][i] = 0;
    }
    
    for(auto r: road)
    {
        int u = r[0];
        int v = r[1];
        int dist = r[2];
        
        d[u][v] = min(d[u][v], dist);
        d[v][u] = min(d[v][u], dist);
    }
    
    for(int i = 1; i<= N; i++)
    {
        for(int s= 1; s<= N; s++)
        {
            if(i == s) continue;
            for(int t = 1; t<= N; t++)
            {
                if(i == s) continue;
                d[s][t] = min(d[s][i]+d[i][t], d[s][t]);
                d[t][s] = d[s][t];
            }
        }
    }
    /*
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j<=N; j++)
        {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }*/
    
    for(int i = 1; i<=N; i++)
    {
        if(d[1][i] <= K)
            answer++;
    }
    
    


    return answer;
}