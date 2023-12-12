#include <bits/stdc++.h>

using namespace std;

bool visited[10];
int vcnt;//던전 깬 횟수
int tired;//피로도
int n;
int max_clear = INT_MIN;//젤 많이 깬경우
vector<vector<int>> ds;

void explore(int m)//드가야되는 던전 번호, 지금 던전 몇개째(클여부 관계 x)
{
    if (m == n)
    {
        if (vcnt > max_clear)
            max_clear = vcnt;
        return;
    }
    for (int i = 0; i < ds.size(); i++)
    {
        if (visited[i]) continue;
        visited[i] = true;
        if (ds[i][0] <= tired)
        {
            tired -= ds[i][1];
            vcnt++;
            explore(m + 1);
            vcnt--;
            tired += ds[i][1];
        }
        else
        {
            explore(m + 1);
        }
        visited[i] = false;

    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    n = dungeons.size();
    ds = dungeons;
    tired = k;

    explore(0);
    
    answer = max_clear;

    return answer;
}