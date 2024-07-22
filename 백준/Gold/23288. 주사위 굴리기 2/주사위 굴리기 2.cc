#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int b[20][20];
bool v[20][20];
int dice[6] = { 1,2,3,4,5,6 }; // 위 북 동 서 남 아래
int n, m, k;

// 서, 북, 동, 남 순서대로.
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void rollDice(int dir)
{
	int tmp = dice[0];
	if (dir == 0)
	{
		dice[0] = dice[2];
		dice[2] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
	}
	else if (dir == 1)
	{
		dice[0] = dice[4];
		dice[4] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
	}
	else if (dir == 2)
	{
		dice[0] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[2];
		dice[2] = tmp;
	}
	else
	{
		dice[0] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[4];
		dice[4] = tmp;
	}
}

void resetv()
{
	for (int i = 0; i < n; i++)
	{
		fill(v[i], v[i] + m, false);
	}
}

int bfs(int nx, int ny)
{
	queue<pii> q;
	q.push({ nx,ny });
	v[ny][nx] = 1;
	int color = b[ny][nx];
	int area = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		area++;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= m || ty >= n) continue;
			if (b[ty][tx] != color || v[ty][tx]) continue;
			q.push({ tx,ty });
			v[ty][tx] = 1;
		}
	}
	return area;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	int dir = 2;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	int cx = 0;
	int cy = 0;
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		int tx = cx + dx[dir];
		int ty = cy + dy[dir];
		if (tx < 0 || ty < 0 || tx >= m || ty >= n)
		{
			dir = (dir + 2) % 4;
			tx = cx + dx[dir];
			ty = cy + dy[dir];
		}
		rollDice(dir);
		resetv();
		ans += bfs(tx, ty) * b[ty][tx];

		int A = dice[5];
		int B = b[ty][tx];
		if (A > B)
			dir = (dir + 1) % 4;
		else if (A < B)
			dir = (dir + 3) % 4;
		cx = tx;
		cy = ty;
	}
	cout << ans;

	return 0;
}