#include <bits/stdc++.h>

using namespace std;

bool visited[105][105];
int board[105][105];
int dmin[105][105];
int n, m;

// 0-1 bfs? 처음 써보는 알고리즘.
// https://nicotina04.tistory.com/168 참고함
// 1. 덱의 front에서 현재 노드를 꺼낸다.
// 2. 연결된 인접 노드를 살펴본다.
// 3. 현재 노드까지 소비된 비용 + 그 노드를 향하는 가중치 < 그 노드까지 가는데 소비된 비용이면 소비된 비용을 갱신해준다.
// 4. 노드가 갱신된 상태에서 만약 그 노드를 향하는 가중치가 0이면 덱의 front, 1이면 덱의 back에 삽입하도록 한다.
// 5. 덱에서 더 이상 꺼낼 노드가 없을 때까지 위 과정을 반복한다.
void bfs()
{
	deque<pair<int, int>> dq;
	dq.push_back({ 0,0 });
	visited[0][0] = true;
	dmin[0][0] = 0;
	while (!dq.empty())
	{
		auto [x, y] = dq.front(); // front에서 현재 노드를 꺼낸다.
		dq.pop_front();
		if (y == n - 1 && x == m - 1)
		{
			break;
		}
		for (int i = 0; i < 4; i++) // 인접 노드 살펴보기
		{
			int tx = x + ("0121"[i] - '1');
			int ty = y + ("1012"[i] - '1');
			if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
			if (dmin[y][x] + board[ty][tx] < dmin[ty][tx])
			{
				dmin[ty][tx] = dmin[y][x] + board[ty][tx];
				if (!board[ty][tx]) // 노드가 갱신된 상태에서 가중치가 0이면 front
					dq.push_front({ tx,ty });
				else
					dq.push_back({ tx,ty });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	
	for (int i = 0; i < n; i++)
	{
		fill(dmin[i], dmin[i] + m, 0x3f3f3f3f);
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			board[i][j] = c - '0';
		}
	}

	bfs();

	cout << dmin[n - 1][m - 1];

	return 0;
}