#include <bits/stdc++.h>

using namespace std;

vector<string> b_copy;
int rx, ry, gx, gy;
int w, h;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
bool visited[105][105];
int movd[105][105];

bool chk(int tx, int ty)
{
    if(tx <0 || ty <0 || tx >= w || ty >= h) return false;
    else if(b_copy[ty][tx] == 'D') return false;
    return true;
}

pair<int,int> FindEnd(int x, int y, int dir)
{
    while(chk(x, y))
    {
        x += dx[dir];
        y += dy[dir];
    }
    x -= dx[dir];
    y -= dy[dir];
    return {x, y};
}

void BFS(int x, int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[y][x] = true;
    while(!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;
        if(nx == gx && ny == gy)
        {
            break;
        }
        q.pop();
        for(int i = 0; i< 4; i++)
        {
            auto res = FindEnd(nx, ny, i);
            int tx = res.first;
            int ty = res.second;
            if(visited[ty][tx]) continue;
            q.push({tx,ty});
            visited[ty][tx] = true;
            movd[ty][tx] = movd[ny][nx]+1;
        }
    }
}

int solution(vector<string> board) {
    int answer = 0;
    
    b_copy = board;
    
    w = board[0].size();
    h = board.size();
    for(int i =0; i< h; i ++)
    {
        for(int j =0; j < w; j++)
        {
            if(board[i][j] == 'R')
            {
                rx = j;
                ry = i;
            }
            if(board[i][j] == 'G')
            {
                gx = j;
                gy = i;
            }
        }
    }
    
    BFS(rx, ry);
    

    
    if(movd[gy][gx] == 0)
    {
        return -1;
    }
    
    return movd[gy][gx];
}