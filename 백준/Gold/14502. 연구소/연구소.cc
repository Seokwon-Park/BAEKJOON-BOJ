#include <bits/stdc++.h>

using namespace std;

int n, m;
int max_val = INT_MIN;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
vector<pair<int, int>> vpos;

int board[10][10];
int visited[10][10];
int board_copy[10][10];

void bfs()
{
	queue<pair<int, int>> q;
	for (auto pos : vpos) // 바이러스 전파한 값으로 board_copy를 업데이트함.
	{
		q.push({ pos.first,pos.second });
		visited[pos.second][pos.first] = true;
	}

	while (!q.empty())
	{
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = nx + dx[i];
			int ty = ny + dy[i];
			if (tx < 0 || ty < 0 || tx >= m || ty >= n)continue;
			if (visited[ty][tx] || board_copy[ty][tx] != 0) continue;
			board_copy[ty][tx] = 2;
			visited[ty][tx] = true;
			q.push({ tx,ty });
			
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 2)
			{
				vpos.push_back({ j, i }); //바이러스 위치 저장
			}
		}
	}

	//가능한 벽에 대한 조합 찾기
	vector<int> ncr(n * m, 0);
	fill(ncr.end() - 3, ncr.end(), 1);
	do
	{
		for (int i = 0; i < n; i++)
		{
			fill(visited[i], visited[i] + m, false);
			for (int j = 0; j < m; j++)
			{
				board_copy[i][j] = board[i][j];
			}
		}

		bool isValid = true;
		for (int i = 0; i < n * m; i++)
		{
			if (ncr[i] == 1)
			{
				int nm = i;
				int x = nm % m;
				int y = nm / m;
				if (board[y][x] != 0)
				{
					isValid = false;
					break;
				}
				board_copy[y][x] = 1;
			}
		}

		if (!isValid) continue;

		bfs();

		// 전파된 환경에 대해 안전구역 넓이를 구함
		int safe_area = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (board_copy[i][j] == 0)
					safe_area++;
			}
		}
		// 현재 최대값보다 크다면 업데이트함.
		max_val = max(max_val, safe_area);

	} while (next_permutation(ncr.begin(), ncr.end()));

	cout << max_val;


	return 0;
}
