#include <bits/stdc++.h>

using namespace std;

int w, h; //width, height
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };


char board[1005][1005];
bool visited[1005][1005][2]; // 0은 한번도 안부숨, 1은 이제 1번 부숨.
int dist[1005][1005];

bool bfs()
{
	queue<vector<int>> q; // tx, ty, 남은 crash 횟수.
	q.push({ 0, 0, 0 });
	visited[0][0][0] = true; 
	dist[0][0] = 1;

	while (!q.empty())
	{
		int nx = q.front()[0];
		int ny = q.front()[1];
		int crash = q.front()[2];
		if (nx == w - 1 && ny == h - 1)
		{
			cout << dist[ny][nx]; // 찾았으면 return 바로 
			return true;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			// target x, y;
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			
			if (tx < 0 || ty < 0 || tx >= w || ty >= h) continue;
			if (crash == 1 && board[ty][tx] == '1') continue;
			if (visited[ty][tx][crash]) continue;
			if (board[ty][tx] == '1' && crash == 0) // 벽이고 한번도 안부쉈으면
			{
				visited[ny][nx][crash + 1] = true; // 다음위치는 부수고 방문했다고 표시.
				dist[ty][tx] = dist[ny][nx] + 1;
				q.push({ tx, ty, crash + 1 });
			}
			if (board[ty][tx] == '0') // 벽이 아니면
			{
				visited[ty][tx][crash] = true; // 남은 부순 횟수와 방문 표시 부쉈으면 1에 visited가 될것이고 아니면 0에 visited가 될것
				dist[ty][tx] = dist[ny][nx] + 1;
				q.push({ tx,ty, crash });
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char input;

	cin >> h >> w;

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			cin >> board[y][x];
		}
	}

	if (!bfs())
	{
		cout << -1;
	}
	
	/*cout << '\n';
	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			cout << dist[y][x] << ' ';
		}
		cout << '\n';
	}*/

	return 0;
}