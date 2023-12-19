#include <bits/stdc++.h>

using namespace std;

int board[105][105];
bool visited[105][105];
int m, n, k;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int BFS(int x, int y)
{
    queue<pair<int, int>> q;

    q.push({x, y});
    visited[y][x] = true;
    int area = 0;
    while (!q.empty())
    {
        auto pos = q.front();
        area++;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = pos.first + dx[i];
            int ty = pos.second + dy[i];
            if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
            if (visited[ty][tx]) continue;
            q.push({ tx,ty });
            visited[ty][tx] = true;
        }
    }
    return area;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n >> k;

    int cnt = 0;
    vector<int> areas;
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        y1 = m - y1;
        y2 = m - y2;
        int width = x2 - x1;
        int height = y1 - y2;

        for (int y = y2; y < y1; y++)
        {
            for (int x = x1; x < x2; x++)
            {
                visited[y][x] = true;
                board[y][x] = 1;
            }
        }
        
    }

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {            
            //cout << board[y][x];
            if (visited[y][x] == false)
            {
                areas.push_back(BFS(x, y));
                cnt++;
            }
        }
    }

    sort(areas.begin(), areas.end());

    cout << cnt << '\n';
    for (auto a : areas)
    {
        cout << a << ' ';
    }


    return 0;
}