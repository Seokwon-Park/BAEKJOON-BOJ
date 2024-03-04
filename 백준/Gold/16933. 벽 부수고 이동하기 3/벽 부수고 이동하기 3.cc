#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int board[1005][1005];
int crash[1005][1005]; // 이 좌표까지 오는데 몇개 부숨?
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int n, m, k;

int bfs()
{
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	crash[0][0] = 0;

	int dist = 1; // 처음칸도 포함
	bool isNight = false; // 낮과 밤일때 조건 처리용

	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)//dist = n(1,2,3...)일 때 push된 좌표씩만 탐색
			// n = 1  queue = {0, 0};
			// n = 2  queue = {1, 0}, {2,0};
			// ...
		{
			auto [x, y, c] = q.front();
			q.pop();
			if (y == n - 1 && x == m - 1)
			{
				return dist; //찾았으면 경로 반환
			}
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];

				//outofBound 검사
				if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
				if (crash[ty][tx] <= c) continue;

				if (!isNight) // 낮인 경우
				{
					if (board[ty][tx] == 0) // 다음칸이 벽이 아니면 그냥 이동한다.
					{
						crash[ty][tx] = c;
						q.push({ tx, ty , c});
					}
					else // 벽인 경우 + 다음 벽을 부수고 이동할 수 있는 경우에는 머물러서 다음 날을 기다린다.
					{
						if (k <= c) continue;
						crash[ty][tx] = c;
						q.push({ tx, ty, c+1 });
					}
				}
				else // 밤인 경우
				{
					if (board[ty][tx] == 0) // 다음칸이 벽이 아니면 그냥 이동한다.
					{
						crash[ty][tx] = c;
						q.push({ tx, ty, c });
					}
					else // 벽인 경우 + 다음 벽을 부수고 이동할 수 있는 경우에는 머물러서 다음 날을 기다린다.
					{
						// 부수고 이동할 수 있는 경우 머무른다.
						q.push({ x, y, c });
					}

				}
			}
		}
		isNight = !isNight; // 낮밤 바꾸기
 		dist++;// 이동한 거리 추가
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char input;
			cin >> input;
			board[i][j] = input-'0';
			crash[i][j] = INF;
		}
	}

	cout << bfs();

	return 0;
}