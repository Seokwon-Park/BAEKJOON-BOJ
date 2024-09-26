#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;

int b[5][5];
int v[5][5];
pii pos[7];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int r, c;

void resetv()
{
	for (int i = 0; i < 5; i++)
	{
		fill(v[i], v[i] + 5, false);
	}
}

pii RunResult(int x, int y, int dir)
{
	int tx = x;
	int ty = y;
	while (1)
	{
		tx += dx[dir];
		ty += dy[dir];
		if (b[ty][tx] == 7) // 뛰어가는 중에 7을 만나면 멈춤
		{
			return { tx, ty };
		}
		if (tx < 0 || ty < 0 || tx >= 5 || ty >= 5 || b[ty][tx] == -1) // 맵 경계 또는 -1 앞에서 멈춤.
		{
			return { tx - dx[dir], ty - dy[dir] };
		}
	}
}

int bfs(int sx, int sy, int findNum)
{
	resetv();
	queue<pii> q;
	q.push({ sx,sy });
	int moved = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y] = q.front();
			q.pop();
			if (b[y][x] == findNum)
			{
				return moved;
			}
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= 5 || ty >= 5) continue;
				if (b[ty][tx] == -1 || v[ty][tx]) continue;
				v[ty][tx] = true;
				q.push({ tx,ty });
			}
			for (int j = 0; j < 4; j++)
			{
				auto [tx, ty] = RunResult(x, y, j);
				if (v[ty][tx]) continue;
				v[ty][tx] = true;
				q.push({ tx,ty });
			}
		}
		moved++;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> b[i][j];
			pos[b[i][j]] = make_pair(j, i);
		}
	}
	cin >> r >> c;

	vector<int> brute = { 1,2,3,4,5,6 };

	int ans = INF;
	do
	{
		int res = 0;
		int sx = c;
		int sy = r;
		bool canGo = true;
		for (int i = 0; i < brute.size(); i++)
		{
			int tmp = bfs(sx, sy, brute[i]);
			if (tmp == -1)
			{
				canGo = false;
				break;
			}
			res += tmp;
			sx = pos[brute[i]].first;
			sy = pos[brute[i]].second;
		}
		if (canGo)
		{
			ans = min(ans, res);
		}
	} while (next_permutation(brute.begin(), brute.end()));

	if (ans != INF)
		cout << ans;
	else
		cout << -1;

	return 0;
}

