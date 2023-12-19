#include <bits/stdc++.h>

using namespace std;

int RGB[105][105];
int RB[105][105];
bool visited[105][105];
int n;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void BFS(int x, int y, int rgb, bool isRB)
{
    queue<pair<int, int>> q;

    q.push({x, y});
    visited[y][x] = true;
    while (!q.empty())
    {
        auto pos = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = pos.first + dx[i];
            int ty = pos.second + dy[i];
            if (tx < 0 || ty < 0 || tx >= n || ty >= n) continue;
            if (!isRB)
            {
                if (visited[ty][tx] || RGB[ty][tx] != rgb) continue;
            }
            else
            {
                if (visited[ty][tx] || RB[ty][tx] != rgb) continue;
            }
            q.push({ tx,ty });
            visited[ty][tx] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    
    int rgb_count = 0;
    int rb_count = 0;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            if (str[j] == 'R')
            {
                RGB[i][j] = 1;
                RB[i][j] = 1;
            }
            if (str[j] == 'G')
            {
                RGB[i][j] = 2;
                RB[i][j] = 1;
            }
            if (str[j] == 'B')
            {
                RGB[i][j] = 3;
                RB[i][j] = 3;
            }
        }
    }


    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == false)
            {
                BFS(j, i, RGB[i][j], false);
                rgb_count++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        fill(visited[i], visited[i] + n, false);
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == false)
            {
                BFS(j, i, RB[i][j], true);
                rb_count++;
            }
        }
    }

    cout << rgb_count << ' ' << rb_count;

    return 0;
}