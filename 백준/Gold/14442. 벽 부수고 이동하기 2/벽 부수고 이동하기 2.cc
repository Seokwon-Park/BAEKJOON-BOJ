
#include <bits/stdc++.h>

using namespace std;

// 내꺼 아님. 시간복잡도를 위해 다른 소스코드를 참고함
// 어케생각했을까.
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

#define INF 0x3f3f3f3f

int n, m, k;
int board[1005][1005];
int visited[1005][1005];
int c[1005][1005];

int bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y});
	c[y][x] = 0; // 이건 0,0에 벽을 0개 부순상태라는뜻.

	int answer = INF;
	int dist = 1;
	while (!q.empty())
	{
		int qs = q.size();
		for (int l = 0; l < qs; l++) 
		// 이 for 문이 필요한 이유는 같은 움직인 거리를 가지는 점들에 대해서 진행하기 위해서?인듯
		// Queue((0,0)):dist = 1 -> Queue((1,0) (0,1)):dist = 2 -> 
		{
			auto [nx, ny] = q.front();
			q.pop();
			if (ny == n - 1 && nx == m - 1)
			{
				return answer <= dist? answer : dist;
			}
			for (int i = 0; i < 4; i++)
			{
				int tx = nx + dx[i];
				int ty = ny + dy[i];

				int crash = c[ny][nx] + board[ty][tx]; // 다음 위치에 가기 위해서 벽을 몇개 부쉈나?
				if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
				if (c[ty][tx] <= crash || k < crash) continue;
				// 1. 다음위치에 도달하려고 부순 수 <= 다음 위치에 도달하기 까지 부술 것으로 예상되는 값
				// 당연히 이전에 지나온 길은 c[ty][tx]가 crash보다 작을 것이기 때문에 무한루프가 일어나지 않는다.
				// 그러니까 만약 이미 현재 경로에서 부순것보다 덜 부쉈거나 같은 개수의 벽을 부쉈으면 이 루트는 최선이 아니다?
				// 2. 부순횟수가 k보다 크면 진행하면 안됨
				c[ty][tx] = crash;
				q.push({ tx,ty });
			}
		}
		dist++; // 처음 qsize에 대해서 다 돌았으면 다음거리로 넘어가도 된다.
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char input;
			cin >> input;
			board[i][j] = input - '0';
			c[i][j] = INF;
		}
	}

	int answer = bfs(0, 0);
	if (answer == INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}