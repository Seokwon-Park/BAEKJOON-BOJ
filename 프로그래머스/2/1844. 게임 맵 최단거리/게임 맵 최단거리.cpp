#include <bits/stdc++.h>

using namespace std;

int dist[105][105];
bool visited[105][105];
vector<vector<int>> m;
int x, y;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int width;
int height;

void BFS()
{
    queue<pair<int,int>> q;  
    q.push({0,0});
    dist[0][0] = 1;
    visited[0][0] = true;
    while(!q.empty())
    {
        pair<int,int> pos = q.front();        
        q.pop();
        if(pos.first == width-1 && pos.second == height-1) break;
        for(int i =0; i< 4; i++)
        {
            int tx = pos.first + dx[i];
            int ty = pos.second + dy[i];
            if(tx < 0 || ty < 0 || tx >= width || ty >= height) continue;
            if(m[ty][tx] != 1 || visited[ty][tx]) continue;
            
            dist[ty][tx] = dist[pos.second][pos.first] +1;
            q.push({tx, ty});
            visited[ty][tx] = true;            
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
    m = maps;
    width = maps[0].size();
    height = maps.size();

    BFS();   
    if(dist[height-1][width-1] == 0) return -1;
    return dist[height-1][width-1];
}