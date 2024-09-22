#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1'000'000'007;

int n, m, fuel;
int b[25][25];
int s[25][25];
int v[25][25];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int cx, cy;
pii st[405];



void resetv()
{
	for (int i = 0; i < n; i++)
	{
		fill(v[i], v[i] + n, false);
	}
}

int FindClosestStart(int xx, int yy)
{
	resetv();
	queue<pii> q;
	q.push({ xx,yy });
	v[yy][xx] = true;
	int dist = 0;
	vector<int> passengers;
	bool isFind = false;
	int	fx = INF;
	int fy = INF;
	int ret = -1;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y] = q.front();
			q.pop();
			if (s[y][x] != 0)
			{
				isFind = true;
				if (dist > fuel) // 가장 짧은 출발점을 발견했는데 기름이 부족해? 리턴.
				{
					return -1;
				}
				// 기름은 충분한 경우.
				if (fy == y) // 행이 같으면
				{
					if (x < fx)
					{
						fx = x;
						fy = y;
						ret = s[y][x];
					}
				}
				else
				{
					if (y < fy)
					{
						fx = x;
						fy = y;
						ret = s[y][x];
					}
				}
			}
			if (isFind) continue;
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
				if (b[ty][tx] == 1 || v[ty][tx]) continue;
				q.push({ tx,ty });
				v[ty][tx] = true;
			}
		}
		if (isFind)
		{
			cx = fx;
			cy = fy;
			fuel -= dist;
			s[fy][fx] = 0;
			return ret;
		}
		dist++;
	}
	return -1;
}

bool CanMoveToTarget(int xx, int yy, pii target)
{
	resetv();
	queue<pii> q;
	q.push({ xx,yy });
	auto [targetx, targety] = target;
	v[yy][xx] = true;
	int dist = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [x, y] = q.front();
			q.pop();
			if (x == targetx && y == targety)
			{
				if (dist > fuel)
				{
					return false;
				}
				else
				{
					cx = x;
					cy = y;
					fuel += dist;
					return true;
				}
			}
			for (int j = 0; j < 4; j++)
			{
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= n || ty >= n)continue;
				if (b[ty][tx] == 1 || v[ty][tx]) continue;
				q.push({ tx,ty });
				v[ty][tx] = true;
			}
		}
		dist++;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> fuel;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	cin >> cy >> cx;
	cx--;
	cy--;
	vector<pii> en(m + 1);
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		s[a - 1][b - 1] = i;
		en[i] = { d - 1,c - 1 };
	}

	for (int i = 0; i < m; i++)
	{
		int res = FindClosestStart(cx, cy);
		if (res == -1)
		{
			cout << -1;
			return 0;
		}
		else
		{
			if (!CanMoveToTarget(cx, cy, en[res]))
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << fuel;

	return 0;
}