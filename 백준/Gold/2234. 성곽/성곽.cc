#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007;

int n, m;
int b[55][55];
int ar[55][55];
int bb[55][55];
bool v[55][55];
// 1111(2) = SENW;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int bfs(pii xy, int color)
{
	queue<pii> q;
	q.push(xy);
	vector<pii> sv;
	v[xy.second][xy.first] = 1;
	int area = 0;
	while (!q.empty())
	{
		auto [x, y] = q.front();
		sv.push_back(q.front());
		q.pop();
		bb[y][x] = color;
		area++;
		for (int i = 0; i < 4; i++)
		{
			if (((b[y][x] >> i) & 1) == 1)continue;
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
			if (v[ty][tx])continue;
			q.push({ tx,ty });
			v[ty][tx] = 1;
		}
	}

	for (auto [x, y] : sv)
	{
		ar[y][x] = area;
	}
	return area;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> b[i][j];
		}
	}

	int mx = 0;
	int rooms = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!v[i][j])
			{
				int res = bfs({ j, i }, rooms);
				mx = max(mx, res);
				rooms++;
			}
		}
	}

	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << bb[i][j] << ' ';
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	//for (int i = 0; i < m; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << ar[i][j] << ' ';
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";


	int mx2 = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				if (((b[i][j] >> k) & 1) == 0) continue;
				int tx = j + dx[k];
				int ty = i + dy[k];
				if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
				if (bb[i][j] == bb[ty][tx])continue;
				mx2 = max(mx2, ar[ty][tx] + ar[i][j]);
			}
		}
	}
	cout << rooms << '\n' << mx << '\n' << mx2;


	return 0;
}