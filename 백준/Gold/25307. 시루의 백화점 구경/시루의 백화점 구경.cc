#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const int MOD = 1'000'000'000;

int b[2005][2005];
bool v[2005][2005];
int n, m, k;
int mane[2005][2005];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void mbfs(queue<pii> q)
{
	int dist = 0;
	while (!q.empty())
	{
		if (dist == k) return;
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [cr, cc] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int tr = cr + dy[j];
				int tc = cc + dx[j];
				if (v[tr][tc] || tr < 0 || tc < 0 || tr >= n || tc >= m) continue;
				v[tr][tc] = true;
				mane[tr][tc] = 1;
				q.push({ tr,tc });
			}
		}
		dist++;
	}
}

int bfs(int r, int c)
{
	queue<pii> q;
	q.push({ r,c });
	int dist = 0;
	v[r][c] = true;
	while (!q.empty())
	{
		int qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			auto [cr, cc] = q.front();
			q.pop();
			for (int j = 0; j < 4; j++)
			{
				int tr = cr + dy[j];
				int tc = cc + dx[j];
				if (v[tr][tc] || tr < 0 || tc < 0 || tr >= n || tc >= m|| b[tr][tc] == 1 || mane[tr][tc] == 1) continue;
				if (b[tr][tc] == 2)
				{
					return dist+1;
				}
				v[tr][tc] = true;
				q.push({ tr,tc });
			}
		}
		dist++;
	}
	return -1;
}

void resetv()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			v[i][j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;
	int r, c;
	queue<pii> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
			if (b[i][j] == 3)
			{
				mane[i][j] = 1;
				q.push({ i,j });
			}
			if (b[i][j] == 4)
			{
				r = i;
				c = j;
			}
		}
	}
	mbfs(q);
	resetv();
	cout << bfs(r, c);


	return 0;
}