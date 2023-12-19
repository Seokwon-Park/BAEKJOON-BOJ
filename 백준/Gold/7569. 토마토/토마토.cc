#include <bits/stdc++.h>

using namespace std;

int dx[6] = { -1, 0, 0, 1, 0, 0 };
int dy[6] = { 0, -1, 0, 0, 1, 0 };
int dz[6] = { 0, 0, -1, 0, 0, 1 };

int board[105][105][105];
bool visited[105][105][105];

int m, n, h; // x, y, z
int max_time = 0;

queue<vector<int>> q;

void BFS()
{
    while(!q.empty())
    {
        int posX = q.front()[0];
        int posY = q.front()[1];
        int posZ = q.front()[2];
        int time = q.front()[3];
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int tx = posX + dx[i];
            int ty = posY + dy[i];
            int tz = posZ + dz[i];
            if (tx < 0 || ty < 0 || tz < 0 || tx >= m || ty >= n || tz >= h) continue;
            if (visited[tz][ty][tx] || board[tz][ty][tx] == 1) continue;
            q.push({tx, ty, tz, time+1});
            if (max_time < time + 1) max_time = time + 1;
            visited[tz][ty][tx] = true;
        }


    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n >> h;

    vector<vector<int>> st_pt;

    for (int z = 0; z < h; z++)
        for (int y = 0; y < n; y++)
            for (int x = 0; x < m; x++)
            {
                cin >> board[z][y][x];
                if (board[z][y][x] == 1)
                {
                    q.push({ x, y, z, 0 });// q에 스타팅 포인트와 경과 시간을 저장
                    visited[z][y][x] = true;
                }
                if (board[z][y][x] == -1)
                {
                    visited[z][y][x] = true;
                }
            }
    BFS(); // call BFS

    for (int z = 0; z < h; z++)
        for (int y = 0; y < n; y++)
            for (int x = 0; x < m; x++)
            {
                if (visited[z][y][x] == false)
                {
                    cout << -1;
                    return 0;
                }
            }

    cout << max_time;

    return 0;
}