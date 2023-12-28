#include<bits/stdc++.h>

using namespace std;

int w, h;
int sx, sy, lx, ly, ex, ey;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
bool visited[105][105];
int dist[105][105];
vector<string> map_copy;

bool BFS(int x, int y, int tarx, int tary)
{
    queue<pair<int,int>> q;
    q.push({x, y});

    for(int i =0; i< h ; i++)
    {
        fill(visited[i], visited[i]+w, false);
    }
    
    visited[y][x] = true;
    
    while(!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        if(nx == tarx && ny == tary) // 타겟을 찾았으면 true
        {
            return true;
            break;
        }
        q.pop();
        for(int i = 0; i< 4 ; i++)
        {
            int tx = nx + dx[i];
            int ty = ny + dy[i];
            if(tx < 0 || ty < 0 || tx>= w || ty >= h) continue;
            if(visited[ty][tx] || map_copy[ty][tx] == 'X') continue;
            q.push({tx, ty});
            visited[ty][tx] = true;
            dist[ty][tx] = dist[ny][nx] + 1;
        }
    }
    return false; // lever를 못찾던가 ending을 못찾으면 -1을 출력하도록 false 리턴
}

int solution(vector<string> maps) {
    int answer = 0;
    
    h = maps.size();
    w = maps[0].length();
    map_copy = maps;
    
    
    for(int i =0; i< h; i++)
    {
        for(int j = 0; j< w; j ++)
        {
            if(maps[i][j] == 'S')
            {
                sx = j;
                sy = i;
            }
            else if(maps[i][j] == 'L')
            {
                lx = j;
                ly = i;
            }
            else if(maps[i][j] == 'E')
            {
                ex = j;
                ey = i;
            }
        }
    }   
    
    if(BFS(sx,sy, lx, ly)) // 스타팅 지점에서 레버까지 탐색
    {
        if(BFS(lx,ly, ex,ey)) // 레버에서 엔딩 지점까지 탐색
        {
            answer = dist[ey][ex];
        }
        else
        {
            answer = -1;
        }
    }
    else
    {
        answer = -1;
    }
        
        
  

    
    return answer;
}
